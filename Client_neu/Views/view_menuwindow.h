#ifndef VIEW_MENUWINDOW_H
#define VIEW_MENUWINDOW_H

#include <QMainWindow>

namespace Ui {
class view_MenuWindow;
}

class view_MenuWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit view_MenuWindow(QWidget *parent = nullptr);
    ~view_MenuWindow();

private slots:
    void on_btnQuitGame_clicked();
    void on_btnMultiplayer_clicked();

private:
    Ui::view_MenuWindow *ui;
  //  view_waitinginqueue *QueueWindow;
};

#endif // VIEW_MENUWINDOW_H
