//
// Created by Ryan on 8/8/2015.
//

#include "Systems/PhysicsSystem.hpp"
#include "Components/Physical.hpp"
#include "Components/Spatial.hpp"

void PhysicsSystem::update(double timeStep, std::vector<std::unique_ptr<Entity>> &entities) {
    for(auto& e : entities) {
        Physical* physicalRef = e->getComponent<Physical>();
        Spatial* spatialRef = e->getComponent<Spatial>();

        if(physicalRef && spatialRef) {
            float angle = physicalRef->getBodyRef().GetAngle();
            b2Vec2 pos = physicalRef->getBodyRef().GetPosition();
            b2Vec2 velocity = physicalRef->getBodyRef().GetLinearVelocity();

            spatialRef->setRotation(angle * (180.0f / 3.14159265359f));
            spatialRef->setPosition(sf::Vector2f(pos.x, pos.y));
        }
    }
}

void PhysicsSystem::doPhysics(double timeStep, b2World& physicsSpace) {
    physicsSpace.Step(timeStep, velocityIterations, positionIterations);
}