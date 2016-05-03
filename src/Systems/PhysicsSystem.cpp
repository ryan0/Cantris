//
// Created by Ryan on 8/8/2015.
//

#include "Systems/PhysicsSystem.hpp"
#include "Components/Physical.hpp"
#include "Components/Movable.hpp"
#include "Components/Spatial.hpp"
#include "math.h"

void PhysicsSystem::update(float tpf, std::vector<std::unique_ptr<Entity>> &entities) {
    for(auto& e : entities) {
        Physical* physicalRef = e->getComponent<Physical>();
        Movable* movableRef = e->getComponent<Movable>();
        Spatial* spatialRef = e->getComponent<Spatial>();

        if(physicalRef && movableRef && spatialRef) {
            float angle = physicalRef->getBodyRef().GetAngle();
            b2Vec2 pos = physicalRef->getBodyRef().GetPosition();
            b2Vec2 velocity = physicalRef->getBodyRef().GetLinearVelocity();

            spatialRef->setRotation(angle * (180.0f / 3.14159265359));
            spatialRef->setPosition(sf::Vector2f(pos.x, pos.y));
            movableRef->setVelocity(sf::Vector2f(velocity.x, velocity.y));
        }
    }
}

void PhysicsSystem::doPhysics(float tpf, b2World& physicsSpace) {
    physicsSpace.Step(tpf, velocityIterations, positionIterations);
}