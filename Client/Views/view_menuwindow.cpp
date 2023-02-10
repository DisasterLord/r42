#include "view_menuwindow.h"
#include "ui_view_menuwindow.h"

view_MenuWindow::view_MenuWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::view_MenuWindow)
{
    ui->setupUi(this);    
    this->setFixedSize(QSize(680, 540));
    this->setWindowTitle("Menu - CAH (ITP)");
}

view_MenuWindow::~view_MenuWindow()
{
    delete ui;
}

void view_MenuWindow::on_btnQuitGame_clicked()
{
    QCoreApplication::quit();
}


void view_MenuWindow::on_btnMultiplayer_clicked()
{
    // Close current Window
    this->close();

    // Create Queue Window
    /*
    view_waitingInQueue* QueueWindow = view_waitingInQueue::getInstance();
    QueueWindow->show();
    */
}
