//
// Created by Ryan on 8/8/2015.
//

#include "Systems/PhysicsSystem.hpp"
#include "Components/Physical.hpp"
#include "Components/Movable.hpp"
#include "Components/Spatial.hpp"

void PhysicsSystem::onNewEntity(Entity *entityRef) {

}

void PhysicsSystem::update(float tpf, std::vector<std::unique_ptr<Entity>> &entities) {
    for(auto& e : entities) {
        Physical* physicalRef = e->getComponent<Physical>();
        Movable* movableRef = e->getComponent<Movable>();
        Spatial* spatialRef = e->getComponent<Spatial>();

        if(physicalRef && movableRef && spatialRef) {
            movableRef->accelerate(gravity * tpf);
        }
    }
}
