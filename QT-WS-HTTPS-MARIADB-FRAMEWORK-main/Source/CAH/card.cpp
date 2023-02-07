#include "card.h"

Card::Card(int p_id, QString p_text, int p_luecken, card_typ p_typ)
{
    id = p_id;
    text = p_text;
    luecken = p_luecken;
    typ = p_typ;
}
