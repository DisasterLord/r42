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
      Client(QObject* parent = 0);
      ~Client();
      void start( QString address, quint16 port );
    public slots:
      void startTransfer();
      void startRead();
    private:
      QTcpSocket *client;
      Card handCards[10];
};

#endif // SIMPLECLIENT_H
