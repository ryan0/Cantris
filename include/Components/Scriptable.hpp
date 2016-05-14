//
// Created by Ryan on 5/7/2016.
//

#ifndef RAINSFORD_SCRIPTABLE_HPP
#define RAINSFORD_SCRIPTABLE_HPP

#include <memory>
#include <string>
#include "selene.h"
#include "Component.hpp"
#include "Engine/Entity.hpp"
#include "Engine/Scene.hpp"

class Scriptable : public Component {
public:
    virtual void loadFromLua(sel::Selector& luaData, AssetManager& assetManagerRef, b2World& physicsSpace) override;
    void start(Entity* entity, Scene* scene, sel::State& luaState);
    void update(double timeStep, Entity* entity, Scene* scene, sel::State& luaState);
    bool started();

private:
    struct ScriptData {
        std::string file;
        std::string parameters;
    };

    std::vector<ScriptData> scriptInfo;
    std::vector<int> scriptHandles;
    bool hasStarted = false;
};

#endif //RAINSFORD_SCRIPTABLE_HPP
