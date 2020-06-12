#ifndef ENEMY_H
#define ENEMY_H

#include <SFML/Graphics.hpp>

class Enemy
{
public:
    Enemy(sf::Texture *texture, sf::Vector2u windowSize);
    void spawn();
    ~Enemy();

    sf::Sprite m_sprite;

    int HP;

    int randomSpawn;

    int enemySpawnTimer = 0;

    std::vector<Enemy> enemies;
};

#endif // ENEMY_H
