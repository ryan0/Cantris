//
// Created by Ryan on 8/8/2015.
//

#ifndef RAINSFORD_PHYSICAL_HPP
#define RAINSFORD_PHYSICAL_HPP

#include <SFML/Graphics/Rect.hpp>
#include "Component.hpp"



class Physical : public Component {
public:
    void setStatic(bool isStatic);
    bool isStatic();

    void setRestitude(float newRestitude);
    float getRestitude();

    void setMass(float newMass);
    float getMass();

private:
    bool staticObj;
    float restitude;
    float mass;
};

#endif //RAINSFORD_PHYSICAL_HPP
