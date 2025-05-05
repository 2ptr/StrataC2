/********************************************************************************
** Form generated from reading UI file 'listenersdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LISTENERSDIALOG_H
#define UI_LISTENERSDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ListenersDialog
{
public:
    QGridLayout *gridLayout;
    QLabel *label;
    QTabWidget *tabWidget;
    QWidget *tab;
    QFormLayout *formLayout;
    QLabel *label_5;
    QLineEdit *listenerNameBox;
    QLabel *label_2;
    QComboBox *bindInterfaceBox;
    QLabel *label_3;
    QSpinBox *bindPortBox;
    QLabel *label_6;
    QSpinBox *agentPortBox;
    QLabel *label_4;
    QTextEdit *agentCallbacksBox;
    QWidget *tab_2;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *ListenersDialog)
    {
        if (ListenersDialog->objectName().isEmpty())
            ListenersDialog->setObjectName("ListenersDialog");
        ListenersDialog->resize(381, 533);
        ListenersDialog->setStyleSheet(QString::fromUtf8("/* GLOBAL FONT & BACKGROUND */\n"
"QWidget {\n"
"    background-color: #0D1117;\n"
"    color: #E6F1FF;\n"
"    font-family: 'Fira Code', 'Consolas', 'Courier New', monospace;\n"
"    font-size: 11pt;\n"
"    border: none;\n"
"}\n"
"\n"
"/* INPUT FIELDS */\n"
"QLineEdit, QTextEdit, QPlainTextEdit, QSpinBox {\n"
"    background-color: #161B22;\n"
"    border: 1px solid #4C8EDA;\n"
"    border-radius: 6px;\n"
"    padding: 8px;\n"
"    color: #E6F1FF;\n"
"    font-size: 11.5pt;\n"
"}\n"
"\n"
"QLineEdit:focus, QTextEdit:focus, QPlainTextEdit:focus, QSpinBox:focus {\n"
"    border: 1px solid #58A6FF;\n"
"    background-color: #1B2330;\n"
"}\n"
"\n"
"/* QSPINBOX ARROWS */\n"
"QSpinBox::up-button, QSpinBox::down-button {\n"
"    background-color: #21262D;\n"
"    subcontrol-origin: border;\n"
"    border: 1px solid #4C8EDA;\n"
"    width: 16px;\n"
"    border-radius: 3px;\n"
"}\n"
"\n"
"QSpinBox::up-button:hover, QSpinBox::down-button:hover {\n"
"    background-color: #2C313C;\n"
"    border-color: #58A6FF;\n"
"}\n"
""
                        "\n"
"QSpinBox::up-arrow, QSpinBox::down-arrow {\n"
"    image: none;\n"
"    width: 0;\n"
"    height: 0;\n"
"    border-left: 5px solid transparent;\n"
"    border-right: 5px solid transparent;\n"
"}\n"
"\n"
"QSpinBox::up-arrow {\n"
"    border-bottom: 6px solid #E6F1FF;\n"
"    margin: 2px;\n"
"}\n"
"\n"
"QSpinBox::down-arrow {\n"
"    border-top: 6px solid #E6F1FF;\n"
"    margin: 2px;\n"
"}\n"
"\n"
"/* BUTTONS */\n"
"QPushButton {\n"
"    background-color: #21262D;\n"
"    color: #E6F1FF;\n"
"    border: 1px solid #4C8EDA;\n"
"    border-radius: 6px;\n"
"    padding: 6px 12px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #2C313C;\n"
"    border-color: #58A6FF;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #3B4452;\n"
"}\n"
"\n"
"/* TABLES */\n"
"QTableWidget, QTableView {\n"
"    background-color: #121826;\n"
"    alternate-background-color: #1B2330;\n"
"    border: 1px solid #4C8EDA;\n"
"    color: #E6F1FF;\n"
"    gridline-color: #30363D;\n"
"    selection-background-colo"
                        "r: #264F78;\n"
