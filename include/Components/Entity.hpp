//
// Created by Ryan on 8/1/2015.
//

#ifndef RAINSFORD_ENTITY_HPP
#define RAINSFORD_ENTITY_HPP

#include <SFML/Graphics.hpp>
#include <vector>

#include "Component.hpp"

class Entity {
public:
    void addComponent(component_ptr newComponent);

private:
    std::vector<component_ptr> components;
};

#endif //RAINSFORD_ENTITY_HPP