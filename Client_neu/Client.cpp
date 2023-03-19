#include "Views/Client.h"

// Konstruktor der Klasse Client
Client::Client( QObject* parent ): QObject( parent ){
   client=new QTcpSocket;
   // Verbindung von "connected()" Signal zu "startTransfer()" Slot herstellen
   connect( client, SIGNAL( connected() ), this, SLOT( startTransfer() ) );
   // Verbindung von "readyRead()" Signal zu "startRead()" Slot herstellen
   connect(client, SIGNAL(readyRead()), this, SLOT(startRead()));
}

// Konstruktor mit Parameter
Client::Client(view_multiplayer* View):Client()
{
    this->View = View;
}

// Destruktor
Client::~Client(){
  client->close();  // Socket schließen
  client->deleteLater();    // Socket löschen
}

// Methode zum Starten der Verbindung
void Client::start( QString address, quint16 port )
{
    QHostAddress addr( address );   // Adresse des Servers
    client->connectToHost( addr, port );    // Verbindung zum Server aufbauen

}

// Methode zum Senden von Daten an den Server
void Client::startTransfer(){
  QString str("GET \r\n \r\n"); // HTTP-Request senden
  QByteArray ba = str.toLocal8Bit();
  const char *c_str = ba.data();

  client->write( c_str, str.length()+1 );
}

// Methode zum Empfangen von Daten vom Server
void Client::startRead(){

  char buffer[1024] = {0};
  QTcpSocket *sender = (QTcpSocket* ) QObject::sender();
  sender->read(buffer, sender->bytesAvailable());

  //Empfangenen String zum Debuggen ausgeben
  qDebug() << buffer;
  //QStringList tokens = QString( sender->readLine() ).split( "/" );
}
