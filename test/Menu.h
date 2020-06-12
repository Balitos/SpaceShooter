#pragma once
#include "SFML/Graphics.hpp"
#include <iostream>
#include <fstream>
#include <string>

#define MAX_NUMBER_OF_ITEMS 3

class Menu
{
public:
    Menu(float width, float height);
    ~Menu();

    void MenuPause();

    void draw(sf::RenderWindow &window);
    void MoveUp();
    void MoveDown();
    int GetPressedItem() { return selectedItemIndex; }

private:
    int selectedItemIndex;
    sf::Font font;
    sf::Text menu[MAX_NUMBER_OF_ITEMS];




};