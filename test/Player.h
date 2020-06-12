#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>
#include "Bullet.h"

class Player
{
public:
    Player(sf::Texture *texture, sf::Vector2u windowSize, sf::Font font, sf::RenderWindow &window, sf::Texture bulletTex);
    void move();
    void draw();
    ~Player();


    sf::Texture *m_texture;
    sf::Sprite m_sprite;
    sf::RenderWindow &m_window;

    int HP;
    int HPMax;

    std::vector<Bullet> bullets;

    int score = 0;
    int shootTimer = 20;
    sf::Text hpText;
    sf::Font m_font;
    sf::Texture m_bulletTex;
};

#endif // PLAYER_H
