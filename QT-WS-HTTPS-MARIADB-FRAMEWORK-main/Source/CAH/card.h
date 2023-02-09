#ifndef CARD_H
#define CARD_H

#include <QString>

enum card_typ {
    NONE, WHITE, BLACK
};


struct Card
{
    Card() : id(NULL), text(""), luecken(0), typ(card_typ::NONE) {}
    Card(int p_id, QString p_text, int p_luecken, card_typ p_typ);
    int id;
    QString text;
    int luecken;
    card_typ typ;

};

#endif // CARD_H

