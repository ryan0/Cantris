//
// Created by Ryan on 7/31/2015.
//

#ifndef RAINSFORD_GAME_HPP
#define RAINSFORD_GAME_HPP

#include "System/EngineState.hpp"

class Game : public EngineState {
public:
    virtual void update(float tpf) override;
    virtual void render(sf::RenderTarget &target) override;
    virtual void initialize(Engine& engine, GameWindow& gameWindow) override;
    virtual void cleanup() override;

private:
    Engine* engineRef;
};

#endif //RAINSFORD_GAME_HPP