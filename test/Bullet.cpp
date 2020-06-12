#include "Bullet.h"


Bullet::Bullet(sf::Texture *texture, sf::Vector2f pos)
{
    this->m_sprite.setTexture(*texture);

    this->m_sprite.setScale(0.1f, 0.07f);

    this->m_sprite.setPosition(pos);
}

Bullet::~Bullet(){}
