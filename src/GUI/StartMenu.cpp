//
// Created by Ryan on 7/31/2015.
//

#include <SFML/Graphics.hpp>

#include "GUI/StartMenu.hpp"
#include "Game/Game.hpp"

void StartMenu::update(float tpf) {
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Return)) {
        engineRef->setState(engineState_ptr(new Game()));
    }
}

void StartMenu::render(sf::RenderTarget &target) {
    sf::RectangleShape test = sf::RectangleShape(sf::Vector2f(100, 50));
    test.setFillColor(sf::Color::Cyan);

    target.draw(test);
}

void StartMenu::initialize(Engine &engine) {
    engineRef = &engine;
}

void StartMenu::cleanup() {

}
