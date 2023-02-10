#ifndef VIEW_WAITINGINQUEUE_H
#define VIEW_WAITINGINQUEUE_H

#include <QDialog>

namespace Ui {
class view_waitinginqueue;
}

class view_waitinginqueue : public QDialog
{
    Q_OBJECT

public:
    explicit view_waitinginqueue(QWidget *parent = nullptr);
    ~view_waitinginqueue();

private:
    Ui::view_waitinginqueue *ui;
};

#endif // VIEW_WAITINGINQUEUE_H
