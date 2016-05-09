//
// Created by Ryan on 5/1/2016.
//

#include <iostream>
#include <selene/State.h>
#include <Components/Renderable.hpp>
#include <Components/Spatial.hpp>
#include <Components/Graphical.hpp>
#include <Components/Physical.hpp>
#include <Components/Scriptable.hpp>
#include <Components/Animator.hpp>
#include "Engine/LuaEntityLoader.hpp"
#include "Components/Animated.hpp"

LuaEntityLoader::LuaEntityLoader(AssetManager& assetManager, b2World& physicsSpace)
        : assetManagerRef(assetManager), physicsSpaceRef(physicsSpace)
{
    component_register["Animated"] = &createComponent<Animated>;
    component_register["Graphical"] = &createComponent<Graphical>;
    component_register["Animator"] = &createComponent<Animator>;
    component_register["Physical"] = &createComponent<Physical>;
    component_register["Renderable"] = &createComponent<Renderable>;
    component_register["Spatial"] = &createComponent<Spatial>;
    component_register["Scriptable"] = &createComponent<Scriptable>;
}

std::unique_ptr<Entity> LuaEntityLoader::loadEntity(sel::Selector& luaData) {
    std::unique_ptr<Entity> entity;
    if(luaData["id"]) {
        std::string id = luaData["id"];
        entity.reset(new Entity(id));
    }
    else {
        entity.reset(new Entity());
    }

    for(auto const &it : component_register) {
        if(luaData[it.first.c_str()]) {
            std::cout << it.first << std::endl;
            component_ptr component(it.second());
            sel::Selector selector = luaData[it.first.c_str()];
            component->loadFromLua(selector, assetManagerRef, physicsSpaceRef);
            entity->addComponent(std::move(component));
        }
    }

    std::cout<<std::endl;
    return entity;
}

