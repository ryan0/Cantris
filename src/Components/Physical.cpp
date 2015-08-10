//
// Created by Ryan on 8/10/2015.
//

#include "Components/Physical.hpp"

void Physical::setStatic(bool isStatic) {
    staticObj = isStatic;
}

bool Physical::isStatic() {
    return staticObj;
}

void Physical::setRestitude(float newRestitude) {
    restitude = newRestitude;
}

float Physical::getRestitude() {
    return restitude;
}

void Physical::setMass(float newMass) {
    mass = newMass;
}

float Physical::getMass() {
    return mass;
}
