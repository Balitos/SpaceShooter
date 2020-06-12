#include "Enemy.h"
#include <iostream>


Enemy::Enemy(sf::Texture *texture, sf::Vector2u windowSize)
{
    randomSpawn= rand() % (100 + 1);

    if (  randomSpawn < 65 ){
    this->HP = 1;

    }
    else if ( randomSpawn >65 && randomSpawn<90){
    this->HP = 2;

    }
    else if ( 90 < randomSpawn){
    this->HP = 3;

    }
 //   this->HPMax = rand() % 3 + 1;
 //   this->HPMax = this->HP;

    this->m_sprite.setTexture(*texture);

    this->m_sprite.setScale(0.05f, 0.05f);

    this->m_sprite.setPosition((rand() % int(windowSize.x - this->m_sprite.getGlobalBounds().width)), 0.f);
}

void Enemy::spawn()
{
    if(enemySpawnTimer < 30)
    {
        enemySpawnTimer++;
    }
}

Enemy::~Enemy(){}
