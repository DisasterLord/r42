#ifndef VIEW_MULTIPLAYER_H
#define VIEW_MULTIPLAYER_H

#include <QDialog>
#include <QString>
#include <QTcpSocket>
#include <QHostAddress>
#include "Client.h"
namespace Ui {
class view_multiplayer;
}


class Client;
class view_multiplayer : public QDialog
{
    Q_OBJECT

public:
    explicit view_multiplayer(QWidget *parent = nullptr);
    ~view_multiplayer();
public slots:
private:
    Ui::view_multiplayer *ui;
    Client *client;
signals:
};

#endif // VIEW_MULTIPLAYER_H
