//
// Created by Ryan on 5/1/2016.
//

#ifndef RAINSFORD_LUAENTITYLOADER_HPP
#define RAINSFORD_LUAENTITYLOADER_HPP

#include <string>
#include <memory>
#include <map>
#include <Box2D/Box2D.h>

#include "Entity.hpp"
#include "Components/Component.hpp"
#include "Core/AssetManager.hpp"

template<typename T> component_ptr createComponent() { return component_ptr(new T); }

class LuaEntityLoader {
public:
    LuaEntityLoader(AssetManager& assetManager, b2World& physicsSpace);
    std::unique_ptr<Entity> loadEntity(sel::Selector& luaData);

private:
    std::map<std::string, component_ptr(*)()> component_register;
    AssetManager& assetManagerRef;
    b2World& physicsSpaceRef;
};

#endif //RAINSFORD_ENTITYLOADERLUA_HPP
