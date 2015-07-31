//
// Created by Ryan on 7/30/2015.
//

#ifndef RAINSFORD_ENGINE_HPP
#define RAINSFORD_ENGINE_HPP

#include <SFML/graphics.hpp>
#include <memory>

#include "EngineState.hpp"

class Engine {
public:
    Engine();
    void run();
    void stop();
    void setState(std::unique_ptr<EngineState> newState);

private:
    sf::RenderWindow window;
    std::unique_ptr<EngineState> state;
    bool running;
};

#endif //RAINSFORD_ENGINE_HPP
