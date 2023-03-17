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
  Server(QObject * parent = 0);
  ~Server();
    QVector<Card> loadCards(QString fileName);
    QString getBlackCard(QVector<Card>);
public slots:
  void acceptConnection();
  void startRead();
  void startTransfer(QString message, int i);
signals:
  void sigClientFull(QString,int);

private:
  QTcpServer *server;
  QTcpSocket* client[MAXCLIENT];
  int clientCount = 0;
  QVector<Card> whiteCard;
  QVector<Card> blackCard;
  QString transferMessage;
};
#endif // SIMPLESERVER_H
