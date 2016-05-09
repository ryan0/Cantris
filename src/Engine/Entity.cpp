//
// Created by Ryan on 8/1/2015.
//

#include "Engine/Entity.hpp"

Entity::Entity() {
    static unsigned long int uId = 596636;
    id = std::to_string(++uId);
}

Entity::Entity(std::string uId) {
    id = uId;
}

std::string Entity::getId() {
    return id;
}

void Entity::addComponent(component_ptr newComponent) {
    newComponent->setOwner(this);
    std::type_index index(typeid(*newComponent.get()));
    components[index] = std::move(newComponent);
}
