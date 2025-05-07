#include "listenersdialog.h"
#include "teamserverwindow.h"
#include "ui_ListenersDialog.h"
#include "ui_TeamserverWindow.h"
#include <QMessageBox>

// Windows networking includes
#include <winsock2.h>
#include <iphlpapi.h>
#include <ws2tcpip.h>

#pragma comment(lib, "iphlpapi.lib")
#pragma comment(lib, "ws2_32.lib")

ListenersDialog::ListenersDialog(QWidget *parent, TeamserverWindow *main_window) :
    QDialog(parent),
    ui(new Ui::ListenersDialog),
    main_window(main_window)
    {
    ui->setupUi(this);

    // Populate fields
    this->populate_fields();
}

static bool isValidIpAddress(const std::string &ip) {
    return ip.rfind("169.254.", 0) != 0 && ip != "127.0.0.1";
}

void ListenersDialog::populate_fields() {
    ui->bindInterfaceBox->clear();
    ui->bindInterfaceBox->addItem("0.0.0.0");
    std::vector<std::string> ipList;

    // Initialize Windows Sockets
    WSADATA wsaData;
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        return;
    }

    // Get network adapters
    ULONG bufferSize = 15000;
    IP_ADAPTER_ADDRESSES *adapters = static_cast<IP_ADAPTER_ADDRESSES *>(malloc(bufferSize));
    if (!adapters) {
        WSACleanup();
        return;
    }

    if (GetAdaptersAddresses(AF_INET, 0, NULL, adapters, &bufferSize) == NO_ERROR) {
        for (IP_ADAPTER_ADDRESSES *adapter = adapters; adapter != NULL; adapter = adapter->Next) {
            for (IP_ADAPTER_UNICAST_ADDRESS *unicast = adapter->FirstUnicastAddress;
                 unicast != NULL;
                 unicast = unicast->Next) {
                sockaddr_in *sa_in = reinterpret_cast<sockaddr_in *>(unicast->Address.lpSockaddr);
                char ipStr[INET_ADDRSTRLEN];
                inet_ntop(AF_INET, &sa_in->sin_addr, ipStr, sizeof(ipStr));

                std::string ip(ipStr);
                if (isValidIpAddress(ip)) {
                    ipList.push_back(ip);
                }
            }
        }
    }

    free(adapters);
    WSACleanup();

    for (const std::string &ip: ipList) {
        ui->bindInterfaceBox->addItem(ip.c_str());
    }
}

void ListenersDialog::on_buttonBox_accepted() {
    Listener potential_listener(
        ui->listenerNameBox->text().toStdString(),
        ui->bindInterfaceBox->currentText().toStdString(),
        ui->bindPortBox->value()
    );
    if (potential_listener.tryHttpStartListener()) {
        main_window->g_Listeners.push_back(potential_listener);
        main_window->log_activity(
            "Started listener: " + ui->listenerNameBox->text().toStdString() +
            ", bound to " + ui->bindInterfaceBox->currentText().toStdString() +
            ":" + std::to_string(ui->bindPortBox->value())
        );
    } else {
        QMessageBox::critical(this, "Error", "Failed to start listener. Check bind address and port.");
    }

    main_window->ui->listenersTable->repopulateItems();
    this->close();
}

void ListenersDialog::on_buttonBox_rejected() {
    this->close();
}

ListenersDialog::~ListenersDialog() {
    delete ui;
}
