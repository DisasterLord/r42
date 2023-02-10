/********************************************************************************
** Form generated from reading UI file 'menuwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MENUWINDOW_H
#define UI_MENUWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Menuwindow
{
public:
    QWidget *centralwidget;
    QPushButton *btnMultiplayer;
    QLabel *gameName;
    QPushButton *btnQuitGame;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Menuwindow)
    {
        if (Menuwindow->objectName().isEmpty())
            Menuwindow->setObjectName("Menuwindow");
        Menuwindow->resize(680, 540);
        Menuwindow->setStyleSheet(QString::fromUtf8("background-color: #FFFFFF;"));
        centralwidget = new QWidget(Menuwindow);
        centralwidget->setObjectName("centralwidget");
        btnMultiplayer = new QPushButton(centralwidget);
        btnMultiplayer->setObjectName("btnMultiplayer");
        btnMultiplayer->setGeometry(QRect(120, 200, 181, 34));
        btnMultiplayer->setStyleSheet(QString::fromUtf8("color: #000000; \n"
"font-size: 22px; \n"
"font-weight: bold; \n"
"border: none; \n"
"background_color: transparent; \n"
"text-align: left;"));
        gameName = new QLabel(centralwidget);
        gameName->setObjectName("gameName");
        gameName->setGeometry(QRect(120, 40, 191, 121));
        QFont font;
        font.setPointSize(20);
        font.setBold(true);
        gameName->setFont(font);
        gameName->setStyleSheet(QString::fromUtf8("color: #000000"));
        gameName->setWordWrap(true);
        btnQuitGame = new QPushButton(centralwidget);
        btnQuitGame->setObjectName("btnQuitGame");
        btnQuitGame->setGeometry(QRect(120, 240, 181, 34));
        btnQuitGame->setStyleSheet(QString::fromUtf8("color: #000000; \n"
"font-size: 22px; \n"
"font-weight: bold; \n"
"border: none; \n"
"background_color: transparent; \n"
"text-align: left;"));
        Menuwindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Menuwindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 680, 26));
        Menuwindow->setMenuBar(menubar);
        statusbar = new QStatusBar(Menuwindow);
        statusbar->setObjectName("statusbar");
        Menuwindow->setStatusBar(statusbar);

        retranslateUi(Menuwindow);

        QMetaObject::connectSlotsByName(Menuwindow);
    } // setupUi

    void retranslateUi(QMainWindow *Menuwindow)
    {
        Menuwindow->setWindowTitle(QCoreApplication::translate("Menuwindow", "Menuwindow", nullptr));
        btnMultiplayer->setText(QCoreApplication::translate("Menuwindow", "Start Game", nullptr));
        gameName->setText(QCoreApplication::translate("Menuwindow", "Cards Against Humanity", nullptr));
        btnQuitGame->setText(QCoreApplication::translate("Menuwindow", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Menuwindow: public Ui_Menuwindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MENUWINDOW_H
