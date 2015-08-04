//
// Created by Ryan on 8/4/2015.
//

#include "Components/PhysicsComp.hpp"

void PhysicsComp::setPosition(sf::Vector2f newPosition) {
    position = newPosition;
}

sf::Vector2 <float> PhysicsComp::getPosition() {
    return position;
}

void PhysicsComp::setVelocity(sf::Vector2f newVelocity) {
    velocity = newVelocity;
}

sf::Vector2 <float> PhysicsComp::getVelocity() {
    return velocity;
}