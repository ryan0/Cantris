//
// Created by Ryan on 7/31/2015.
//

#ifndef RAINSFORD_ENGINESTATE_HPP
#define RAINSFORD_ENGINESTATE_HPP

#include <SFML/Graphics.hpp>

class Engine;
class EngineState {
public:
    virtual void update(float tpf) = 0;
    virtual void render(sf::RenderTarget& target) = 0;

    virtual void initialize(Engine& engine) = 0;
    virtual void cleanup() = 0;

    virtual ~EngineState() {}
};


#endif //RAINSFORD_ENGINESTATE_HPP
