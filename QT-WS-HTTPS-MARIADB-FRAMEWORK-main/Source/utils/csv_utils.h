#ifndef CSV_UTILS_H
#define CSV_UTILS_H
#include "../CAH/card.h"
#include "QVector"


class csv_utils
{
public:
    csv_utils();
    static QVector<Card> read_CardCSV(QString p_Path);
};

#endif // CSV_UTILS_H
