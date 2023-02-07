#ifndef PLAYER_H
#define PLAYER_H

#include "card.h"
#include <QObject>

class Player
{
private:
    int m_id;
    QString m_name;
    bool m_tzar;
    int m_score;
    Card m_cards[10];
public:
    Player(int p_id, QString p_name, bool p_tzar, int p_score, Card (&p_card)[10]);
    void m_addCard(Card* p_Card);
    void m_removeCard(Card* p_Card);
};

#endif // PLAYER_H
