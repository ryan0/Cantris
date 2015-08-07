//
// Created by Ryan on 8/4/2015.
//

#include "Components/Movement.hpp"

void Movement::setVelocity(sf::Vector2f newVelocity) {
    velocity = newVelocity;
}

sf::Vector2 <float> Movement::getVelocity() {
    return velocity;
}