"    selection-color: #FFFFFF;\n"
"    font-size: 10.5pt;\n"
"}\n"
"\n"
"QTableWidget::item, QTableView::item {\n"
"    padding: 4px;\n"
"}\n"
"\n"
"QTableWidget::item:selected, QTableView::item:selected {\n"
"    background-color: #264F78;\n"
"    color: #FFFFFF;\n"
"}\n"
"\n"
"/* HEADERS */\n"
"QHeaderView::section {\n"
"    background-color: #161B22;\n"
"    color: #E6F1FF;\n"
"    border: 1px solid #30363D;\n"
"    padding: 6px;\n"
"    font-size: 10pt;\n"
"}\n"
"\n"
"/* LIST WIDGET */\n"
"QListWidget {\n"
"    background-color: #121826;\n"
"    border: 1px solid #4C8EDA;\n"
"    color: #E6F1FF;\n"
"}\n"
"\n"
"QListWidget::item {\n"
"    padding: 4px;\n"
"}\n"
"\n"
"QListWidget::item:selected {\n"
"    background-color: #264F78;\n"
"    color: #FFFFFF;\n"
"}\n"
"\n"
"/* SCROLLBARS */\n"
"QScrollBar:vertical, QScrollBar:horizontal {\n"
"    background-color: #161B22;\n"
"    border: none;\n"
"    width: 12px;\n"
"}\n"
"\n"
"QScrollBar::handle:vertical, QScrollBar::handle:horizontal {\n"
"    "
                        "background-color: #4C8EDA;\n"
"    min-height: 20px;\n"
"    border-radius: 6px;\n"
"}\n"
"\n"
"QScrollBar::handle:hover {\n"
"    background-color: #58A6FF;\n"
"}\n"
"\n"
"QScrollBar::add-line, QScrollBar::sub-line {\n"
"    background: none;\n"
"}\n"
"\n"
"/* COMBOBOXES */\n"
"QComboBox {\n"
"    background-color: #161B22;\n"
"    border: 1px solid #4C8EDA;\n"
"    border-radius: 4px;\n"
"    padding: 6px;\n"
"    color: #E6F1FF;\n"
"}\n"
"\n"
"QComboBox QAbstractItemView {\n"
"    background-color: #0D1117;\n"
"    selection-background-color: #264F78;\n"
"    color: #E6F1FF;\n"
"}\n"
"\n"
"/* TABS */\n"
"QTabWidget::pane {\n"
"    border: 1px solid #4C8EDA;\n"
"    background-color: #121826;\n"
"    border-radius: 6px;\n"
"    padding: 4px;\n"
"}\n"
"\n"
"QTabBar::tab {\n"
"    background-color: #21262D;\n"
"    border: 1px solid #4C8EDA;\n"
"    padding: 6px 12px;\n"
"    border-top-left-radius: 6px;\n"
"    border-top-right-radius: 6px;\n"
"    margin-right: 2px;\n"
"    color: #E6F1FF;\n"
"}\n"
"\n"
"QTa"
                        "bBar::tab:selected {\n"
