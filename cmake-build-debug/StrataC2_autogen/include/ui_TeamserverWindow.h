/********************************************************************************
** Form generated from reading UI file 'teamserverwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TEAMSERVERWINDOW_H
#define UI_TEAMSERVERWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>
#include "../../../components/TableWidgets.h"

QT_BEGIN_NAMESPACE

class Ui_TeamserverWindow
{
public:
    QAction *actionImport_Assembly;
    QAction *actionGenerate;
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QLabel *label_2;
    QLabel *label_3;
    AgentTableWidget *agentTable;
    ListenerTableWidget *listenersTable;
    QPushButton *createListenerButton;
    QPushButton *deleteListenerButton;
    QLabel *agentLabel;
    QLabel *label_4;
    QTextEdit *cmdsTextEdit;
    QListWidget *activityList;
    QLineEdit *commandLine;
    QStatusBar *statusbar;
    QMenuBar *menuBar;
    QMenu *menu_Strata_C2;
    QMenu *menuPayloads;
    QMenu *menuArmory;

    void setupUi(QMainWindow *TeamserverWindow)
    {
        if (TeamserverWindow->objectName().isEmpty())
            TeamserverWindow->setObjectName("TeamserverWindow");
        TeamserverWindow->resize(1223, 867);
        TeamserverWindow->setStyleSheet(QString::fromUtf8("/* GLOBAL FONT & BACKGROUND */\n"
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
"    font-size: 10pt;\n"
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
        actionImport_Assembly = new QAction(TeamserverWindow);
        actionImport_Assembly->setObjectName("actionImport_Assembly");
        actionGenerate = new QAction(TeamserverWindow);
        actionGenerate->setObjectName("actionGenerate");
        centralwidget = new QWidget(TeamserverWindow);
        centralwidget->setObjectName("centralwidget");
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setHorizontalSpacing(25);
        gridLayout->setVerticalSpacing(10);
        gridLayout->setContentsMargins(15, 10, 15, 10);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        QFont font;
        font.setFamilies({QString::fromUtf8("Fira Code")});
        font.setPointSize(11);
        font.setBold(true);
        label_2->setFont(font);
        label_2->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout->addWidget(label_2, 0, 0, 1, 1);

        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setFont(font);
        label_3->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout->addWidget(label_3, 0, 1, 1, 2);

        agentTable = new AgentTableWidget(centralwidget);
        if (agentTable->columnCount() < 6)
            agentTable->setColumnCount(6);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        agentTable->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        agentTable->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        agentTable->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        agentTable->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        agentTable->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        agentTable->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        agentTable->setObjectName("agentTable");
        agentTable->setHorizontalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAlwaysOff);
        agentTable->setEditTriggers(QAbstractItemView::EditTrigger::NoEditTriggers);
        agentTable->setTabKeyNavigation(false);
        agentTable->setProperty("showDropIndicator", QVariant(false));
        agentTable->setDragDropOverwriteMode(false);
        agentTable->setAlternatingRowColors(true);
        agentTable->setSelectionMode(QAbstractItemView::SelectionMode::SingleSelection);
        agentTable->setSelectionBehavior(QAbstractItemView::SelectionBehavior::SelectRows);
        agentTable->setShowGrid(true);
        agentTable->setGridStyle(Qt::PenStyle::NoPen);
        agentTable->setRowCount(0);
        agentTable->horizontalHeader()->setCascadingSectionResizes(true);
        agentTable->horizontalHeader()->setDefaultSectionSize(50);
        agentTable->horizontalHeader()->setStretchLastSection(false);
        agentTable->verticalHeader()->setVisible(false);

        gridLayout->addWidget(agentTable, 1, 0, 2, 1);

        listenersTable = new ListenerTableWidget(centralwidget);
        if (listenersTable->columnCount() < 3)
            listenersTable->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        listenersTable->setHorizontalHeaderItem(0, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        listenersTable->setHorizontalHeaderItem(1, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        listenersTable->setHorizontalHeaderItem(2, __qtablewidgetitem8);
        listenersTable->setObjectName("listenersTable");
        listenersTable->setHorizontalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAlwaysOff);
        listenersTable->setEditTriggers(QAbstractItemView::EditTrigger::NoEditTriggers);
        listenersTable->setTabKeyNavigation(false);
        listenersTable->setProperty("showDropIndicator", QVariant(false));
        listenersTable->setDragDropOverwriteMode(false);
        listenersTable->setAlternatingRowColors(true);
        listenersTable->setSelectionMode(QAbstractItemView::SelectionMode::SingleSelection);
        listenersTable->setSelectionBehavior(QAbstractItemView::SelectionBehavior::SelectRows);
        listenersTable->setGridStyle(Qt::PenStyle::NoPen);
        listenersTable->setRowCount(0);
        listenersTable->setColumnCount(3);
        listenersTable->horizontalHeader()->setCascadingSectionResizes(true);
        listenersTable->horizontalHeader()->setMinimumSectionSize(50);
        listenersTable->horizontalHeader()->setDefaultSectionSize(50);
        listenersTable->horizontalHeader()->setHighlightSections(false);
        listenersTable->horizontalHeader()->setStretchLastSection(false);
        listenersTable->verticalHeader()->setVisible(false);
        listenersTable->verticalHeader()->setCascadingSectionResizes(false);
        listenersTable->verticalHeader()->setDefaultSectionSize(35);
        listenersTable->verticalHeader()->setStretchLastSection(false);

        gridLayout->addWidget(listenersTable, 1, 1, 1, 2);

        createListenerButton = new QPushButton(centralwidget);
        createListenerButton->setObjectName("createListenerButton");

        gridLayout->addWidget(createListenerButton, 2, 1, 1, 1);

        deleteListenerButton = new QPushButton(centralwidget);
        deleteListenerButton->setObjectName("deleteListenerButton");

        gridLayout->addWidget(deleteListenerButton, 2, 2, 1, 1);

        agentLabel = new QLabel(centralwidget);
        agentLabel->setObjectName("agentLabel");
        agentLabel->setFont(font);
        agentLabel->setFrameShadow(QFrame::Shadow::Sunken);
        agentLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout->addWidget(agentLabel, 3, 0, 1, 1);

        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");
        label_4->setFont(font);
        label_4->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout->addWidget(label_4, 3, 1, 1, 2);

        cmdsTextEdit = new QTextEdit(centralwidget);
        cmdsTextEdit->setObjectName("cmdsTextEdit");

        gridLayout->addWidget(cmdsTextEdit, 4, 0, 1, 1);

        activityList = new QListWidget(centralwidget);
        activityList->setObjectName("activityList");
        activityList->setProperty("isWrapping", QVariant(false));
        activityList->setWordWrap(true);

        gridLayout->addWidget(activityList, 4, 1, 2, 2);

        commandLine = new QLineEdit(centralwidget);
        commandLine->setObjectName("commandLine");
        commandLine->setMaxLength(999999999);
        commandLine->setFrame(true);

        gridLayout->addWidget(commandLine, 5, 0, 1, 1);

        gridLayout->setColumnStretch(0, 17);
        gridLayout->setColumnStretch(1, 3);
        gridLayout->setColumnStretch(2, 3);
        TeamserverWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(TeamserverWindow);
        statusbar->setObjectName("statusbar");
        TeamserverWindow->setStatusBar(statusbar);
        menuBar = new QMenuBar(TeamserverWindow);
        menuBar->setObjectName("menuBar");
        menuBar->setGeometry(QRect(0, 0, 1223, 33));
        menu_Strata_C2 = new QMenu(menuBar);
        menu_Strata_C2->setObjectName("menu_Strata_C2");
        menu_Strata_C2->setAcceptDrops(false);
        menuPayloads = new QMenu(menuBar);
        menuPayloads->setObjectName("menuPayloads");
        menuArmory = new QMenu(menuBar);
        menuArmory->setObjectName("menuArmory");
        TeamserverWindow->setMenuBar(menuBar);

        menuBar->addAction(menu_Strata_C2->menuAction());
        menuBar->addAction(menuPayloads->menuAction());
        menuBar->addAction(menuArmory->menuAction());
        menuPayloads->addAction(actionGenerate);
        menuArmory->addAction(actionImport_Assembly);

        retranslateUi(TeamserverWindow);

        QMetaObject::connectSlotsByName(TeamserverWindow);
    } // setupUi

    void retranslateUi(QMainWindow *TeamserverWindow)
    {
        TeamserverWindow->setWindowTitle(QCoreApplication::translate("TeamserverWindow", "TeamserverWindow", nullptr));
        actionImport_Assembly->setText(QCoreApplication::translate("TeamserverWindow", "Import Assembly...", nullptr));
        actionGenerate->setText(QCoreApplication::translate("TeamserverWindow", "Generate...", nullptr));
        label_2->setText(QCoreApplication::translate("TeamserverWindow", "Agents", nullptr));
        label_3->setText(QCoreApplication::translate("TeamserverWindow", "Listeners", nullptr));
        QTableWidgetItem *___qtablewidgetitem = agentTable->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("TeamserverWindow", "ID", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = agentTable->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("TeamserverWindow", "Hostname", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = agentTable->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("TeamserverWindow", "User", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = agentTable->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("TeamserverWindow", "Process", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = agentTable->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("TeamserverWindow", "IP", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = agentTable->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("TeamserverWindow", "Last Seen (s)", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = listenersTable->horizontalHeaderItem(0);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("TeamserverWindow", "Name", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = listenersTable->horizontalHeaderItem(1);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("TeamserverWindow", "Interface", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = listenersTable->horizontalHeaderItem(2);
        ___qtablewidgetitem8->setText(QCoreApplication::translate("TeamserverWindow", "Port", nullptr));
        createListenerButton->setText(QCoreApplication::translate("TeamserverWindow", "Create", nullptr));
        deleteListenerButton->setText(QCoreApplication::translate("TeamserverWindow", "Delete", nullptr));
        agentLabel->setText(QCoreApplication::translate("TeamserverWindow", "Agent : None", nullptr));
        label_4->setText(QCoreApplication::translate("TeamserverWindow", "Activity Log", nullptr));
        cmdsTextEdit->setHtml(QCoreApplication::translate("TeamserverWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Fira Code','Consolas','Courier New','monospace'; font-size:10pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", nullptr));
        commandLine->setPlaceholderText(QCoreApplication::translate("TeamserverWindow", "Enter a command...", nullptr));
        menu_Strata_C2->setTitle(QCoreApplication::translate("TeamserverWindow", "Strata C2", nullptr));
        menuPayloads->setTitle(QCoreApplication::translate("TeamserverWindow", "Payloads", nullptr));
        menuArmory->setTitle(QCoreApplication::translate("TeamserverWindow", "Armory", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TeamserverWindow: public Ui_TeamserverWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TEAMSERVERWINDOW_H
