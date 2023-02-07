#ifndef CSV_UTILS_H
#define CSV_UTILS_H
#include "../CAH/card.h"

#include <QVector>
#include <QDebug>
#include <QFile>
#include <QTextStream>
#include <QStringList>

class csv_utils
{
public:
    csv_utils();
    static QVector<Card> m_readCardCSV(const QString &path, card_typ p_cardType);
};

#endif // CSV_UTILS_H
