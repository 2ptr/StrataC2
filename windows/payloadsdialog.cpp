//
// Created by jake.otte on 5/21/2025.
//

// You may need to build the project (run Qt uic code generator) to get "ui_payloadsdialog.h" resolved

#include "payloadsdialog.h"

#include <fstream>
#include <QSettings>
#include <QMessageBox>
#include <QFileDialog>
#include <QProcess>
#include <QString>
#include "ui_PayloadsDialog.h"
#include "teamserverwindow.h"


std::string replaceAll(std::string str, const std::string& from, const std::string& to) {
    size_t start_pos = 0;
    while((start_pos = str.find(from, start_pos)) != std::string::npos) {
        str.replace(start_pos, from.length(), to);
        start_pos += to.length();
    }
    return str;
}

PayloadsDialog::PayloadsDialog(QWidget *parent, TeamserverWindow *main_window) :
    QDialog(parent),
    ui(new Ui::PayloadsDialog),
    main_window(main_window)
    {
        ui->setupUi(this);

    // Populate fields
    this->populate_fields();
}

void PayloadsDialog::populate_fields() {
    ui->fileFormatBox->clear();
    ui->listenerBox->clear();
    ui->outputTextEdit->clear();

    // Load listeners
    for (Listener& listener : main_window->g_Listeners) {
        ui->listenerBox->addItem(QString::fromStdString(listener.name));
    }

    // Load filetypes
    ui->fileFormatBox->addItem("Windows exe");
    ui->fileFormatBox->addItem("Windows dll");

    // Load cmake path
    QSettings settings;
    QString cmakePath = settings.value("cmakePath", "").toString();
    ui->cmakeLineEdit->setText(cmakePath);
}

void PayloadsDialog::on_cmakeButton_clicked() {
    QString cmakePath = QFileDialog::getOpenFileName(this, "Select CMake Executable", "C:/", "CMake (cmake.exe)");
    ui->cmakeLineEdit->setText(cmakePath);
}

void PayloadsDialog::on_buttonBox_accepted() {
    // Check valid
    if (ui->listenerBox->currentText().isEmpty() || ui->fileFormatBox->currentText().isEmpty()){
        return;
    }

    // Save the new cmake path if we can
    QString cmakePath = ui->cmakeLineEdit->text();
    if (!cmakePath.isEmpty()) {
        QSettings settings;
        settings.setValue("cmakePath", cmakePath);
    }

    // Get the listener instance
    auto it = std::ranges::find_if(main_window->g_Listeners, [&] (Listener& l)
        { return l.name == ui->listenerBox->currentText().toStdString(); });
    if (it == main_window->g_Listeners.end()) {
        this->close();
    }
    Listener& listener = *it;

    // Check what agent we need to prepare
    if (listener.type == HTTP) {
        prepare_http(listener);
    }

    this->close();
}

void PayloadsDialog::prepare_http(Listener listener) {
    // Update sleep and callbacks
    std::ifstream template_file("../agents/http/conf/Config.template");
    std::stringstream buffer;
    buffer << template_file.rdbuf();
    std::string file_contents = buffer.str();

    // Make callbacks string
    std::string callbacks_map = "{\n";
    for (const auto& [host, port] : listener.callbacks) {
        std::string host_str(host.begin(), host.end());
        callbacks_map += "    {L\"" + host_str + "\", " + std::to_string(port) + "},\n";
    }
    callbacks_map += "}";

    // Replace placeholders
    file_contents = replaceAll(file_contents, "@SLEEP_VALUE@", std::to_string(ui->sleepBox->value()*1000));
    file_contents = replaceAll(file_contents, "@CALLBACKS_MAP@", callbacks_map);

    // Write new config
    std::ofstream output_file("../agents/http/conf/Config.cpp");
    output_file << file_contents;

    // Compile
    QString sourceDir = "../agents/http";
    QStringList args = {
        "--build", "./build",
        "--target", "strata-exe",
        "-j", "10"
    };
    if (compile_payload(sourceDir, args)) {
        QString destinationPath = QFileDialog::getSaveFileName(nullptr, "Save Executable", "strata.exe");
        QString builtExecutablePath = "../agents/http/build/strata-exe.exe";
        if (QFile::exists(destinationPath)) {
            QFile::remove(destinationPath);
        }
        if (!QFile::copy(builtExecutablePath, destinationPath)) {
            QMessageBox::warning(nullptr, "Copy Failed", "Failed to copy file to destination.");
        } else {
            QMessageBox::information(nullptr, "Success", "Executable saved successfully.");
        }
    } else {
        QMessageBox::warning(nullptr, "Build Failed", "Failed to build executable.");
    }
}

bool PayloadsDialog::compile_payload(QString sourcedir, QStringList args) {
    // Setup
    QString cmake_path = ui->cmakeLineEdit->text();
    QProcess *process = new QProcess(this);
    process->setProgram(cmake_path);
    process->setWorkingDirectory(sourcedir);

    // Setup signals
    connect(process, &QProcess::readyReadStandardOutput, [=]() {
        QString output = process->readAllStandardOutput();
        ui->outputTextEdit->append(output);
    });
    connect(process, &QProcess::readyReadStandardError, [=]() {
        QString output = process->readAllStandardError();
        ui->outputTextEdit->append("[stderr] " + output);
    });

    ui->outputTextEdit->append("Starting build...");

    // Configure
    process->setArguments(QStringList() << "-S" << "." << "-B" << "./build" << "-G" << "MinGW Makefiles");
    process->start();
    process->waitForFinished();

    // Compile
    process->setArguments(args);
    process->start();
    process->waitForFinished();

    if (process->exitCode() == 0) {
        return true;
    }
    return false;
}

PayloadsDialog::~PayloadsDialog() {
    delete ui;
}
