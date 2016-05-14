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

    const double timeStep = 1.0f / 180.0f;
    double lag = 0;

    while(running)
    {
        sf::Event event;
        while (pollEvent(event)) {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) stop();
            if (state) state->handleEvents(event);
        }

        double dt = timer.restart().asSeconds();
        if(dt > .05) {
            dt = .05;
        }
        lag += dt;
        std::cout<<dt<<std::endl;

        while(lag >= timeStep) {
            if(state) state->update(timeStep);
            lag -= timeStep;
        }
        double alpha = lag / timeStep;

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
