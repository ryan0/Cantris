//
// Created by Ryan on 7/30/2015.
//

#include "System/Engine.hpp"

Engine::Engine() {
    window.create(sf::VideoMode(800, 600), "Rainsford");
}

void Engine::run() {
    running = true;
    sf::Clock timer;
    sf::Event event;

    while(running)
    {
        window.pollEvent(event);
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            stop();

        if(state) {
            state->update(timer.restart().asSeconds());
            state->render(window);
        }
        window.display();
        window.clear();
    }
}

void Engine::stop() {
    running = false;
}


void Engine::setState(engineState_ptr newState) {
    if(state) {
        state->cleanup();
    }
    state = std::move(newState);
    if(state) {
        state->initialize(*this);
    }
}
