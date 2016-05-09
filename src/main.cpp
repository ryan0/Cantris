#include <afxres.h>
#include "Core/GameWindow.hpp"
#include "GUI/StartMenu.hpp"

int main() {
    SetPriorityClass(GetCurrentProcess(), ABOVE_NORMAL_PRIORITY_CLASS);

    GameWindow gameWindow;
    sf::VideoMode videoMode(600, 400);
    sf::ContextSettings contextSettings;
    contextSettings.antialiasingLevel = 0;
    contextSettings.majorVersion = 3;
    contextSettings.minorVersion = 0;
    gameWindow.create(sf::VideoMode::getDesktopMode(), "Rainsford", sf::Style::Fullscreen, contextSettings);
    gameWindow.setVerticalSyncEnabled(true);
    gameWindow.setState(windowState_ptr(new StartMenu));
    gameWindow.run();

    return 0;
}