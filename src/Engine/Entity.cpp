//
// Created by Ryan on 8/1/2015.
//

#include "Engine/Entity.hpp"


void Entity::addComponent(component_ptr newComponent) {
    newComponent->setOwner(this);
    std::type_index index(typeid(*newComponent.get()));
    components[index] = std::move(newComponent);
}
