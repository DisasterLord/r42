#include "player.h"
#include "game.h"

Player::Player(int p_id, QString p_name, bool p_tzar, int p_score)
{
    m_id = p_id;
    m_name = p_name;
    m_tzar = p_tzar;
    m_score = p_score;
/*
    for (int i = 0; i < 10; i++) {
        m_cards[i] = p_card[i];
    }
*/
}

void Player::m_addCard(Card *p_card)
{
    if(sizeof(m_cards) >= 10)
    {
        return;
    }


}

void Player::m_removeCard(Card *p_card)
{

}
