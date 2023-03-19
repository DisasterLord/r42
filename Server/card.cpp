#include "card.h"

// Konstruktor für eine Karte mit ID, Text und Anzahl der Lücken
Card::Card(int p_id, QString p_text, int p_blanks)
{
    id = p_id;      // ID der Karte setzen
    text = p_text;  // Text der Karte setzen
    blanks = p_blanks;  // Anzahl der Lücken in der Karte setzen
}

