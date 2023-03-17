#include "simpleServer.h"
#include <QDateTime>
#include <QRandomGenerator>
#include <QFile>

Server::Server(QObject* parent): QObject(parent)
{
    for(int i=0; i<MAXCLIENT;i++)
    {
    client[i]=NULL;
    }
    server=new QTcpServer;

  connect(server, SIGNAL(newConnection()), this, SLOT(acceptConnection()));
  server->listen(QHostAddress::Any, 8888);

  blackCard = loadCards("C:/Users/Fabian/Documents/GitHub/r42/CSV/B_Cards.csv");
  blackCard.erase(blackCard.begin());
  whiteCard = loadCards("C:/Users/Fabian/Documents/GitHub/r42/CSV/W_Cards.csv");
  whiteCard.erase(whiteCard.begin());


  transferMessage = getBlackCard(blackCard);

  qDebug() << getBlackCard(blackCard);
}

Server::~Server()
{
  server->close();
  for(int i=0; i<MAXCLIENT;i++)
  {
  if(client[i] != NULL)
     client[i]->close();
  }
  server->deleteLater();
}

void Server::acceptConnection()
{
  //Verbindung annehmen
    if(clientCount <MAXCLIENT)
    {
    client[clientCount] = server->nextPendingConnection();
    connect(client[clientCount], SIGNAL(readyRead()), this, SLOT(startRead()));
    clientCount++;
    qDebug() << clientCount;

    }
    connect(this,SIGNAL(sigClientFull(QString,int)),this,SLOT(startTransfer(QString,int)));
    if (clientCount == MAXCLIENT)
    {
        for(int i = 0; i< MAXCLIENT;i++)
        {

        emit sigClientFull(transferMessage, i);
        }
    }
}

void Server::startRead(){

    // Dieser Slot wird aufgerufen, sobald der Client Daten an den Server sendet
    // Der Server überprüft, ob es sich um einen GET-Request handelt und sendet ein sehr
    // einfaches HTML-Dokument zurück

  QTcpSocket *socket = (QTcpSocket* ) QObject::sender();

  if ( socket->canReadLine() )
  {
      qDebug() << socket->readLine();
      QStringList tokens = QString( socket->readLine() ).split( "/" );
      if ( tokens[0] == "GET" )
      {
          QTextStream os( socket );
          os.setAutoDetectUnicode( true );
          os << "HTTP/1.0 200 Ok\r\n"
          "Content-Type: text/html; charset=\"utf-8\"\r\n"
          "\r\n"
          "<h1>Hallo!</h1>\n"
          << QDateTime::currentDateTime().toString() << "\n";
          socket->close();

          if ( socket->state() == QTcpSocket::UnconnectedState )
          {
              delete socket;
          }
      }
  }
}

void Server::startTransfer(QString message, int i){
  QByteArray ba = message.toLocal8Bit();
  const char *c_str = ba.data();

  client[i]->write( c_str, message.length()+1 );
}

// Funktion zum Laden der Karten aus einer CSV-Datei
QVector<Card> Server::loadCards(QString fileName) {
    QVector<Card> cards;
    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly)) {
        qDebug() << "Could not open file " << fileName;
        return cards;
    }
    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList fields = line.split(";");
        if (fields.size() > 2) {        //hier
            int id = fields[0].remove('"').toInt();
            QString text = fields[1].remove('"');
            int anzahl = fields[2].remove('"').toInt();
            Card card(id, text, anzahl);
            cards.push_back(card);
        }
    }
    file.close();
    return cards;
}

QString Server::getBlackCard(QVector<Card>)
{

    QRandomGenerator random(QDateTime::currentMSecsSinceEpoch()/1000);
    int randomNumber = random.bounded(blackCard.size());
    QString Message = "getBlackCard/";
    Message += QString::number(blackCard[randomNumber].id) +"/"+blackCard[randomNumber].text+"/"+QString::number(blackCard[randomNumber].blanks);


    return Message;
}
