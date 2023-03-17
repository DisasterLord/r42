#ifndef CLIENT_H
#define CLIENT_H

#include <QString>
#include <QTcpSocket>
#include <QHostAddress>
#include "view_multiplayer.h"

class view_multiplayer;
class Client: public QObject
{
    Q_OBJECT
    public:
      Client(QObject* parent = 0);
      Client(view_multiplayer*);
      ~Client();
      void start( QString address, quint16 port );
    public slots:
      void startTransfer();
      void startRead();
    private:
      QTcpSocket *client;
      view_multiplayer* View;
};

#endif // SIMPLECLIENT_H
