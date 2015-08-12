//
// Created by Ryan on 8/1/2015.
//

#ifndef RAINSFORD_GAMEWINDOW_HPP
#define RAINSFORD_GAMEWINDOW_HPP

#include <SFML/Graphics.hpp>
#include <memory>

#include "WindowState.hpp"
#include "GameWindow.hpp"
#include "AssetManager.hpp"

class GameWindow : public sf::RenderWindow {
public:
    GameWindow();
    void run();
    void stop();
    void setState(windowState_ptr newState);
    void makeLetterBox(sf::Vector2f viewSize);
    void makeLetterBox(sf::View& view);

private:
    windowState_ptr state;
    AssetManager assetManager;
    bool running;
};


#endif //RAINSFORD_GAMEWINDOW_HPP
