//
// Created by Ryan on 5/1/2016.
//

#include <iostream>
#include <selene/State.h>
#include <Components/Renderable.hpp>
#include <Components/Spatial.hpp>
#include <Components/Graphical.hpp>
#include <Components/Movable.hpp>
#include <Components/Physical.hpp>
#include <Components/PlayerControlled.hpp>
#include "Engine/LuaEntityLoader.hpp"
#include "Components/Animated.hpp"

LuaEntityLoader::LuaEntityLoader(AssetManager& assetManager, b2World& physicsSpace)
        : assetManagerRef(assetManager), physicsSpaceRef(physicsSpace)
{
    component_register["Animated"] = &createComponent<Animated>;
    component_register["Graphical"] = &createComponent<Graphical>;
    component_register["Movable"] = &createComponent<Movable>;
    component_register["Physical"] = &createComponent<Physical>;
    component_register["Renderable"] = &createComponent<Renderable>;
    component_register["Spatial"] = &createComponent<Spatial>;
}

std::unique_ptr<Entity> LuaEntityLoader::loadEntity(std::string luafile) {
    std::cout<<luafile<<std::endl;
    luafile = "../assets/" + luafile;

    sel::State luaState;
    luaState.Load(luafile);
    std::unique_ptr<Entity> entity(new Entity());


    for(auto const &it : component_register) {
        if(luaState[it.first.c_str()]) {
            std::cout << it.first << std::endl;

            component_ptr component(it.second());
            sel::Selector selector = luaState[it.first.c_str()];
            component->loadFromLua(selector, assetManagerRef, physicsSpaceRef);
            entity->addComponent(std::move(component));
        }
    }


    if(luaState["PlayerControlled"] == true) {
        std::unique_ptr<PlayerControlled> control(new PlayerControlled());
        entity->addComponent(std::move(control));
    }

    std::cout<<std::endl;
    return entity;
}
