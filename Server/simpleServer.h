#ifndef SIMPLESERVER_H
#define SIMPLESERVER_H

#include <QObject>
#include "card.h"
#include "simpleClient.h"

// Darauf achten, dass in der .pro-Datei folgender Eintrag steht
// QT += network
// Falls nachträglich hinzugefügt, dann qmake nocheinmal starten
// sonst werden die beiden folgenden Zeilen nicht erkannt
#include <QTcpServer>
#include <QTcpSocket>


#define MAXCLIENT 4

class Server: public QObject
{
Q_OBJECT
public:
  Server(QObject * parent = 0);     // Konstruktor
  ~Server();                        // Destruktor
    QVector<Card> loadCards(QString fileName);   // Funktion zum Laden der Karten aus einer CSV-Datei
    QString getBlackCard(QVector<Card>);          // Funktion zum Abrufen einer schwarzen Karte
public slots:
  void acceptConnection();            // Slot zur Verarbeitung neuer Client-Verbindungen
  void startRead();                   // Slot zum Lesen von Daten von einem Client-Socket
  void startTransfer(QString message, int i);    // Slot zum Senden von Daten an einen Client-Socket
signals:
  void sigClientFull(QString,int);    // Signal, das gesendet wird, wenn ein neuer Client-Verbunden ist

private:
  QTcpServer *server;                  // Zeiger auf QTcpServer-Objekt
  QTcpSocket* client[MAXCLIENT];       // Array von QTcpSocket-Objekten für jeden Client
  int clientCount = 0;                 // Anzahl der verbundenen Clients
  QVector<Card> whiteCard;             // Vector für weiße Karten
  QVector<Card> blackCard;             // Vector für schwarze Karten
  QString transferMessage;             // String für die Übertragung von Nachrichten an Clients
};

#endif // SIMPLESERVER_H
