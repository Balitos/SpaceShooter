#ifndef UI_H
#define UI_H

#include <SFML/Graphics.hpp>

class UI
{
public:
    UI(sf::RenderWindow &window, sf::Font font);
    ~UI();

    sf::Text scoreText;
    sf::Text gameOverText;
    sf::RenderWindow &m_window;
    sf::Font m_font;
    sf::Text eHpText;
};

#endif // UI_H
