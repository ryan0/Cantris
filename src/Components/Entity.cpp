//
// Created by Ryan on 8/1/2015.
//

#include "Components/Entity.hpp"


void Entity::addComponent(component_ptr newComponent) {
    newComponent->setOwner(this);
    components.push_back(std::move(newComponent));
}
