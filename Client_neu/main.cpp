#include "Views/view_menuwindow.h"
#include "Views/view_multiplayer.h"
#include <QApplication>

// Hauptfunktion
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // Hauptfenster erstellen
    //view_MenuWindow w;
    view_multiplayer w;
    // Hauptfenster anzeigen
    w.show();
    // Event-Loop starten
    return a.exec();
}
