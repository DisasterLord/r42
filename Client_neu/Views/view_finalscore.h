#ifndef VIEW_FINALSCORE_H
#define VIEW_FINALSCORE_H

#include <QDialog>

namespace Ui {
class view_finalscore;
}

class view_finalscore : public QDialog
{
    Q_OBJECT

public:
    explicit view_finalscore(QWidget *parent = nullptr);
    ~view_finalscore();

private:
    Ui::view_finalscore *ui;
};

#endif // VIEW_FINALSCORE_H
