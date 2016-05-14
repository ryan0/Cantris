//
// Created by Ryan on 5/7/2016.
//

#include "Components/Scriptable.hpp"

void Scriptable::start(Entity* entity, Scene* scene, sel::State& luaState){
    for(const auto& scriptData : scriptInfo) {
        int scriptHandle = luaState["getScript"](scriptData.file, scriptData.parameters);
        luaState["startScript"](scriptHandle, entity, scene);
        scriptHandles.push_back(scriptHandle);
    }
    hasStarted = true;
}

void Scriptable::update(double timeStep, Entity* entity, Scene* scene, sel::State& luaState) {
    for(const auto& scriptHandle : scriptHandles) {
        luaState["updateScript"](scriptHandle, timeStep, entity, scene);
    }
}

bool Scriptable::started() {
    return hasStarted;
}

