//
// Created by Ryan on 7/31/2015.
//

#ifndef RAINSFORD_GAME_HPP
#define RAINSFORD_GAME_HPP

#include "Core/WindowState.hpp"

class Game : public WindowState {
public:
    virtual void update(float tpf) override;
    virtual void render(sf::RenderTarget &target) override;
    virtual void handleEvents(sf::Event &event);
    virtual void initialize(GameWindow& gameWindow, AssetManager& assetManager) override;
    virtual void cleanup() override;

private:
    GameWindow* gameWindowRef;
};

#endif //RAINSFORD_GAME_HPP