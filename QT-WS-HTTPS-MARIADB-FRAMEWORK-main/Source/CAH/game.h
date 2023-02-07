#ifndef GAME_H
#define GAME_H
#include "card.h"
#include "player.h"
#include "QVector"
#include "../utils/csv_utils.h"

class Game
{
private:
    Player *m_Players[3];
    QVector<Card> m_whiteCards;
    QVector<Card> m_blackCards;
    Card *m_activeCard;
public:
    Game();
    void Update();
    void GameRound();
};

#endif // GAME_H
