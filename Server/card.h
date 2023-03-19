#ifndef CARD_H
#define CARD_H

#include <QString>

// Struktur, die eine Karte darstellt
struct Card
{
    Card() : id(NULL), text(""), blanks(0) {} // Konstruktor, der die Werte der Karte initialisiert
    Card(int p_id, QString p_text, int p_blanks); // Konstruktor, um eine Karte mit gegebenen Werten zu erstellen
    int id; // ID der Karte
    QString text; // Text auf der Karte
    int blanks; // Anzahl der Lücken in dem Text auf der Karte
};

#endif // CARD_H

