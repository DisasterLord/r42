#ifndef CARD_H
#define CARD_H
#include "QObject"

enum C_Typ
{
    WHITE,BLACK
};


struct Card
{
    Card();
    Card( int id, QString text, int luecken, C_Typ typ);
    int ID;
    QString Text;
    int Luecken;
    C_Typ Typ;

};

#endif // CARD_H

