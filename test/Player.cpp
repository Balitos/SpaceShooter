#include "Player.h"
#include <iostream>


Player::Player(sf::Texture *texture, sf::Vector2u windowSize, sf::Font font, sf::RenderWindow &window, sf::Texture bulletTex)
    :m_window{window}, m_font{font}, m_bulletTex{bulletTex}
{
    this->HPMax = 10;
    this->HP = this->HPMax;

    this->m_texture = texture;
    this->m_texture->setSmooth(true);
    this->m_sprite.setTexture(*texture);
    this->m_sprite.setPosition(windowSize.x / 2 - this->m_sprite.getLocalBounds().width / 2, windowSize.y);

    hpText.setFont(m_font);
    hpText.setCharacterSize(12.f);
    hpText.setFillColor(sf::Color::White);
}

void Player::move()
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        this->m_sprite.move(0, -10.f);
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        this->m_sprite.move(0, 10.f);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        this->m_sprite.move(-10.f, 0);
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        this->m_sprite.move(10.f, 0);
    }

    hpText.setPosition(m_sprite.getPosition().x, m_sprite.getPosition().y - hpText.getGlobalBounds().height);
    hpText.setString(std::to_string(HP) + "/" + std::to_string(HPMax));

    //COLLISION WITH WINDOW
    if(m_sprite.getPosition().x <= 0) //Left
    {
        m_sprite.setPosition(0.f, m_sprite.getPosition().y);
    }
    if(m_sprite.getPosition().x >= m_window.getSize().x - m_sprite.getGlobalBounds().width) //Right
    {
        m_sprite.setPosition(m_window.getSize().x - m_sprite.getGlobalBounds().width, m_sprite.getPosition().y);
    }
    if(m_sprite.getPosition().y <= 0) //Top
    {
        m_sprite.setPosition(m_sprite.getPosition().x, 0.f);
    }
    if(m_sprite.getPosition().y >= m_window.getSize().y - m_sprite.getGlobalBounds().height) //Bottom
    {
        m_sprite.setPosition(m_sprite.getPosition().x, m_window.getSize().y - m_sprite.getGlobalBounds().height);
    }

    //UPDATE CONTROLS
    if(shootTimer < 15)
    {
        shootTimer++;
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && shootTimer >= 15) //Shooting
    {
        bullets.push_back(Bullet(&m_bulletTex, m_sprite.getPosition()));
        shootTimer = 0; //Reset timer
    }
}

void Player::draw()
{
    m_window.draw(m_sprite);
}

Player::~Player(){}
