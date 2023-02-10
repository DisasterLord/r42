#include "menuwindow.h"
#include "ui_menuwindow.h"

MenuWindow::MenuWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MenuWindow)
{
    ui->setupUi(this);
    this->setFixedSize(QSize(680, 540));
    this->setWindowTitle("Menu - CAH");
}

MenuWindow::~MenuWindow()
{
    delete ui;
}


void MenuWindow::on_btnQuitGame_clicked()
{
    QCoreApplication::quit();
}


void MenuWindow::on_btnMultiplayer_clicked()
{
    // Close current Window
    this->close();

    // Create Queue Window
    //view_waitinginqueue* QueueWindow = view_waitinginqueue::getInstance();
   // QueueWindow->show();
}
