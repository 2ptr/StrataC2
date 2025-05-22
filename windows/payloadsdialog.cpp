//
// Created by jake.otte on 5/21/2025.
//

// You may need to build the project (run Qt uic code generator) to get "ui_payloadsdialog.h" resolved

#include "payloadsdialog.h"

#include <fstream>
#include "../classes/Constants.h"
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

    // Load listeners
    for (Listener& listener : main_window->g_Listeners) {
        ui->listenerBox->addItem(QString::fromStdString(listener.name));
    }

    // Load filetypes
    ui->fileFormatBox->addItem(EXE_FILETYPE.data());
    ui->fileFormatBox->addItem(DLL_FILETYPE.data());
}

void PayloadsDialog::on_buttonBox_accepted() {
    // Check valid
    if (ui->listenerBox->currentText().isEmpty() || ui->fileFormatBox->currentText().isEmpty()){
        return;
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

    // this->close();
}

void PayloadsDialog::prepare_http(Listener listener) {
    // Update sleep and callbacks
    std::ifstream template_file(HTTP_TEMPLATE_FILEPATH);
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
    file_contents = replaceAll(file_contents, SLEEP_TEMPLATE_MARKER, std::to_string(ui->sleepBox->value()*1000));
    file_contents = replaceAll(file_contents, CALLBACKS_TEMPLATE_MARKER, callbacks_map);

    // Write new config
    std::ofstream output_file(HTTP_CONFIG_FILEPATH);
    output_file << file_contents;
    output_file.close();

    // Compile and copy
    if (compile_payload(HTTP_SRC_DIR.data())) {
        QString destinationPath = QFileDialog::getSaveFileName(nullptr, "Save Executable", "strata.exe");
        QString builtExecutablePath = "../agents/http/strata-exe.exe";
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

bool PayloadsDialog::compile_payload(QString sourcedir) {
    QProcess *process = new QProcess(this);
    process->setWorkingDirectory(sourcedir);
    process->setProgram("cmd");
    process->setArguments({"/c", "compile.bat"});
    process->start();
    process->waitForFinished();
    if (process->exitCode() == 0) {
        delete process;
        return true;
    }
    delete process;
    return false;
}

PayloadsDialog::~PayloadsDialog() {
    delete ui;
}
