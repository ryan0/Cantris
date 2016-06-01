//
// Created by Ryan on 8/2/2015.
//

#include "Core/GameWindow.hpp"
#include <SFML/OpenGL.hpp>
#include <iostream>

namespace {
    void renderThread() {

    }
}

GameWindow::GameWindow() {

}

void GameWindow::run() {
    const double lockStep = 1.0 / 120.0;
    double dtAccumulator = 0;
    sf::Clock dtClock;

    running = true;
    while(running)
    {
        sf::Event event;
        while (pollEvent(event)) {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) stop();
            if (state) state->handleEvents(event);
        }

        double dt = dtClock.restart().asSeconds();
        dtAccumulator += dt;

        while(dtAccumulator >= lockStep) {
            dtAccumulator -= lockStep;
            if(state) state->update(lockStep);
        }
        double alpha = dtAccumulator / lockStep;

        clear();
        if(state) state->render(alpha, *this);
        display();
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

void GameWindow::makeLetterBox(sf::View& view) {
    float resRatio = (float)getSize().x / (float)getSize().y;
    float viewRatio = view.getSize().x / view.getSize().y;

    if(resRatio > viewRatio) {
        view.setViewport(sf::FloatRect((1.0f - viewRatio / resRatio) * .5f, 0.0f, viewRatio / resRatio, 1.0f));
    }
    else {
        view.setViewport(sf::FloatRect(0.0f, (1.0f - resRatio / viewRatio) * .5f, 1.0f, resRatio / viewRatio));
    }
    setView(view);
}
