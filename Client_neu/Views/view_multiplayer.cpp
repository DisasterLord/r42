#include "view_multiplayer.h"
#include "ui_view_multiplayer.h"
#include "Client.h"

// Konstruktor der Multiplayer-View, initialisiert das UI und erstellt einen neuen Client
view_multiplayer::view_multiplayer(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::view_multiplayer)
{
    ui->setupUi(this);

    // Erstellen eines neuen Client-Objekts und Verbindung zum Server auf localhost (127.0.0.1) Port 8888
    client = new Client(this);
    client->start("127.0.0.1",8888);
}

// Destruktor der Multiplayer-View
view_multiplayer::~view_multiplayer()
{
    delete ui;
}
