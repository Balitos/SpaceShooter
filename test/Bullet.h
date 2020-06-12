#ifndef BULLET_H
#define BULLET_H

#include <SFML/Graphics.hpp>

class Bullet
{
private:


public:
    Bullet(sf::Texture *texture, sf::Vector2f pos);
    ~Bullet();

    sf::Sprite m_sprite;
};

#endif // BULLET_H
