#ifndef GAME_H
#define GAME_H
#include "card.h"
#include "player.h"
#include "QVector"
#include "../utils/csv_utils.h"

class Game
{
private:
    Player *Players[3];
    QVector<Card> CardsW;
    QVector<Card> CardsB;
    Card *ActiveCard;
public:
    Game();
    void Get_CSVBCard();
    void Get_CSVWCard();
    void Update();
    void GameRound();
};

#endif // GAME_H
