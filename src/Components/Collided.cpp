//
// Created by Ryan on 8/10/2015.
//

#include "Components/Collided.hpp"

const std::vector<collide_data> &Collided::getCollisions() {
    return collisions;
}

void Collided::addCollision(const collide_data &newCollide) {
    collisions.push_back(newCollide);
}

void Collided::setCollisions(std::vector<collide_data> &collisionData) {
    collisions = collisionData;
}
