#include "view_menuwindow.h"
#include "ui_view_menuwindow.h"

view_MenuWindow::view_MenuWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::view_MenuWindow)
{
    ui->setupUi(this);
    this->setFixedSize(QSize(680, 540)); // Fenstergröße festlegen
    this->setWindowTitle("Menu - CAH (ITP)"); // Fenstertitel setzen
}

view_MenuWindow::~view_MenuWindow()
{
    delete ui;
}

void view_MenuWindow::on_btnQuitGame_clicked()
{
    QCoreApplication::quit(); // Programm beenden
}


void view_MenuWindow::on_btnMultiplayer_clicked()
{
    // Close current Window
    this->close(); // Aktuelles Fenster schließen

    // Create Queue Window

    //view_waitinginqueue* QueueWindow = view_waitinginqueue::getInstance();
    //QueueWindow->show();

}
