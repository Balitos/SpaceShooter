#include <iostream>
#include "Bullet.h"
#include "Game.h"
#include "Enemy.h"
#include "Player.h"
#include "UI.h"
#include "Menu.h"
#include <fstream>
#include <string>

using namespace std;
#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600


int page_number;

int main()
{



    srand(time(NULL));
    sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Brick Shooter");
    window.setFramerateLimit(60);
    Menu menu(600,600);
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
            {
                window.close();
            }
            if (event.type== sf::Event::KeyReleased){
                if (event.key.code == sf::Keyboard::Up){
                    menu.MoveUp();
                    break;
                }
                if (event.key.code == sf::Keyboard::Down){
                    menu.MoveDown();
                    break;
                }
                if (event.key.code == sf::Keyboard::Return){

                    if (menu.GetPressedItem() == 0){
                        std::cout << "Play button has been pressed" << std::endl;
                        window.close();
                        page_number=0;


                    }
                    if (menu.GetPressedItem() == 1){
                        //window.close();
                        page_number=1;
                    }
                    if (menu.GetPressedItem() == 2){
                        window.close();
                        page_number=2;
                    }

                }
                if (page_number ==0){
                        window.close();
                        Game game;
                    }
            }


        }






        window.clear();
        menu.draw(window);
        window.display();
    }

    return 0;
}
