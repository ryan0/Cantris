#include "Core/GameWindow.hpp"
#include "GUI/StartMenu.hpp"

int main() {
    GameWindow gameWindow;
    gameWindow.create(sf::VideoMode(600, 800), "Rainsford");

    gameWindow.setState(windowState_ptr(new StartMenu));
    gameWindow.run();
    return 0;
}