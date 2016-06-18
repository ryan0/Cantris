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

void Scriptable::loadFromLua(sel::Selector& luaData, AssetManager& assetManagerRef, b2World& physicsSpace) {
    int count = 1;
    while(luaData[count] == true) {
        ScriptData scriptData;
        scriptData.parameters = "NO_PARAMETERS";
        std::string file = luaData[count]["script"];
        scriptData.file = file;
        if(luaData[count]["parameters"]) {
            std::string parameters = luaData[count]["parameters"];
            scriptData.parameters = parameters;
        }
        scriptInfo.push_back(scriptData);
        count++;
    }
}

