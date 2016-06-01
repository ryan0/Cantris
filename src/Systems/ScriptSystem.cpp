//
// Created by Ryan on 5/7/2016.
//

#include "Components/Scriptable.hpp"
#include "Engine/Scene.hpp"
#include "Engine/Entity.hpp"
#include "Systems/ScriptSystem.hpp"
#include "Engine/LuaBindings.hpp"

void ScriptSystem::update(double timeStep, std::vector<std::unique_ptr<Entity>> &entities, Scene* scene) {
    for (auto& e : entities) {
        Scriptable* scriptable = e->getComponent<Scriptable>();
        if(scriptable) {
            if(scriptable->started()) {
                scriptable->update(timeStep, e.get(), scene, luaState);
            }
            else {
                scriptable->start(e.get(), scene, luaState);
            }
        }
    }

    luaState("collectgarbage()");
}



ScriptSystem::ScriptSystem() {
    luaState = sel::State{true};
    luaState.Load("../lua/scripts/getScript.lua");

    luaState["Vector"].SetClass<lua::Vector>(
            "x", &lua::Vector::x,
            "y", &lua::Vector::y
    );

    luaState["print"] = &lua::print;
    luaState["isKeyPressed"] = &lua::isKeyPressed;

    luaState["getEntityById"] = &lua::getEntityById;

    luaState["getPosition"] = &lua::getPosition;
    luaState["getRotation"] = &lua::getRotation;
    luaState["getScale"] = &lua::getScale;
    luaState["move"] = &lua::move;
    luaState["rotate"] = &lua::rotate;
    luaState["scale"] = &lua::scale;
    luaState["setPosition"] = &lua::setPosition;
    luaState["setRotation"] = &lua::setRotation;
    luaState["setScale"] = &lua::setScale;

    luaState["getLocalCenter"] = &lua::getLocalCenter;
    luaState["getVelocity"] = &lua::getVelocity;
    luaState["setPhysicalPosition"] = &lua::setPhysicalPosition;
    luaState["applyLinearImpulse"] = &lua::applyLinearImpulse;
    luaState["applyForceToCenter"] = &lua::applyForceToCenter;

    luaState["setCurrentAnimation"] = &lua::setCurrentAnimation;
    luaState["getCurrentAnimation"] = &lua::getCurrentAnimation;
    luaState["getCurrentAnimationName"] = &lua::getCurrentAnimationName;
    luaState["play"] = &lua::play;
    luaState["pause"] = &lua::pause;
    luaState["stop"] = &lua::stop;
    luaState["setLooped"] = &lua::setLooped;
    luaState["isLooped"] = &lua::isLooped;
    luaState["isPlaying"] = &lua::isPlaying;
}