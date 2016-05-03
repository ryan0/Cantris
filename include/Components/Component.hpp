//
// Created by Ryan on 8/1/2015.
//

#ifndef RAINSFORD_COMPONENT_HPP
#define RAINSFORD_COMPONENT_HPP

#include <memory>
#include "selene.h"
#include "Core/AssetManager.hpp"

class Entity;
class Component {
    friend class Entity;
public:
    virtual void loadFromLua(sel::Selector& luaData, AssetManager& assetManagerRef, b2World& physicsSpace) {}
    virtual ~Component();

private:
    void setOwner(Entity* newOwner);
    Entity* owner;
};

typedef std::unique_ptr<Component> component_ptr;

#endif //RAINSFORD_COMPONENT_HPP