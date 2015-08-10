//
// Created by Ryan on 8/1/2015.
//

#ifndef RAINSFORD_ENTITY_HPP
#define RAINSFORD_ENTITY_HPP

#include <SFML/Graphics.hpp>
#include <unordered_map>
#include <typeindex>
#include <memory>

#include "Components/Component.hpp"
#include "Messages/Message.hpp"

class Entity {
public:
    void addComponent(component_ptr newComponent);
    template <typename T> bool hasComponent();
    template <typename T> T* getComponent();
    template <typename T> void removeComponent();

private:
    std::unordered_map<std::type_index, component_ptr> components;
};


template<typename T> bool Entity::hasComponent() {
    std::type_index index(typeid(T));
    return components.find(index) != components.end();
}

template<typename T> T* Entity::getComponent() {
    std::type_index index(typeid(T));
    if(hasComponent<T>()) {
        return static_cast<T*>(components[index].get());
    }
    else {
        return nullptr;
    }
}

template <typename T> void Entity::removeComponent() {
    std::type_index index(typeid(T));
    if(hasComponent<T>()) {
        components.erase(index);
    }
}

#endif //RAINSFORD_ENTITY_HPP