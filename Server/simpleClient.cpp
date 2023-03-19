#include "simpleClient.h"

Client::Client( QObject* parent ): QObject( parent ){
   client=new QTcpSocket;
   // Verbinde das Signal connected() mit der Slot-Funktion startTransfer()
   connect( client, SIGNAL( connected() ), this, SLOT( startTransfer() ) );
   // Verbinde das Signal readyRead() mit der Slot-Funktion startRead()
   connect(client, SIGNAL(readyRead()), this, SLOT(startRead()));
}

Client::~Client(){
  // Schließe die Verbindung zum Server
  client->close();
  // Lösche den Client und dessen Objekte
  client->deleteLater();
}

void Client::start( QString address, quint16 port )
{
    // Erstelle ein Objekt von QHostAddress aus der IP-Adresse
    QHostAddress addr( address );
    // Verbinde den Client mit dem Server unter der angegebenen Adresse und dem angegebenen Port
    client->connectToHost( addr, port );
}

void Client::startTransfer(){
  // Erstelle eine neue HTTP-Anfrage
  QString str("GET \r\n \r\n");
  // Wandele die Anfrage in ein QByteArray um
  QByteArray ba = str.toLocal8Bit();
  // Konvertiere das QByteArray in einen const char*
  const char *c_str = ba.data();

  // Sende die Anfrage an den Server
  client->write( c_str, str.length()+1 );
}


void Client::startRead(){

  // Erstelle einen Char-Array-Puffer mit einer Größe von 1024
  char buffer[1024] = {0};
  // Erhalte den Sender des Signals readyRead()
  QTcpSocket *sender = (QTcpSocket* ) QObject::sender();
  // Lese die verfügbaren Bytes in den Puffer ein
  sender->read(buffer, sender->bytesAvailable());

  //Empfangenen String zum Debuggen ausgeben
  qDebug() << buffer;

  //Empfangenen String auswerten
  //ToDo
}

