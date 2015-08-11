//
// Created by Ryan on 8/8/2015.
//

#ifndef RAINSFORD_PHYSICAL_HPP
#define RAINSFORD_PHYSICAL_HPP

#include <SFML/Graphics/Rect.hpp>
#include "Component.hpp"



class Physical : public Component {
public:
    void setElasticity(float newRestitude);
    float getElasticity();

    void setMass(float newMass);
    float getMass();

private:
    float elasticity;
    float mass;
};

#endif //RAINSFORD_PHYSICAL_HPP
