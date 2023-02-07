#ifndef PLAYER_H
#define PLAYER_H
#include "card.h"


class Player
{
private:
    int ID;
    QString Name;
    bool Tzar;
    int Score;
    Card *Cards[10];
public:
    Player(int id, QString name, bool tzar, int score, Card cards[10]);
    void add_Card(Card* p_Card);
    void remove_Card(Card* p_Card);
};

#endif // PLAYER_H
