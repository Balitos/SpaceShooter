#include <iostream>
#include <fstream>
#include <string>
#include "Bullet.h"
#include "Game.h"
#include "Enemy.h"
#include "Player.h"
#include "UI.h"
#include "Menu.h"

using namespace std;

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

Game::Game()
{

    srand(time(NULL));
    sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Brick Shooter");

    window.setFramerateLimit(60);

    //INIT FONT
    sf::Font font;
    font.loadFromFile("fonts/Rubik-Medium.ttf");

    //INIT TEXTURES
    sf::Texture playerTex;
    playerTex.loadFromFile("textures/DurrrSpaceShip.png");

    sf::Texture enemyTex;
    enemyTex.loadFromFile("textures/enemy-alien.png");

    sf::Texture bulletTex;
    bulletTex.loadFromFile("textures/laser_purple.png");


    //UI init
    UI ui(window, font);

    //PLAYER INIT
    Player player(&playerTex, window.getSize(), font, window, bulletTex);

    int ScoreTotal;
    //ENEMY INIT
    Enemy enemy(&enemyTex, window.getSize());




    //////////////////////////////////////Récupère les scores totals pour faire de l'argent

    ifstream fichier("points.txt");
    double ancienScore;
    if (fichier){

        fichier >> ancienScore;          //On lit un mot depuis le fichier

        cout << "ancienScore Du fichier = " << ancienScore << endl;
    }

/////////////////////////////////////////////////






    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
            {
                window.close();
            }
        }


        if(player.HP > 0)
        {
            //PLAYER
            player.move();

            //BULLETS
            for(size_t i = 0; i < player.bullets.size(); i++)
            {
                //Move
                player.bullets[i].m_sprite.move(0.f, -20.f);

                //Out of window bounds
                if(player.bullets[i].m_sprite.getPosition().x > window.getSize().x)
                {
                    player.bullets.erase(player.bullets.begin() + i);
                    break;
                }

                //Enemy collision
                for(size_t k = 0; k < enemy.enemies.size(); k++)
                {
                    if(player.bullets[i].m_sprite.getGlobalBounds().intersects(enemy.enemies[k].m_sprite.getGlobalBounds()))
                    {
                        if(enemy.enemies[k].HP <= 1)
                        {

                            enemy.enemies.erase(enemy.enemies.begin() + k);

                        }
                        else
                        {
                            enemy.enemies[k].HP--; //Enemy take damage
                        }
                        player.score += enemy.enemies[k].HP;
                        player.bullets.erase(player.bullets.begin() + i);
                        ScoreTotal = player.score;
                        std::cout << "SCORE +1 = " << ScoreTotal  << std::endl;
                        break;
                    }
                }
            }

            //ENEMY SPANW
            enemy.spawn();
///augmentation difficulté
            int vitesseDeSpawn =25;
            if(ScoreTotal  > 50 && ScoreTotal < 75){
                vitesseDeSpawn = 15;
           }
            else if (ScoreTotal  > 75 && ScoreTotal < 100){
                vitesseDeSpawn = 10;
            }
          else if (ScoreTotal  > 100 && ScoreTotal < 180 ){
                vitesseDeSpawn = 5;
            }
          else if (ScoreTotal  > 180 ){
                  vitesseDeSpawn = 3;
              }
////
            if(enemy.enemySpawnTimer >= vitesseDeSpawn)
            {
                enemy.enemies.push_back(Enemy(&enemyTex, window.getSize()));
                enemy.enemySpawnTimer = 0; //Reset timer
            }

           //ENEMY MOVE
           for(size_t i = 0; i < enemy.enemies.size(); i++)
            {
                enemy.enemies[i].m_sprite.move(0.f,5.f);

                if(enemy.enemies[i].m_sprite.getPosition().y >= window.getSize().y - enemy.enemies[i].m_sprite.getGlobalBounds().height)
                {
                    enemy.enemies.erase(enemy.enemies.begin() + i);
                    break;
                }

                if(enemy.enemies[i].m_sprite.getGlobalBounds().intersects(player.m_sprite.getGlobalBounds()))
                {
                    enemy.enemies.erase(enemy.enemies.begin() + i);

                    player.HP--; //Player take damage
                    break;
                }
            }

            //UI Update
            ui.scoreText.setString("Score: " + std::to_string(player.score));

            //Draw
            window.clear();

            //PLAYER:
            window.draw(player.m_sprite);

            //BULLETS
            for(size_t i = 0; i < player.bullets.size(); i++)
            {
                window.draw(player.bullets[i].m_sprite);
            }

            //ENEMY
            for(size_t i = 0; i < enemy.enemies.size(); i++)
            {
                ui.eHpText.setString(std::to_string(enemy.enemies[i].HP) + "/" + std::to_string(enemy.enemies[i].HP));
                ui.eHpText.setPosition(enemy.enemies[i].m_sprite.getPosition().x, enemy.enemies[i].m_sprite.getPosition().y - ui.eHpText.getGlobalBounds().height);
                window.draw(ui.eHpText);
                window.draw(enemy.enemies[i].m_sprite);
            }

            //UI
            window.draw(ui.scoreText);
            window.draw(player.hpText);




        }

        if(player.HP <= 0)
        {
            window.draw(ui.gameOverText);

        }


        window.display();


    }
if (ScoreTotal > ancienScore){
    string const argent("points.txt");
    ofstream monFlux(argent.c_str());


                monFlux << ScoreTotal << endl;
                cout << "Nouveau hight score ajouter au fichier = " << ScoreTotal << endl;

            } else
            {
                 cout << "Score inferieur au hight score = " << ScoreTotal << endl;
            }


}

