//
// Created by Ryan on 8/1/2015.
//

#ifndef RAINSFORD_GAMEWINDOW_HPP
#define RAINSFORD_GAMEWINDOW_HPP

#include <SFML/Graphics.hpp>

class GameWindow : public sf::RenderWindow {
public:
   void makeLetterBox(sf::Vector2f viewSize);
};

#endif //RAINSFORD_GAMEWINDOW_HPP