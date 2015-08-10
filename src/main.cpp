#include "Core/GameWindow.hpp"
#include "GUI/StartMenu.hpp"

int main() {
    GameWindow gameWindow;
    gameWindow.create(sf::VideoMode::getDesktopMode(), "Rainsford", sf::Style::Fullscreen);

    gameWindow.setState(windowState_ptr(new StartMenu));
    gameWindow.run();
    return 0;
}