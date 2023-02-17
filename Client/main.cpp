#include "Views/view_menuwindow.h"
#include "Views/view_multiplayer.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    view_MenuWindow w;
    w.show();
    return a.exec();
}
