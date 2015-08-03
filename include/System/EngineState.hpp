//
// Created by Ryan on 7/31/2015.
//

#ifndef RAINSFORD_ENGINESTATE_HPP
#define RAINSFORD_ENGINESTATE_HPP

#include <SFML/Graphics.hpp>
#include <memory>
#include "GameWindow.hpp"
#include "AssetManager.hpp"

class Engine;
class GameWindow;
class AssetManager;

class EngineState {
public:
    virtual void update(float tpf) = 0;
    virtual void render(sf::RenderTarget& target) = 0;
    virtual void handleEvents(sf::Event& event) = 0;

    virtual void initialize(Engine& engine, GameWindow& gameWindow, AssetManager& assetManager) = 0;
    virtual void cleanup() = 0;

    virtual ~EngineState() {}
};

typedef std::unique_ptr<EngineState> engineState_ptr;

#endif //RAINSFORD_ENGINESTATE_HPP
