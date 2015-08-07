//
// Created by Ryan on 8/4/2015.
//

#include "Components/Movable.hpp"

void Movable::setVelocity(sf::Vector2f newVelocity) {
    velocity = newVelocity;
}

sf::Vector2 <float> Movable::getVelocity() {
    return velocity;
}