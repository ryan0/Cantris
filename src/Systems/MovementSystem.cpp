//
// Created by Ryan on 8/7/2015.
//

#include <Components/Physical.hpp>
#include "Systems/MovementSystem.hpp"
#include "Components/Movable.hpp"
#include "Components/Spatial.hpp"
#include <iostream>

void MovementSystem::update(float tpf, std::vector<std::unique_ptr<Entity>>& entities) {
    for(auto& e : entities) {
        Movable* movableRef = e->getComponent<Movable>();
        Spatial* spatialRef = e->getComponent<Spatial>();

        if(movableRef && spatialRef) {
            spatialRef->move(movableRef->getVelocity() * tpf);
        }
    }
}
