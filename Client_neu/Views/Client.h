#ifndef CLIENT_H
#define CLIENT_H

#include <QString>
#include <QTcpSocket>
#include <QHostAddress>
#include "view_multiplayer.h"

// Vorwärtsdeklaration der Klasse view_multiplayer
class view_multiplayer;

// Die Client-Klasse erbt von QObject
class Client: public QObject
{
    Q_OBJECT
    public:
        // Konstruktoren und Destruktor
        Client(QObject* parent = 0);
        Client(view_multiplayer*);
        ~Client();

        // Funktion zum Starten der Verbindung mit dem Server
        void start(QString address, quint16 port);

    public slots:
        // Slot zum Senden von Daten an den Server
        void startTransfer();

        // Slot zum Empfangen von Daten vom Server
        void startRead();

    private:
        // QTcpSocket-Objekt zum Verwalten der Verbindung
        QTcpSocket *client;

        // Zeiger auf das view_multiplayer-Objekt, um Daten anzuzeigen
        view_multiplayer* View;
};

#endif // CLIENT_H
