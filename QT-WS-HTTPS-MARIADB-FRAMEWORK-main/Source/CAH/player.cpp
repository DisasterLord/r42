#include "player.h"

Player::Player(int id, QString name, bool tzar, int score, Card cards[10])
{
    ID = id;
    Name = name;
    Tzar = tzar;
    Score = score;
    Cards = cards;
}

void Player::add_Card(Card *p_Card)
{

}

void Player::remove_Card(Card *p_Card)
{

}
