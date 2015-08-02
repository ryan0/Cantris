//
// Created by Ryan on 8/1/2015.
//

#ifndef RAINSFORD_COMPONENT_HPP
#define RAINSFORD_COMPONENT_HPP

#include "System/Entity.hpp"

class Component {
public:
    Component(Entity& entity);

private:
    Entity& ownerRef;
};

#endif //RAINSFORD_COMPONENT_HPP
