//
// Created by Ryan on 7/30/2015.
//

#ifndef RAINSFORD_ENGINE_HPP
#define RAINSFORD_ENGINE_HPP

#include <SFML/graphics.hpp>
#include <memory>

#include "EngineState.hpp"
#include "GameWindow.hpp"
#include "AssetManager.hpp"

class Engine {
public:
    Engine();
    void run();
    void stop();
    void setState(engineState_ptr newState);

private:
    engineState_ptr state;
    GameWindow gameWindow;
    AssetManager assetManager;
    bool running;
};

#endif //RAINSFORD_ENGINE_HPP
