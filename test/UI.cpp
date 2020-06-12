#include "UI.h"

UI::UI(sf::RenderWindow &window, sf::Font font)
    :m_window{window}, m_font{font}
{
    scoreText.setFont(m_font);
    scoreText.setCharacterSize(20);
    scoreText.setFillColor(sf::Color::White);
    scoreText.setPosition(10.f, 10.f);

    gameOverText.setFont(m_font);
    gameOverText.setCharacterSize(30);
    gameOverText.setFillColor(sf::Color::Red);
    gameOverText.setPosition(100.f, m_window.getSize().y / 2);
    gameOverText.setString("GAME OVER!");

    eHpText.setFont(m_font);
    eHpText.setCharacterSize(12.f);
    eHpText.setFillColor(sf::Color::White);
}

UI::~UI(){}
