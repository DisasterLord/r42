#ifndef CARD_H
#define CARD_H

#include <QString>


struct Card
{
    Card() : id(NULL), text(""), blanks(0) {}
    Card(int p_id, QString p_text, int p_blanks);
    int id;
    QString text;
    int blanks;

};

#endif // CARD_H
