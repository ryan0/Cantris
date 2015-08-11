//
// Created by Ryan on 8/10/2015.
//

#include "Components/Physical.hpp"

void Physical::setElasticity(float newRestitude) {
    elasticity = newRestitude;
}

float Physical::getElasticity() {
    return elasticity;
}

void Physical::setMass(float newMass) {
    mass = newMass;
}

float Physical::getMass() {
    return mass;
}
