#include "csv_utils.h"

csv_utils::csv_utils()
{

}

QVector<Card> csv_utils::m_readCardCSV(const QString &path, card_typ p_cardType)
{
    QFile file(path);
    QVector<Card> cards;

    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&file);

        while (!in.atEnd()) {
            QString line = in.readLine();
            QStringList fields = line.split(";");
            if (fields.size() > 2) {        //hier
                int id = fields[0].remove('"').toInt();
                QString text = fields[1].remove('"');
                int anzahl = fields[2].remove('"').toInt();
                Card card(id, text, anzahl, p_cardType);
                cards.push_back(card);

                //qDebug() << "Creating Object for Card with ID: " << fields[0].remove('"').toInt();
            }
        }

        file.close();
    }

    return cards;
}
