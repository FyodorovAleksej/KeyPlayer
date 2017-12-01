/********************************************************************************
** Form generated from reading UI file 'keymainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_KEYMAINWINDOW_H
#define UI_KEYMAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_KeyMainWindow
{
public:
    QAction *actionSaveFile;
    QAction *actionOpenFile;
    QAction *actionSaveFileMenu;
    QAction *actionOpenFileMenu;
    QAction *actionProperties;
    QWidget *centralwidget;
    QGridLayout *gridLayout_2;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout;
    QTreeWidget *fileTreeWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *editButton;
    QSpacerItem *verticalSpacer;
    QPushButton *addButton;
    QSpacerItem *verticalSpacer_2;
    QPushButton *autoButton;
    QSpacerItem *verticalSpacer_4;
    QPushButton *deleteButton;
    QSpacerItem *verticalSpacer_3;
    QPushButton *deleteAllButton;
    QTabWidget *tabWidget;
    QWidget *tab_0;
    QGridLayout *gridLayout;
    QListWidget *keyListWidget_0;
    QWidget *tab_1;
    QGridLayout *gridLayout_3;
    QListWidget *keyListWidget_1;
    QWidget *tab_2;
    QGridLayout *gridLayout_4;
    QListWidget *keyListWidget_2;
    QWidget *tab_3;
    QGridLayout *gridLayout_5;
    QListWidget *keyListWidget_3;
    QWidget *tab_4;
    QGridLayout *gridLayout_6;
    QListWidget *keyListWidget_4;
    QWidget *tab_5;
    QGridLayout *gridLayout_7;
    QListWidget *keyListWidget_5;
    QWidget *tab_6;
    QGridLayout *gridLayout_8;
    QListWidget *keyListWidget_6;
    QWidget *tab_7;
    QGridLayout *gridLayout_9;
    QListWidget *keyListWidget_7;
    QWidget *tab_8;
    QGridLayout *gridLayout_10;
    QListWidget *keyListWidget_8;
    QWidget *tab_9;
    QGridLayout *gridLayout_11;
    QListWidget *keyListWidget_9;
    QVBoxLayout *verticalLayout_2;
    QPushButton *playButton;
    QLabel *infoLabel;
    QLabel *fileLabel;
    QMenuBar *menubar;
    QMenu *menuFile;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *KeyMainWindow)
    {
        if (KeyMainWindow->objectName().isEmpty())
            KeyMainWindow->setObjectName(QStringLiteral("KeyMainWindow"));
        KeyMainWindow->resize(800, 600);
        QIcon icon;
        icon.addFile(QStringLiteral("../../Downloads/w256h2561350657674tone.png"), QSize(), QIcon::Normal, QIcon::Off);
        KeyMainWindow->setWindowIcon(icon);
        actionSaveFile = new QAction(KeyMainWindow);
        actionSaveFile->setObjectName(QStringLiteral("actionSaveFile"));
        actionOpenFile = new QAction(KeyMainWindow);
        actionOpenFile->setObjectName(QStringLiteral("actionOpenFile"));
        actionSaveFileMenu = new QAction(KeyMainWindow);
        actionSaveFileMenu->setObjectName(QStringLiteral("actionSaveFileMenu"));
        actionOpenFileMenu = new QAction(KeyMainWindow);
        actionOpenFileMenu->setObjectName(QStringLiteral("actionOpenFileMenu"));
        actionProperties = new QAction(KeyMainWindow);
        actionProperties->setObjectName(QStringLiteral("actionProperties"));
        centralwidget = new QWidget(KeyMainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        gridLayout_2 = new QGridLayout(centralwidget);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        fileTreeWidget = new QTreeWidget(centralwidget);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QStringLiteral("1"));
        fileTreeWidget->setHeaderItem(__qtreewidgetitem);
        fileTreeWidget->setObjectName(QStringLiteral("fileTreeWidget"));

        horizontalLayout->addWidget(fileTreeWidget);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        editButton = new QPushButton(centralwidget);
        editButton->setObjectName(QStringLiteral("editButton"));

        verticalLayout->addWidget(editButton);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        addButton = new QPushButton(centralwidget);
        addButton->setObjectName(QStringLiteral("addButton"));

        verticalLayout->addWidget(addButton);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        autoButton = new QPushButton(centralwidget);
        autoButton->setObjectName(QStringLiteral("autoButton"));

        verticalLayout->addWidget(autoButton);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_4);

        deleteButton = new QPushButton(centralwidget);
        deleteButton->setObjectName(QStringLiteral("deleteButton"));

        verticalLayout->addWidget(deleteButton);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_3);

        deleteAllButton = new QPushButton(centralwidget);
        deleteAllButton->setObjectName(QStringLiteral("deleteAllButton"));

        verticalLayout->addWidget(deleteAllButton);


        horizontalLayout->addLayout(verticalLayout);

        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tab_0 = new QWidget();
        tab_0->setObjectName(QStringLiteral("tab_0"));
        gridLayout = new QGridLayout(tab_0);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        keyListWidget_0 = new QListWidget(tab_0);
        keyListWidget_0->setObjectName(QStringLiteral("keyListWidget_0"));

        gridLayout->addWidget(keyListWidget_0, 0, 0, 1, 1);

        tabWidget->addTab(tab_0, QString());
        tab_1 = new QWidget();
        tab_1->setObjectName(QStringLiteral("tab_1"));
        gridLayout_3 = new QGridLayout(tab_1);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        keyListWidget_1 = new QListWidget(tab_1);
        keyListWidget_1->setObjectName(QStringLiteral("keyListWidget_1"));

        gridLayout_3->addWidget(keyListWidget_1, 0, 0, 1, 1);

        tabWidget->addTab(tab_1, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        gridLayout_4 = new QGridLayout(tab_2);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        keyListWidget_2 = new QListWidget(tab_2);
        keyListWidget_2->setObjectName(QStringLiteral("keyListWidget_2"));

        gridLayout_4->addWidget(keyListWidget_2, 0, 0, 1, 1);

        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        gridLayout_5 = new QGridLayout(tab_3);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        keyListWidget_3 = new QListWidget(tab_3);
        keyListWidget_3->setObjectName(QStringLiteral("keyListWidget_3"));

        gridLayout_5->addWidget(keyListWidget_3, 0, 0, 1, 1);

        tabWidget->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QStringLiteral("tab_4"));
        gridLayout_6 = new QGridLayout(tab_4);
        gridLayout_6->setSpacing(6);
        gridLayout_6->setContentsMargins(11, 11, 11, 11);
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        keyListWidget_4 = new QListWidget(tab_4);
        keyListWidget_4->setObjectName(QStringLiteral("keyListWidget_4"));

        gridLayout_6->addWidget(keyListWidget_4, 0, 0, 1, 1);

        tabWidget->addTab(tab_4, QString());
        tab_5 = new QWidget();
        tab_5->setObjectName(QStringLiteral("tab_5"));
        gridLayout_7 = new QGridLayout(tab_5);
        gridLayout_7->setSpacing(6);
        gridLayout_7->setContentsMargins(11, 11, 11, 11);
        gridLayout_7->setObjectName(QStringLiteral("gridLayout_7"));
        keyListWidget_5 = new QListWidget(tab_5);
        keyListWidget_5->setObjectName(QStringLiteral("keyListWidget_5"));

        gridLayout_7->addWidget(keyListWidget_5, 0, 0, 1, 1);

        tabWidget->addTab(tab_5, QString());
        tab_6 = new QWidget();
        tab_6->setObjectName(QStringLiteral("tab_6"));
        gridLayout_8 = new QGridLayout(tab_6);
        gridLayout_8->setSpacing(6);
        gridLayout_8->setContentsMargins(11, 11, 11, 11);
        gridLayout_8->setObjectName(QStringLiteral("gridLayout_8"));
        keyListWidget_6 = new QListWidget(tab_6);
        keyListWidget_6->setObjectName(QStringLiteral("keyListWidget_6"));

        gridLayout_8->addWidget(keyListWidget_6, 0, 0, 1, 1);

        tabWidget->addTab(tab_6, QString());
        tab_7 = new QWidget();
        tab_7->setObjectName(QStringLiteral("tab_7"));
        gridLayout_9 = new QGridLayout(tab_7);
        gridLayout_9->setSpacing(6);
        gridLayout_9->setContentsMargins(11, 11, 11, 11);
        gridLayout_9->setObjectName(QStringLiteral("gridLayout_9"));
        keyListWidget_7 = new QListWidget(tab_7);
        keyListWidget_7->setObjectName(QStringLiteral("keyListWidget_7"));

        gridLayout_9->addWidget(keyListWidget_7, 0, 0, 1, 1);

        tabWidget->addTab(tab_7, QString());
        tab_8 = new QWidget();
        tab_8->setObjectName(QStringLiteral("tab_8"));
        gridLayout_10 = new QGridLayout(tab_8);
        gridLayout_10->setSpacing(6);
        gridLayout_10->setContentsMargins(11, 11, 11, 11);
        gridLayout_10->setObjectName(QStringLiteral("gridLayout_10"));
        keyListWidget_8 = new QListWidget(tab_8);
        keyListWidget_8->setObjectName(QStringLiteral("keyListWidget_8"));

        gridLayout_10->addWidget(keyListWidget_8, 0, 0, 1, 1);

        tabWidget->addTab(tab_8, QString());
        tab_9 = new QWidget();
        tab_9->setObjectName(QStringLiteral("tab_9"));
        gridLayout_11 = new QGridLayout(tab_9);
        gridLayout_11->setSpacing(6);
        gridLayout_11->setContentsMargins(11, 11, 11, 11);
        gridLayout_11->setObjectName(QStringLiteral("gridLayout_11"));
        keyListWidget_9 = new QListWidget(tab_9);
        keyListWidget_9->setObjectName(QStringLiteral("keyListWidget_9"));

        gridLayout_11->addWidget(keyListWidget_9, 0, 0, 1, 1);

        tabWidget->addTab(tab_9, QString());

        horizontalLayout->addWidget(tabWidget);


        verticalLayout_3->addLayout(horizontalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        playButton = new QPushButton(centralwidget);
        playButton->setObjectName(QStringLiteral("playButton"));

        verticalLayout_2->addWidget(playButton);

        infoLabel = new QLabel(centralwidget);
        infoLabel->setObjectName(QStringLiteral("infoLabel"));

        verticalLayout_2->addWidget(infoLabel);

        fileLabel = new QLabel(centralwidget);
        fileLabel->setObjectName(QStringLiteral("fileLabel"));

        verticalLayout_2->addWidget(fileLabel);


        verticalLayout_3->addLayout(verticalLayout_2);


        gridLayout_2->addLayout(verticalLayout_3, 0, 0, 1, 1);

        KeyMainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(KeyMainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 25));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        KeyMainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(KeyMainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        KeyMainWindow->setStatusBar(statusbar);
        toolBar = new QToolBar(KeyMainWindow);
        toolBar->setObjectName(QStringLiteral("toolBar"));
        KeyMainWindow->addToolBar(Qt::TopToolBarArea, toolBar);

        menubar->addAction(menuFile->menuAction());
        menuFile->addAction(actionSaveFileMenu);
        menuFile->addAction(actionOpenFileMenu);
        toolBar->addAction(actionSaveFile);
        toolBar->addAction(actionOpenFile);
        toolBar->addAction(actionProperties);

        retranslateUi(KeyMainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(KeyMainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *KeyMainWindow)
    {
        KeyMainWindow->setWindowTitle(QApplication::translate("KeyMainWindow", "MainWindow", Q_NULLPTR));
        actionSaveFile->setText(QApplication::translate("KeyMainWindow", "saveFile", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actionSaveFile->setToolTip(QApplication::translate("KeyMainWindow", "Saving current keys list as a file on disk", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actionSaveFile->setShortcut(QApplication::translate("KeyMainWindow", "Ctrl+S", Q_NULLPTR));
        actionOpenFile->setText(QApplication::translate("KeyMainWindow", "openFile", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actionOpenFile->setToolTip(QApplication::translate("KeyMainWindow", "Opening saved key list from disk", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actionOpenFile->setShortcut(QApplication::translate("KeyMainWindow", "Ctrl+O", Q_NULLPTR));
        actionSaveFileMenu->setText(QApplication::translate("KeyMainWindow", "&Save", Q_NULLPTR));
        actionOpenFileMenu->setText(QApplication::translate("KeyMainWindow", "&Open", Q_NULLPTR));
        actionProperties->setText(QApplication::translate("KeyMainWindow", "&Properties", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actionProperties->setToolTip(QApplication::translate("KeyMainWindow", "properties of all application", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actionProperties->setShortcut(QApplication::translate("KeyMainWindow", "Alt+P", Q_NULLPTR));
        editButton->setText(QApplication::translate("KeyMainWindow", "&Edit", Q_NULLPTR));
        addButton->setText(QApplication::translate("KeyMainWindow", "&Add", Q_NULLPTR));
        autoButton->setText(QApplication::translate("KeyMainWindow", "A&uto", Q_NULLPTR));
        deleteButton->setText(QApplication::translate("KeyMainWindow", "&Delete", Q_NULLPTR));
        deleteAllButton->setText(QApplication::translate("KeyMainWindow", "De&lete All", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_0), QApplication::translate("KeyMainWindow", "&0", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_1), QApplication::translate("KeyMainWindow", "&1", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("KeyMainWindow", "&2", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("KeyMainWindow", "&3", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QApplication::translate("KeyMainWindow", "&4", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_5), QApplication::translate("KeyMainWindow", "&5", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_6), QApplication::translate("KeyMainWindow", "&6", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_7), QApplication::translate("KeyMainWindow", "&7", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_8), QApplication::translate("KeyMainWindow", "&8", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_9), QApplication::translate("KeyMainWindow", "&9", Q_NULLPTR));
        playButton->setText(QApplication::translate("KeyMainWindow", "&Play", Q_NULLPTR));
        infoLabel->setText(QApplication::translate("KeyMainWindow", "Info:", Q_NULLPTR));
        fileLabel->setText(QApplication::translate("KeyMainWindow", "File Info:", Q_NULLPTR));
        menuFile->setTitle(QApplication::translate("KeyMainWindow", "&File", Q_NULLPTR));
        toolBar->setWindowTitle(QApplication::translate("KeyMainWindow", "toolBar", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class KeyMainWindow: public Ui_KeyMainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_KEYMAINWINDOW_H
