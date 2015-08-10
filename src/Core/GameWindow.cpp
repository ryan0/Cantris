//
// Created by Ryan on 8/2/2015.
//

#include "Core/GameWindow.hpp"
#include <iostream>

GameWindow::GameWindow() {

}

void GameWindow::run() {
    running = true;
    sf::Clock timer;
    sf::Event event;

    while(running)
    {
        pollEvent(event);
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            stop();

        if(state) {
            float tpf = timer.restart().asSeconds();
            state->handleEvents(event);
            state->update(tpf);
            state->render(*this);
        }
        display();
        clear();
    }
}

void GameWindow::stop() {
    running = false;
}


void GameWindow::setState(windowState_ptr newState) {
    if(state) {
        state->cleanup();
    }
    state = std::move(newState);
    if(state) {
        state->initialize(*this, assetManager);
    }
}

void GameWindow::makeLetterBox(sf::Vector2f viewSize) {
    float resRatio = (float)getSize().x / (float)getSize().y;
    float viewRatio = viewSize.x / viewSize.y;

    sf::View camera(sf::FloatRect(0, 0, viewSize.x, viewSize.y));
    if(resRatio > viewRatio) {
        camera.setViewport(sf::FloatRect((1.0f - viewRatio / resRatio) * .5f, 0.0f, viewRatio / resRatio, 1.0f));
    }
    else {
        camera.setViewport(sf::FloatRect(0.0f, (1.0f - resRatio / viewRatio) * .5f, 1.0f, resRatio / viewRatio));
    }
    setView(camera);
}
