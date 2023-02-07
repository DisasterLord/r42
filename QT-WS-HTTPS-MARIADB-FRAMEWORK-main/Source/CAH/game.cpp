#include "game.h"

Game::Game()
{
    // Read White / Black Cards from CSV
    QString csvPath = "C:\\Users\\JNSAP\\Documents\\GitHub\\r42\\CSV\\";
    m_blackCards = csv_utils::m_readCardCSV(csvPath + "B_Cards.csv", BLACK);
    m_whiteCards = csv_utils::m_readCardCSV(csvPath + "W_Cards.csv", WHITE);


    // Just for Debug. Delete this after.
    int posInArray = 3;
    qDebug() << "Card ID: " << m_whiteCards[posInArray].id;
    qDebug() << "Card Text: " << m_whiteCards[posInArray].text;
    qDebug() << "Card Lücken: " << m_whiteCards[posInArray].luecken;
    qDebug() << "Card Type: " << m_whiteCards[posInArray].typ;

    qDebug() << "Card ID: " << m_blackCards[posInArray].id;
    qDebug() << "Card Text: " << m_blackCards[posInArray].text;
    qDebug() << "Card Lücken: " << m_blackCards[posInArray].luecken;
    qDebug() << "Card Type: " << m_blackCards[posInArray].typ;
}

void Game::Update()
{

}

void Game::GameRound()
{

}
