/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "glass.h"
#include "nextfigure.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionStart_Game;
    QAction *actionExit;
    QAction *actionAbout;
    QAction *actionHelp;
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *Next;
    NextFigure *widget_2;
    QSpacerItem *verticalSpacer;
    Glass *widget;
    QVBoxLayout *verticalLayout_2;
    QPushButton *pushButton_2;
    QPushButton *pause;
    QPushButton *pushButton;
    QSpacerItem *verticalSpacer_2;
    QLabel *label;
    QLCDNumber *lcdNumber;
    QSpacerItem *verticalSpacer_3;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuProperties;
    QMenu *menuAbout;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(148, 277);
        actionStart_Game = new QAction(MainWindow);
        actionStart_Game->setObjectName(QStringLiteral("actionStart_Game"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/Images_lab5/iconNewGame.ico"), QSize(), QIcon::Normal, QIcon::Off);
        actionStart_Game->setIcon(icon);
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/Images_lab5/iconExit.ico"), QSize(), QIcon::Normal, QIcon::Off);
        actionExit->setIcon(icon1);
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName(QStringLiteral("actionAbout"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/Images_lab5/iconInfo.ico"), QSize(), QIcon::Normal, QIcon::Off);
        actionAbout->setIcon(icon2);
        actionHelp = new QAction(MainWindow);
        actionHelp->setObjectName(QStringLiteral("actionHelp"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/Images_lab5/iconInstructions.ico"), QSize(), QIcon::Normal, QIcon::Off);
        actionHelp->setIcon(icon3);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        Next = new QLabel(centralWidget);
        Next->setObjectName(QStringLiteral("Next"));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        Next->setFont(font);
        Next->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(Next);

        widget_2 = new NextFigure(centralWidget);
        widget_2->setObjectName(QStringLiteral("widget_2"));

        verticalLayout->addWidget(widget_2);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        horizontalLayout->addLayout(verticalLayout);

        widget = new Glass(centralWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setFocusPolicy(Qt::StrongFocus);
        widget->setProperty("rows", QVariant(25u));
        widget->setProperty("columns", QVariant(11u));

        horizontalLayout->addWidget(widget);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        verticalLayout_2->addWidget(pushButton_2);

        pause = new QPushButton(centralWidget);
        pause->setObjectName(QStringLiteral("pause"));

        verticalLayout_2->addWidget(pause);

        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        QFont font1;
        font1.setPointSize(8);
        pushButton->setFont(font1);

        verticalLayout_2->addWidget(pushButton);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_2);

        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label);

        lcdNumber = new QLCDNumber(centralWidget);
        lcdNumber->setObjectName(QStringLiteral("lcdNumber"));
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(0, 0, 0, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette.setBrush(QPalette::Active, QPalette::Light, brush1);
        palette.setBrush(QPalette::Active, QPalette::Midlight, brush1);
        palette.setBrush(QPalette::Active, QPalette::Dark, brush1);
        palette.setBrush(QPalette::Active, QPalette::Mid, brush1);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        palette.setBrush(QPalette::Active, QPalette::BrightText, brush);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Active, QPalette::Shadow, brush1);
        palette.setBrush(QPalette::Active, QPalette::AlternateBase, brush1);
        QBrush brush2(QColor(255, 255, 220, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::ToolTipBase, brush2);
        palette.setBrush(QPalette::Active, QPalette::ToolTipText, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Light, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Midlight, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Dark, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Mid, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::BrightText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Shadow, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Light, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Midlight, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Dark, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Mid, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::BrightText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Shadow, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush1);
        lcdNumber->setPalette(palette);
        QFont font2;
        font2.setPointSize(10);
        font2.setBold(true);
        font2.setWeight(75);
        lcdNumber->setFont(font2);
        lcdNumber->setFrameShape(QFrame::Panel);
        lcdNumber->setFrameShadow(QFrame::Raised);
        lcdNumber->setLineWidth(1);
        lcdNumber->setMidLineWidth(0);
        lcdNumber->setSmallDecimalPoint(false);
        lcdNumber->setSegmentStyle(QLCDNumber::Filled);
        lcdNumber->setProperty("value", QVariant(0));

        verticalLayout_2->addWidget(lcdNumber);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_3);


        horizontalLayout->addLayout(verticalLayout_2);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 148, 18));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuProperties = new QMenu(menuBar);
        menuProperties->setObjectName(QStringLiteral("menuProperties"));
        menuAbout = new QMenu(menuBar);
        menuAbout->setObjectName(QStringLiteral("menuAbout"));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuProperties->menuAction());
        menuBar->addAction(menuAbout->menuAction());
        menuFile->addAction(actionStart_Game);
        menuFile->addSeparator();
        menuFile->addAction(actionExit);
        menuAbout->addAction(actionAbout);
        menuAbout->addSeparator();
        menuAbout->addAction(actionHelp);

        retranslateUi(MainWindow);
        QObject::connect(actionExit, SIGNAL(triggered()), MainWindow, SLOT(close()));
        QObject::connect(pushButton_2, SIGNAL(clicked()), widget, SLOT(slotNewGame()));
        QObject::connect(pushButton, SIGNAL(clicked()), MainWindow, SLOT(close()));
        QObject::connect(widget, SIGNAL(drawPattern(Figure*)), widget_2, SLOT(paintTooltip(Figure*)));
        QObject::connect(widget, SIGNAL(setScore(int)), lcdNumber, SLOT(display(int)));
        QObject::connect(pause, SIGNAL(clicked()), widget, SLOT(pause()));
        QObject::connect(widget, SIGNAL(gamover()), widget, SLOT(gamOver()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Tetris for Milana", nullptr));
        actionStart_Game->setText(QApplication::translate("MainWindow", "Start New Game", nullptr));
#ifndef QT_NO_SHORTCUT
        actionStart_Game->setShortcut(QApplication::translate("MainWindow", "Ctrl+S", nullptr));
#endif // QT_NO_SHORTCUT
        actionExit->setText(QApplication::translate("MainWindow", "Exit", nullptr));
#ifndef QT_NO_SHORTCUT
        actionExit->setShortcut(QApplication::translate("MainWindow", "Esc", nullptr));
#endif // QT_NO_SHORTCUT
        actionAbout->setText(QApplication::translate("MainWindow", "About", nullptr));
        actionHelp->setText(QApplication::translate("MainWindow", "Help", nullptr));
#ifndef QT_NO_SHORTCUT
        actionHelp->setShortcut(QApplication::translate("MainWindow", "H", nullptr));
#endif // QT_NO_SHORTCUT
        Next->setText(QApplication::translate("MainWindow", "Next:", nullptr));
        pushButton_2->setText(QApplication::translate("MainWindow", "New Game", nullptr));
        pause->setText(QApplication::translate("MainWindow", "Pause", nullptr));
        pushButton->setText(QApplication::translate("MainWindow", "Exit", nullptr));
        label->setText(QApplication::translate("MainWindow", "Score", nullptr));
        menuFile->setTitle(QApplication::translate("MainWindow", "&Fille", nullptr));
        menuProperties->setTitle(QApplication::translate("MainWindow", "Properties", nullptr));
        menuAbout->setTitle(QApplication::translate("MainWindow", "Information", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
