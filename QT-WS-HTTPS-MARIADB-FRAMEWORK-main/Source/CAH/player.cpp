#include "player.h"

Player::Player(int p_id, QString p_name, bool p_tzar, int p_score, Card (&p_card)[10])
{
    m_id = p_id;
    m_name = p_name;
    m_tzar = p_tzar;
    m_score = p_score;

    for (int i = 0; i < 10; i++) {
        m_cards[i] = p_card[i];
    }

}

void Player::m_addCard(Card *p_card)
{

}

void Player::m_removeCard(Card *p_card)
{

}
