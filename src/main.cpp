#include "Core/GameWindow.hpp"
#include "GUI/StartMenu.hpp"

#include <Box2D/Box2D.h>
#include <iostream>

int main() {
    std::cout<<"hi";
    GameWindow gameWindow;
    gameWindow.create(sf::VideoMode::getDesktopMode(), "Rainsford", sf::Style::Fullscreen);
    gameWindow.setVerticalSyncEnabled(true);
    gameWindow.setState(windowState_ptr(new StartMenu));
    gameWindow.run();

    return 0;
}