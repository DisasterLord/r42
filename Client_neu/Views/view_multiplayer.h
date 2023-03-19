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
    explicit view_multiplayer(QWidget *parent = nullptr); // Konstruktor für die Multiplayer-Ansicht
    ~view_multiplayer(); // Destruktor für die Multiplayer-Ansicht
public slots: // Öffentliche Slots, die verwendet werden können, um Signale zu empfangen
private:
    Ui::view_multiplayer *ui; // Zeiger auf das UI-Objekt für die Multiplayer-Ansicht
    Client *client; // Zeiger auf das Client-Objekt, das die TCP-Socket-Verbindung behandelt
signals: // Signale, die emittiert werden können
};

#endif // VIEW_MULTIPLAYER_H
