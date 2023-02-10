#include "view_waitinginqueue.h"
#include "ui_view_waitinginqueue.h"

view_waitinginqueue::view_waitinginqueue(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::view_waitinginqueue)
{
    ui->setupUi(this);
}

view_waitinginqueue::~view_waitinginqueue()
{
    delete ui;
}
