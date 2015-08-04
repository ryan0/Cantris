//
// Created by Ryan on 8/1/2015.
//

#ifndef RAINSFORD_PHYSICSCOMP_HPP
#define RAINSFORD_PHYSICSCOMP_HPP

#include <SFML/Graphics.hpp>

#include "Components/Component.hpp"

class PhysicsComp : public Component {
public:
    void setPosition(sf::Vector2f newPosition);
    sf::Vector2f getPosition();

    void setVelocity(sf::Vector2f newVelocity);
    sf::Vector2f getVelocity();

private:
    sf::Vector2f position;
    sf::Vector2f velocity;
};

#endif //RAINSFORD_PHYSICSCOMP_HPP