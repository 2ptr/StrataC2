#include <QApplication>
#include "../windows/teamserverwindow.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    TeamserverWindow window;
    return QApplication::exec();
}