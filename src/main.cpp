#include <SFML/OpenGL.hpp>
#include "Core/GameWindow.hpp"
#include "GUI/StartMenu.hpp"
#include "Engine/SceneEditor.hpp"

int main(int argc, char* argv[]) {
    sf::ContextSettings contextSettings;
    contextSettings.antialiasingLevel = 4;
    contextSettings.majorVersion = 2;
    contextSettings.minorVersion = 0;
    sf::VideoMode editorVideoMode(600, 400);


    if(argc > 1 && strcmp(argv[1], "Editor") == 0) {
        GameWindow editorWindow;
        editorWindow.create(editorVideoMode, "Editor", sf::Style::Default, contextSettings);
        editorWindow.setVerticalSyncEnabled(true);
        editorWindow.setState(windowState_ptr(new SceneEditor));
        editorWindow.run();
    }
    else {
        GameWindow gameWindow;
        gameWindow.create(sf::VideoMode::getDesktopMode(), "Aeilis", sf::Style::Fullscreen, contextSettings);
        gameWindow.setVerticalSyncEnabled(true);
        gameWindow.setFramerateLimit(0);
        gameWindow.setState(windowState_ptr(new StartMenu));
        gameWindow.run();
    }
    return 0;
}