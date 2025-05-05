//
// Created by jake.otte on 5/5/2025.
//

#ifndef LISTENERSDIALOG_H
#define LISTENERSDIALOG_H

#include <QDialog>

class TeamserverWindow;  // Forward declaration
QT_BEGIN_NAMESPACE
namespace Ui { class ListenersDialog; }
QT_END_NAMESPACE

class ListenersDialog : public QDialog {
Q_OBJECT

public:
    TeamserverWindow *main_window;

    void populate_fields();

    explicit ListenersDialog(QWidget *parent = nullptr, TeamserverWindow *main_window = nullptr);
    ~ListenersDialog() override;

private slots:
    void on_buttonBox_accepted();
    void on_buttonBox_rejected();

private:
    Ui::ListenersDialog *ui;
};


#endif //LISTENERSDIALOG_H
