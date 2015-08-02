//
// Created by Ryan on 8/1/2015.
//

#ifndef RAINSFORD_ENTITY_HPP
#define RAINSFORD_ENTITY_HPP

#include <SFML/Graphics.hpp>

class Entity {
public:
    virtual void update(float tpf) = 0;
    const sf::Vector2f& getPosition();

    virtual ~Entity() {}

protected:
    sf::Vector2f position;
};

#endif //RAINSFORD_ENTITY_HPP