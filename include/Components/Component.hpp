//
// Created by Ryan on 8/1/2015.
//

#ifndef RAINSFORD_COMPONENT_HPP
#define RAINSFORD_COMPONENT_HPP

#include <memory>

class Entity;
class Component {
    friend class Entity;
private:
    void setOwner(Entity* newOwner);
    Entity* owner;
};

typedef std::unique_ptr<Component> component_ptr;

#endif //RAINSFORD_COMPONENT_HPP
