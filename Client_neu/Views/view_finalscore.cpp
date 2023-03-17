#include "view_finalscore.h"
#include "ui_view_finalscore.h"

view_finalscore::view_finalscore(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::view_finalscore)
{
    ui->setupUi(this);
}

view_finalscore::~view_finalscore()
{
    delete ui;
}