"    background-color: #264F78;\n"
"    border-color: #58A6FF;\n"
"}\n"
"\n"
"/* MESSAGE BOX */\n"
"QMessageBox {\n"
"    background-color: #121826;\n"
"    color: #E6F1FF;\n"
"    border: 1px solid #4C8EDA;\n"
"}\n"
"\n"
"QMessageBox QLabel {\n"
"    color: #E6F1FF;\n"
"    font-size: 11pt;\n"
"}\n"
"\n"
"QMessageBox QPushButton {\n"
"    background-color: #21262D;\n"
"    color: #E6F1FF;\n"
"    border: 1px solid #4C8EDA;\n"
"    border-radius: 6px;\n"
"    padding: 6px 12px;\n"
"}\n"
"\n"
"QMessageBox QPushButton:hover {\n"
"    background-color: #2C313C;\n"
"    border-color: #58A6FF;\n"
"}\n"
"\n"
"QMessageBox QPushButton:pressed {\n"
"    background-color: #3B4452;\n"
"}\n"
""));
        gridLayout = new QGridLayout(ListenersDialog);
        gridLayout->setObjectName("gridLayout");
        label = new QLabel(ListenersDialog);
        label->setObjectName("label");
        QFont font;
        font.setFamilies({QString::fromUtf8("Fira Code")});
        font.setPointSize(11);
        font.setBold(true);
        label->setFont(font);
        label->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        tabWidget = new QTabWidget(ListenersDialog);
        tabWidget->setObjectName("tabWidget");
        tab = new QWidget();
        tab->setObjectName("tab");
        formLayout = new QFormLayout(tab);
        formLayout->setObjectName("formLayout");
        label_5 = new QLabel(tab);
        label_5->setObjectName("label_5");

        formLayout->setWidget(0, QFormLayout::ItemRole::LabelRole, label_5);

        listenerNameBox = new QLineEdit(tab);
        listenerNameBox->setObjectName("listenerNameBox");

        formLayout->setWidget(0, QFormLayout::ItemRole::FieldRole, listenerNameBox);

        label_2 = new QLabel(tab);
        label_2->setObjectName("label_2");

        formLayout->setWidget(1, QFormLayout::ItemRole::LabelRole, label_2);

        bindInterfaceBox = new QComboBox(tab);
        bindInterfaceBox->setObjectName("bindInterfaceBox");

        formLayout->setWidget(1, QFormLayout::ItemRole::FieldRole, bindInterfaceBox);

        label_3 = new QLabel(tab);
        label_3->setObjectName("label_3");

        formLayout->setWidget(2, QFormLayout::ItemRole::LabelRole, label_3);

        bindPortBox = new QSpinBox(tab);
        bindPortBox->setObjectName("bindPortBox");
        bindPortBox->setMinimum(1);
        bindPortBox->setMaximum(65000);
        bindPortBox->setValue(443);

        formLayout->setWidget(2, QFormLayout::ItemRole::FieldRole, bindPortBox);

        label_6 = new QLabel(tab);
        label_6->setObjectName("label_6");

        formLayout->setWidget(3, QFormLayout::ItemRole::LabelRole, label_6);

        agentPortBox = new QSpinBox(tab);
        agentPortBox->setObjectName("agentPortBox");
        agentPortBox->setMinimum(1);
        agentPortBox->setMaximum(65000);
        agentPortBox->setValue(443);

        formLayout->setWidget(3, QFormLayout::ItemRole::FieldRole, agentPortBox);

        label_4 = new QLabel(tab);
        label_4->setObjectName("label_4");

        formLayout->setWidget(4, QFormLayout::ItemRole::LabelRole, label_4);

        agentCallbacksBox = new QTextEdit(tab);
        agentCallbacksBox->setObjectName("agentCallbacksBox");

        formLayout->setWidget(5, QFormLayout::ItemRole::SpanningRole, agentCallbacksBox);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName("tab_2");
        tabWidget->addTab(tab_2, QString());

        gridLayout->addWidget(tabWidget, 1, 0, 1, 1);

        buttonBox = new QDialogButtonBox(ListenersDialog);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setOrientation(Qt::Orientation::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::StandardButton::Cancel|QDialogButtonBox::StandardButton::Ok);

        gridLayout->addWidget(buttonBox, 2, 0, 1, 1);


        retranslateUi(ListenersDialog);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(ListenersDialog);
    } // setupUi

    void retranslateUi(QDialog *ListenersDialog)
    {
        ListenersDialog->setWindowTitle(QCoreApplication::translate("ListenersDialog", "ListenersDialog", nullptr));
        label->setText(QCoreApplication::translate("ListenersDialog", "New Listener", nullptr));
        label_5->setText(QCoreApplication::translate("ListenersDialog", "Listener Name", nullptr));
        listenerNameBox->setText(QCoreApplication::translate("ListenersDialog", "Listener 1", nullptr));
        label_2->setText(QCoreApplication::translate("ListenersDialog", "Bind Interface:", nullptr));
        label_3->setText(QCoreApplication::translate("ListenersDialog", "Bind Port:", nullptr));
        label_6->setText(QCoreApplication::translate("ListenersDialog", "Agent Port:", nullptr));
        label_4->setText(QCoreApplication::translate("ListenersDialog", "Agent Callbacks:", nullptr));
        agentCallbacksBox->setMarkdown(QCoreApplication::translate("ListenersDialog", "`http://127.0.0.1:443`\n"
"\n"
"`http://localhost:443`\n"
"\n"
"", nullptr));
        agentCallbacksBox->setHtml(QCoreApplication::translate("ListenersDialog", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Fira Code','Consolas','Courier New','monospace'; font-size:11.5pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:7px; margin-bottom:7px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Fira Code','Consolas','monospace'; font-size:11pt;\">http://127.0.0.1:443</span></p>\n"
"<p style=\" margin-top:7px; margin-bottom:7px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Fira Code','Consolas','monospace'; font-size:11pt;\">http://localhost:443</span></p></body></html"
                        ">", nullptr));
        agentCallbacksBox->setPlaceholderText(QCoreApplication::translate("ListenersDialog", "www.constoso.com", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("ListenersDialog", "HTTP", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("ListenersDialog", "Azure", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ListenersDialog: public Ui_ListenersDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LISTENERSDIALOG_H
