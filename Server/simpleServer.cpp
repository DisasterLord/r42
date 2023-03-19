#include "simpleServer.h"
#include <QDateTime>
#include <QRandomGenerator>
#include <QFile>

// Konstruktor
Server::Server(QObject* parent): QObject(parent)
{
    // Initialisierung der Client-Array
    for(int i=0; i<MAXCLIENT;i++)
    {
        client[i]=NULL;
    }

    // Erstellung des QTcpServers und Starten des Listeners auf Port 8888
    server=new QTcpServer;
    connect(server, SIGNAL(newConnection()), this, SLOT(acceptConnection()));
    server->listen(QHostAddress::Any, 8888);

    // Laden der Karten und Entfernen des ersten Platzhalters
    blackCard = loadCards("../CSV/B_Cards.csv");
    blackCard.erase(blackCard.begin());
    whiteCard = loadCards("../CSV/W_Cards.csv");
    whiteCard.erase(whiteCard.begin());

    // Zufällige Auswahl einer schwarzen Karte
    transferMessage = getBlackCard(blackCard);
    qDebug() << getBlackCard(blackCard);
}

// Destruktor
Server::~Server()
{
    // Schließen des Servers
    server->close();

    // Schließen der Verbindungen zu den Clients
    for(int i=0; i<MAXCLIENT;i++)
    {
        if(client[i] != NULL)
            client[i]->close();
    }

    // Löschen des QTcpServers
    server->deleteLater();
}

// Diese Funktion wird aufgerufen, sobald ein Client eine Verbindung aufbaut
void Server::acceptConnection()
{
    // Verbindung annehmen, falls noch Platz für weitere Clients vorhanden ist
    if(clientCount <MAXCLIENT)
    {
        client[clientCount] = server->nextPendingConnection();
        connect(client[clientCount], SIGNAL(readyRead()), this, SLOT(startRead()));
        clientCount++;
        qDebug() << clientCount;
    }

    // Signal, dass der Server vollständig ist, wird ausgesendet, wenn die maximale Anzahl an Clients erreicht wurde
    connect(this,SIGNAL(sigClientFull(QString,int)),this,SLOT(startTransfer(QString,int)));
    if (clientCount == MAXCLIENT)
    {
        for(int i = 0; i< MAXCLIENT;i++)
        {
            emit sigClientFull(transferMessage, i);
        }
    }
}

// Diese Funktion wird aufgerufen, sobald ein Client Daten an den Server sendet
void Server::startRead()
{
    // Socket des Clients ermitteln
    QTcpSocket *socket = (QTcpSocket* ) QObject::sender();

    // Wenn Daten empfangen wurden
    if ( socket->canReadLine() )
    {
        qDebug() << socket->readLine();
        //Splittet die Zeile beim /
        QStringList tokens = QString( socket->readLine() ).split( "/" );

        // Wenn es sich um einen GET-Request handelt, wird ein einfaches HTML-Dokument zurückgesendet
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
  // Die übergebene Nachricht wird in ein QByteArray konvertiert
  QByteArray ba = message.toLocal8Bit();
  // Der Inhalt des QByteArrays wird als const char* gespeichert
  const char *c_str = ba.data();

  // Die Nachricht wird an den Client mit dem Index i geschickt
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
        // Die nächste Zeile der CSV-Datei wird ausgelesen
        QString line = in.readLine();
        // Die Zeile wird anhand des Trennzeichens ";" in einzelne Felder aufgespalten
        QStringList fields = line.split(";");
        if (fields.size() > 2) {
            // Die ID wird aus dem ersten Feld extrahiert und in eine Zahl umgewandelt
            int id = fields[0].remove('"').toInt();
            // Der Text wird aus dem zweiten Feld extrahiert und die Anführungszeichen werden entfernt
            QString text = fields[1].remove('"');
            // Die Anzahl wird aus dem dritten Feld extrahiert und in eine Zahl umgewandelt
            int anzahl = fields[2].remove('"').toInt();
            // Eine neue Karte wird erstellt und der Kartenliste hinzugefügt
            Card card(id, text, anzahl);
            cards.push_back(card);
        }
    }
    // Die CSV-Datei wird geschlossen und die Kartenliste wird zurückgegeben
    file.close();
    return cards;
}

// Funktion zum Auswählen einer zufälligen schwarzen Karte
QString Server::getBlackCard(QVector<Card>)
{

    // Ein Zufallsgenerator wird erstellt und mit einer aktuellen Zeitstempel-basierten Seed versehen
    QRandomGenerator random(QDateTime::currentMSecsSinceEpoch()/1000);
    // Eine zufällige Zahl zwischen 0 und der Anzahl der vorhandenen schwarzen Karten wird generiert
    int randomNumber = random.bounded(blackCard.size());
    // Die Informationen der zufälligen Karte werden in eine Nachricht verpackt
    QString Message = "getBlackCard/";
    Message += QString::number(blackCard[randomNumber].id) +"/"+blackCard[randomNumber].text+"/"+QString::number(blackCard[randomNumber].blanks);


    return Message;
}
