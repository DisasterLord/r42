#ifndef VIEW_MENUWINDOW_H
#define VIEW_MENUWINDOW_H

#include <QMainWindow>

namespace Ui {
class view_MenuWindow;
}

// Die Klasse view_MenuWindow ist eine Unterklasse von QMainWindow
class view_MenuWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit view_MenuWindow(QWidget *parent = nullptr); // Konstruktor für das Menüfenster
    ~view_MenuWindow(); // Destruktor für das Menüfenster

private slots:
    void on_btnQuitGame_clicked(); // Slot für das Klicken auf den "Spiel beenden"-Button
    void on_btnMultiplayer_clicked(); // Slot für das Klicken auf den "Mehrspieler"-Button

private:
    Ui::view_MenuWindow *ui; // UI-Elemente für das Menüfenster
  //  view_waitinginqueue *QueueWindow;
};

#endif // VIEW_MENUWINDOW_H
