#include "view_multiplayer.h"
#include "ui_view_multiplayer.h"
#include "Client.h"

view_multiplayer::view_multiplayer(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::view_multiplayer)
{
    ui->setupUi(this);
    client = new Client(this);
    client->start("127.0.0.1",8888);
   // connect(client, SIGNAL(readyRead()),this,SLOT(startRead()));

}

view_multiplayer::~view_multiplayer()
{
    delete ui;
}
