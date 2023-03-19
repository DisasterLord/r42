#include <QCoreApplication>         // Qt-Kernanwendung
#include "simpleServer.h"            // Server-Klasse
#include "simpleClient.h"            // Client-Klasse

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv); // Qt-Kernanwendung initialisieren
    Server server;                   // Server-Objekt erstellen

    return a.exec();                 // Qt-Kernanwendung ausführen
}
