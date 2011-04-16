/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Thu Mar 31 04:54:25 2011
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QProgressBar>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QStatusBar>
#include <QtGui/QTableWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionOpen;
    QAction *actionSave;
    QAction *actionExit;
    QAction *actionSettings;
    QAction *actionHelp_with;
    QAction *actionAbout;
    QAction *actionExit_2;
    QWidget *centralWidget;
    QGridLayout *gridLayout_4;
    QGridLayout *gridLayout_3;
    QPushButton *pushButton_processList;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QTableWidget *tableWidget;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton_scan;
    QPushButton *pushButton_next;
    QPushButton *pushButton_stop;
    QPushButton *pushButton_undo;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_2;
    QCheckBox *checkBox;
    QLineEdit *valueEdit;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout;
    QLabel *label_4;
    QComboBox *searchOperationCombo;
    QLabel *label_5;
    QComboBox *dataTypeCombo;
    QCheckBox *checkBox_5;
    QLabel *label;
    QCheckBox *checkBox_3;
    QCheckBox *checkBox_2;
    QSpacerItem *horizontalSpacer_6;
    QSpacerItem *horizontalSpacer_7;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_9;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_7;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButton_8;
    QTableWidget *tableWidget_2;
    QGridLayout *gridLayout_5;
    QProgressBar *progressBar;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *pushButton_5;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *pushButton_4;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuHelp;
    QMenu *menuSettings;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->setEnabled(true);
        MainWindow->resize(606, 553);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/res/gear.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        MainWindow->setAnimated(true);
        MainWindow->setDockNestingEnabled(false);
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName(QString::fromUtf8("actionOpen"));
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName(QString::fromUtf8("actionSave"));
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        actionSettings = new QAction(MainWindow);
        actionSettings->setObjectName(QString::fromUtf8("actionSettings"));
        actionHelp_with = new QAction(MainWindow);
        actionHelp_with->setObjectName(QString::fromUtf8("actionHelp_with"));
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName(QString::fromUtf8("actionAbout"));
        actionExit_2 = new QAction(MainWindow);
        actionExit_2->setObjectName(QString::fromUtf8("actionExit_2"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout_4 = new QGridLayout(centralWidget);
        gridLayout_4->setSpacing(0);
        gridLayout_4->setContentsMargins(2, 2, 2, 2);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        gridLayout_3 = new QGridLayout();
        gridLayout_3->setSpacing(6);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        pushButton_processList = new QPushButton(centralWidget);
        pushButton_processList->setObjectName(QString::fromUtf8("pushButton_processList"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/res/RAM.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_processList->setIcon(icon1);
        pushButton_processList->setIconSize(QSize(32, 32));

        gridLayout_3->addWidget(pushButton_processList, 0, 0, 1, 1);

        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/res/save.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_2->setIcon(icon2);
        pushButton_2->setIconSize(QSize(32, 32));

        gridLayout_3->addWidget(pushButton_2, 0, 1, 1, 1);

        pushButton_3 = new QPushButton(centralWidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/res/Open.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_3->setIcon(icon3);
        pushButton_3->setIconSize(QSize(32, 32));

        gridLayout_3->addWidget(pushButton_3, 0, 2, 1, 1);

        tableWidget = new QTableWidget(centralWidget);
        if (tableWidget->columnCount() < 1)
            tableWidget->setColumnCount(1);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->horizontalHeader()->setStretchLastSection(true);

        gridLayout_3->addWidget(tableWidget, 1, 0, 1, 3);


        gridLayout_4->addLayout(gridLayout_3, 0, 0, 2, 1);

        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setEnabled(true);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy);
        groupBox->setMinimumSize(QSize(0, 315));
        groupBox->setMaximumSize(QSize(99999, 315));
        QFont font;
        font.setFamily(QString::fromUtf8("Andale Mono"));
        font.setPointSize(10);
        groupBox->setFont(font);
        groupBox->setLayoutDirection(Qt::LeftToRight);
        groupBox->setAutoFillBackground(false);
        groupBox->setFlat(false);
        groupBox->setCheckable(false);
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        pushButton_scan = new QPushButton(groupBox);
        pushButton_scan->setObjectName(QString::fromUtf8("pushButton_scan"));
        pushButton_scan->setEnabled(false);
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/res/play.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_scan->setIcon(icon4);
        pushButton_scan->setIconSize(QSize(24, 24));

        horizontalLayout_2->addWidget(pushButton_scan);

        pushButton_next = new QPushButton(groupBox);
        pushButton_next->setObjectName(QString::fromUtf8("pushButton_next"));
        pushButton_next->setEnabled(false);
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/res/forward.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_next->setIcon(icon5);
        pushButton_next->setIconSize(QSize(24, 24));

        horizontalLayout_2->addWidget(pushButton_next);

        pushButton_stop = new QPushButton(groupBox);
        pushButton_stop->setObjectName(QString::fromUtf8("pushButton_stop"));
        pushButton_stop->setEnabled(false);
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/res/stop.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_stop->setIcon(icon6);
        pushButton_stop->setIconSize(QSize(24, 24));

        horizontalLayout_2->addWidget(pushButton_stop);

        pushButton_undo = new QPushButton(groupBox);
        pushButton_undo->setObjectName(QString::fromUtf8("pushButton_undo"));
        pushButton_undo->setEnabled(false);
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/res/undo.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_undo->setIcon(icon7);
        pushButton_undo->setIconSize(QSize(24, 24));

        horizontalLayout_2->addWidget(pushButton_undo);


        verticalLayout->addLayout(horizontalLayout_2);

        groupBox_3 = new QGroupBox(groupBox);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        QFont font1;
        font1.setBold(false);
        font1.setWeight(50);
        groupBox_3->setFont(font1);
        groupBox_3->setMouseTracking(false);
        groupBox_3->setFlat(false);
        groupBox_3->setCheckable(false);
        gridLayout_2 = new QGridLayout(groupBox_3);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        checkBox = new QCheckBox(groupBox_3);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));

        gridLayout_2->addWidget(checkBox, 0, 0, 1, 1);

        valueEdit = new QLineEdit(groupBox_3);
        valueEdit->setObjectName(QString::fromUtf8("valueEdit"));

        gridLayout_2->addWidget(valueEdit, 0, 1, 1, 1);


        verticalLayout->addWidget(groupBox_3);

        groupBox_2 = new QGroupBox(groupBox);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        gridLayout = new QGridLayout(groupBox_2);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 0, 0, 1, 1);

        searchOperationCombo = new QComboBox(groupBox_2);
        searchOperationCombo->setObjectName(QString::fromUtf8("searchOperationCombo"));
        searchOperationCombo->setMinimumSize(QSize(0, 22));

        gridLayout->addWidget(searchOperationCombo, 0, 2, 1, 1);

        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setEnabled(true);
        label_5->setFont(font);
        label_5->setScaledContents(false);

        gridLayout->addWidget(label_5, 1, 0, 1, 1);

        dataTypeCombo = new QComboBox(groupBox_2);
        dataTypeCombo->setObjectName(QString::fromUtf8("dataTypeCombo"));
        dataTypeCombo->setMinimumSize(QSize(0, 22));
        dataTypeCombo->setEditable(false);

        gridLayout->addWidget(dataTypeCombo, 1, 2, 1, 1);

        checkBox_5 = new QCheckBox(groupBox_2);
        checkBox_5->setObjectName(QString::fromUtf8("checkBox_5"));
        checkBox_5->setEnabled(true);

        gridLayout->addWidget(checkBox_5, 3, 0, 1, 2);

        label = new QLabel(groupBox_2);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 2, 0, 1, 1);

        checkBox_3 = new QCheckBox(groupBox_2);
        checkBox_3->setObjectName(QString::fromUtf8("checkBox_3"));

        gridLayout->addWidget(checkBox_3, 3, 2, 1, 1);

        checkBox_2 = new QCheckBox(groupBox_2);
        checkBox_2->setObjectName(QString::fromUtf8("checkBox_2"));

        gridLayout->addWidget(checkBox_2, 6, 0, 1, 1);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_6, 0, 3, 1, 1);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_7, 0, 1, 1, 1);


        verticalLayout->addWidget(groupBox_2);


        gridLayout_4->addWidget(groupBox, 0, 1, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        horizontalLayout->setContentsMargins(-1, 0, -1, -1);
        pushButton_9 = new QPushButton(centralWidget);
        pushButton_9->setObjectName(QString::fromUtf8("pushButton_9"));
        pushButton_9->setMaximumSize(QSize(16777215, 40));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/res/Arrow.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_9->setIcon(icon8);
        pushButton_9->setIconSize(QSize(32, 32));

        horizontalLayout->addWidget(pushButton_9);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton_7 = new QPushButton(centralWidget);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));
        pushButton_7->setMaximumSize(QSize(16777215, 40));
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/res/delete-red.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_7->setIcon(icon9);
        pushButton_7->setIconSize(QSize(32, 32));

        horizontalLayout->addWidget(pushButton_7);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        pushButton_8 = new QPushButton(centralWidget);
        pushButton_8->setObjectName(QString::fromUtf8("pushButton_8"));
        pushButton_8->setMaximumSize(QSize(16777215, 40));
        QIcon icon10;
        icon10.addFile(QString::fromUtf8(":/res/add.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_8->setIcon(icon10);
        pushButton_8->setIconSize(QSize(32, 32));

        horizontalLayout->addWidget(pushButton_8);


        gridLayout_4->addLayout(horizontalLayout, 1, 1, 1, 1);

        tableWidget_2 = new QTableWidget(centralWidget);
        if (tableWidget_2->columnCount() < 5)
            tableWidget_2->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(0, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(1, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(2, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(3, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(4, __qtablewidgetitem5);
        tableWidget_2->setObjectName(QString::fromUtf8("tableWidget_2"));
        tableWidget_2->horizontalHeader()->setStretchLastSection(true);

        gridLayout_4->addWidget(tableWidget_2, 2, 0, 1, 2);

        gridLayout_5 = new QGridLayout();
        gridLayout_5->setSpacing(0);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        gridLayout_5->setSizeConstraint(QLayout::SetNoConstraint);
        progressBar = new QProgressBar(centralWidget);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setValue(24);

        gridLayout_5->addWidget(progressBar, 0, 0, 1, 5);

        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setMinimumSize(QSize(0, 30));

        gridLayout_5->addWidget(pushButton, 1, 0, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_5->addItem(horizontalSpacer_3, 1, 1, 1, 1);

        pushButton_5 = new QPushButton(centralWidget);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setMinimumSize(QSize(0, 30));

        gridLayout_5->addWidget(pushButton_5, 1, 2, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_5->addItem(horizontalSpacer_4, 1, 3, 1, 1);

        pushButton_4 = new QPushButton(centralWidget);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setMinimumSize(QSize(0, 30));

        gridLayout_5->addWidget(pushButton_4, 1, 4, 1, 1);


        gridLayout_4->addLayout(gridLayout_5, 3, 0, 1, 2);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 606, 25));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QString::fromUtf8("menuHelp"));
        menuSettings = new QMenu(menuBar);
        menuSettings->setObjectName(QString::fromUtf8("menuSettings"));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuSettings->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuFile->addAction(actionOpen);
        menuFile->addAction(actionSave);
        menuFile->addAction(actionExit_2);
        menuHelp->addAction(actionHelp_with);
        menuHelp->addAction(actionAbout);
        menuSettings->addAction(actionSettings);

        retranslateUi(MainWindow);
        QObject::connect(pushButton_processList, SIGNAL(clicked()), MainWindow, SLOT(showProcessList()));
        QObject::connect(pushButton_scan, SIGNAL(clicked()), MainWindow, SLOT(firstScan()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "H3xLabs Memory Editor", 0, QApplication::UnicodeUTF8));
        actionOpen->setText(QApplication::translate("MainWindow", "Open", 0, QApplication::UnicodeUTF8));
        actionSave->setText(QApplication::translate("MainWindow", "Save", 0, QApplication::UnicodeUTF8));
        actionExit->setText(QApplication::translate("MainWindow", "Import map file", 0, QApplication::UnicodeUTF8));
        actionSettings->setText(QApplication::translate("MainWindow", "Settings", 0, QApplication::UnicodeUTF8));
        actionHelp_with->setText(QApplication::translate("MainWindow", "Help with ---", 0, QApplication::UnicodeUTF8));
        actionAbout->setText(QApplication::translate("MainWindow", "About --", 0, QApplication::UnicodeUTF8));
        actionExit_2->setText(QApplication::translate("MainWindow", "Exit", 0, QApplication::UnicodeUTF8));
        pushButton_processList->setText(QString());
        pushButton_2->setText(QString());
        pushButton_3->setText(QString());
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("MainWindow", "Address", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("MainWindow", " Scan", 0, QApplication::UnicodeUTF8));
        pushButton_scan->setText(QApplication::translate("MainWindow", "New scan", 0, QApplication::UnicodeUTF8));
        pushButton_next->setText(QApplication::translate("MainWindow", "Next scan", 0, QApplication::UnicodeUTF8));
        pushButton_stop->setText(QApplication::translate("MainWindow", "Stop", 0, QApplication::UnicodeUTF8));
        pushButton_undo->setText(QApplication::translate("MainWindow", "Undo", 0, QApplication::UnicodeUTF8));
        groupBox_3->setTitle(QApplication::translate("MainWindow", "Value:", 0, QApplication::UnicodeUTF8));
        checkBox->setText(QApplication::translate("MainWindow", "Hex", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "Search options", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("MainWindow", "Search type", 0, QApplication::UnicodeUTF8));
        searchOperationCombo->clear();
        searchOperationCombo->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Exact value", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Bigger than..", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Less than..", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Changed", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Unchanged", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Unknown initial value", 0, QApplication::UnicodeUTF8)
        );
        label_5->setText(QApplication::translate("MainWindow", "Value type", 0, QApplication::UnicodeUTF8));
        dataTypeCombo->clear();
        dataTypeCombo->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Boolean", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Character (1 Byte)", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Integer (4 Bytes)", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Long Integer (4 Bytes)", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Float (8 Bytes)", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Double (8 Bytes)", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "String", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Unicode Character", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Unicode String", 0, QApplication::UnicodeUTF8)
        );
        checkBox_5->setText(QApplication::translate("MainWindow", "Read-Only Memory", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", "Scan locations:", 0, QApplication::UnicodeUTF8));
        checkBox_3->setText(QApplication::translate("MainWindow", "Stack", 0, QApplication::UnicodeUTF8));
        checkBox_2->setText(QApplication::translate("MainWindow", "Heap", 0, QApplication::UnicodeUTF8));
        pushButton_9->setText(QString());
        pushButton_7->setText(QString());
        pushButton_8->setText(QApplication::translate("MainWindow", "Add manually", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget_2->horizontalHeaderItem(0);
        ___qtablewidgetitem1->setText(QApplication::translate("MainWindow", "Freez", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget_2->horizontalHeaderItem(1);
        ___qtablewidgetitem2->setText(QApplication::translate("MainWindow", "Address", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget_2->horizontalHeaderItem(2);
        ___qtablewidgetitem3->setText(QApplication::translate("MainWindow", "Type", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget_2->horizontalHeaderItem(3);
        ___qtablewidgetitem4->setText(QApplication::translate("MainWindow", "Value", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget_2->horizontalHeaderItem(4);
        ___qtablewidgetitem5->setText(QApplication::translate("MainWindow", "Comments", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("MainWindow", "Trainer Maker", 0, QApplication::UnicodeUTF8));
        pushButton_5->setText(QApplication::translate("MainWindow", "Conversion Tool", 0, QApplication::UnicodeUTF8));
        pushButton_4->setText(QApplication::translate("MainWindow", "Memory Viewer", 0, QApplication::UnicodeUTF8));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", 0, QApplication::UnicodeUTF8));
        menuHelp->setTitle(QApplication::translate("MainWindow", "Help", 0, QApplication::UnicodeUTF8));
        menuSettings->setTitle(QApplication::translate("MainWindow", "Settings", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
