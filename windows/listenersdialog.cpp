//
// Created by jake.otte on 5/5/2025.
//

// You may need to build the project (run Qt uic code generator) to get "ui_ListenersDialog.h" resolved

#include "listenersdialog.h"
#include "teamserverwindow.h"
#include "ui_ListenersDialog.h"
#include <QMessageBox>
#include <ui_TeamserverWindow.h>
#if defined(_WIN32)
    #include <winsock2.h>
    #include <iphlpapi.h>
    #include <ws2tcpip.h>
    #pragma comment(lib, "iphlpapi.lib")
    #pragma comment(lib, "ws2_32.lib")
#else
    #include <ifaddrs.h>
    #include <netinet/in.h>
    #include <arpa/inet.h>
    #include <cstring>
#endif

ListenersDialog::ListenersDialog(QWidget *parent, TeamserverWindow *main_window) :
    QDialog(parent),
    ui(new Ui::ListenersDialog),
    main_window(main_window)
    {
    ui->setupUi(this);

    // Populate fields
    this->populate_fields();
}

void ListenersDialog::populate_fields() {
    ui->bindInterfaceBox->clear();
    ui->bindInterfaceBox->addItem("0.0.0.0");
    std::vector<std::string> ipList;
    // TODO: Clean this section ; test Linux
    // Get interfaces - WINDOWS
    #if defined(_WIN32)
        WSADATA wsaData;
        WSAStartup(MAKEWORD(2, 2), &wsaData);

        ULONG bufferSize = 15000;
        IP_ADAPTER_ADDRESSES *adapters = (IP_ADAPTER_ADDRESSES *)malloc(bufferSize);

        if (GetAdaptersAddresses(AF_INET, 0, NULL, adapters, &bufferSize) == NO_ERROR) {
            for (IP_ADAPTER_ADDRESSES *adapter = adapters; adapter != NULL; adapter = adapter->Next) {
                for (IP_ADAPTER_UNICAST_ADDRESS *unicast = adapter->FirstUnicastAddress; unicast != NULL; unicast = unicast->Next) {
                    sockaddr_in *sa_in = (sockaddr_in *)unicast->Address.lpSockaddr;
                    char ipStr[INET_ADDRSTRLEN];
                    inet_ntop(AF_INET, &sa_in->sin_addr, ipStr, sizeof(ipStr));
                    std::string ip(ipStr);
                    if (ip.rfind("169.254.", 0) != 0 && ip != "127.0.0.1") {
                        ipList.push_back(ip);
                    }
                }
            }
        }

        free(adapters);
        WSACleanup();

    // Get interfaces - LINUX
    #else
        struct ifaddrs *ifaddr, *ifa;
        char ip[INET_ADDRSTRLEN];

        if (getifaddrs(&ifaddr) == -1) {
            perror("getifaddrs");
            return ipList;
        }

        for (ifa = ifaddr; ifa != nullptr; ifa = ifa->ifa_next) {
            if (!ifa->ifa_addr || ifa->ifa_addr->sa_family != AF_INET) continue;

            struct sockaddr_in *sa = (struct sockaddr_in *)ifa->ifa_addr;
            inet_ntop(AF_INET, &(sa->sin_addr), ip, INET_ADDRSTRLEN);
            std::string ipStr(ip);

            if (ipStr.rfind("169.254.", 0) != 0 && ipStr != "127.0.0.1") {
                ipList.emplace_back(ipStr);
            }
        }

        freeifaddrs(ifaddr);
    #endif
    for (std::string ip : ipList) {
        ui->bindInterfaceBox->addItem(ip.c_str());
    }
}

void ListenersDialog::on_buttonBox_accepted() {
    Listener potential_listener =
        Listener(ui->listenerNameBox->text().toStdString(),
            ui->bindInterfaceBox->currentText().toStdString(),
            ui->bindPortBox->value()
            );
    if (potential_listener.tryStartListener()) {
        main_window->g_Listeners.push_back(potential_listener);
    }else {
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
