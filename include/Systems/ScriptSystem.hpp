//
// Created by Ryan on 5/7/2016.
//

#ifndef RAINSFORD_SCRIPTSYSTEM_HPP
#define RAINSFORD_SCRIPTSYSTEM_HPP

#include "selene.h"

class ScriptSystem {
public:
    void update(double timeStep, std::vector<std::unique_ptr<Entity>> &entities, Scene* scene);
    ScriptSystem();

private:
    sel::State luaState;
};

#endif //RAINSFORD_SCRIPTSYSTEM_HPP
