//
// Created by jake.otte on 5/21/2025.
//

#ifndef PAYLOADSDIALOG_H
#define PAYLOADSDIALOG_H

#include <QDialog>

class Listener;
class TeamserverWindow;  // Forward declaration
QT_BEGIN_NAMESPACE
namespace Ui { class PayloadsDialog; }
QT_END_NAMESPACE

class PayloadsDialog : public QDialog {
Q_OBJECT

public:
    Ui::PayloadsDialog *ui;
    TeamserverWindow *main_window;

    void populate_fields();
    void prepare_http(Listener listener);

    bool compile_payload(QString sourcedir, QStringList args);

explicit PayloadsDialog(QWidget *parent = nullptr, TeamserverWindow *main_window = nullptr);
    ~PayloadsDialog() override;
private slots:

    void on_cmakeButton_clicked();
    void on_buttonBox_accepted();

};


#endif //PAYLOADSDIALOG_H
