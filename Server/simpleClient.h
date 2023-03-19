#ifndef SIMPLECLIENT_H
#define SIMPLECLIENT_H

#include <QString>
#include <QTcpSocket>
#include <QHostAddress>
#include "card.h"

class Client: public QObject
{
    Q_OBJECT
    friend class Server;
    public:
      Client(QObject* parent = 0);     // Konstruktor der Klasse Client
      ~Client();                      // Destruktor der Klasse Client
      void start( QString address, quint16 port );  // Funktion zum Starten des Clients und Verbinden mit einem Server
    public slots:
      void startTransfer();           // Slot zum Starten der Übertragung von Daten zum Server
      void startRead();               // Slot zum Lesen von Daten vom Server
    private:
      QTcpSocket *client;             // Ein Zeiger auf den TCP-Socket, den der Client verwendet
      Card handCards[10];             // Ein Array zum Speichern der Karten, die der Client in der Hand hat
};

#endif // SIMPLECLIENT_H
