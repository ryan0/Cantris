//
// Created by Ryan on 7/31/2015.
//

#ifndef RAINSFORD_ENGINESTATE_HPP
#define RAINSFORD_ENGINESTATE_HPP

#include <SFML/Graphics.hpp>
#include <memory>
#include "AssetManager.hpp"

class GameWindow;
class AssetManager;

class WindowState {
public:
    virtual void update(float tpf) = 0;
    virtual void render(sf::RenderTarget& target) = 0;
    virtual void handleEvents(sf::Event& event) = 0;

    virtual void initialize(GameWindow& gameWindow, AssetManager& assetManager) = 0;
    virtual void cleanup() = 0;

    virtual ~WindowState() {}
};

typedef std::unique_ptr<WindowState> windowState_ptr;

#endif //RAINSFORD_ENGINESTATE_HPP
