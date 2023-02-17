#ifndef VIEW_WAITINGINQUEUE_H
#define VIEW_WAITINGINQUEUE_H

#include <QDialog>

#include "../utils/websocketclient.h"
#include "../Views/view_multiplayer.h"

namespace Ui {
class view_waitinginqueue;
}

class view_waitinginqueue : public QDialog
{
    Q_OBJECT

public:
    static view_waitinginqueue* getInstance();
    void startGame();
    ~view_waitinginqueue();

private:
    Ui::view_waitinginqueue *ui;
    explicit view_waitinginqueue(QWidget *parent = nullptr);
    static view_waitinginqueue* m_instance;
    QString m_ip = "85.214.124.142";
    QString m_port = "1215";
};

#endif // VIEW_WAITINGINQUEUE_H
