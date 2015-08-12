//
// Created by Ryan on 8/8/2015.
//

#include "Systems/PhysicsSystem.hpp"
#include "Components/Physical.hpp"
#include "Components/Movable.hpp"
#include "Components/Spatial.hpp"
#include "Components/Collidable.hpp"
#include "Components/Collided.hpp"
#include <iostream>

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

        if(e->hasComponent<Collided>()) {
            handleCollide(*e, tpf);
        }
    }
}

void PhysicsSystem::handleCollide(Entity &entity, float tpf) {
    Collidable* collidableRef = entity.getComponent<Collidable>();
    Collided* collidedRef = entity.getComponent<Collided>();
    Spatial* spatialRef = entity.getComponent<Spatial>();
    Movable* movableRef = entity.getComponent<Movable>();
    Physical* physicalRef = entity.getComponent<Physical>();

    for(const auto& collide : collidedRef->getCollisions()) {
        if(collide.mass == 0 && movableRef) {
            sf::Vector2f center = sf::Vector2f(
                    collidableRef->getBounds().left + spatialRef->getPosition().x - (collidableRef->getBounds().width / 2.0f),
                    collidableRef->getBounds().top + spatialRef->getPosition().y - (collidableRef->getBounds().height / 2.0f));

            sf::Vector2f collideCenter = sf::Vector2f(
                    collide.bounds.left + collide.position.x - (collide.bounds.width / 2.0f),
                    collide.bounds.top + collide.position.y - (collide.bounds.height / 2.0f));

            float friction = std::fmax(1.0f - physicalRef->getFriction(), 1.0f - collide.friction);
            float elasticity = std::fmin(physicalRef->getElasticity(), collide.elasticity);
            sf::Vector2f velocity(movableRef->getVelocity());
            sf::Vector2f displacement;

            if(collide.intersection.width > collide.intersection.height) {
                displacement.y = collide.intersection.height;
                velocity.y = std::abs(velocity.y) * elasticity;
                if(center.y < collideCenter.y) {
                    displacement.y *= -1.0f;
                    velocity.y *= -1.0f;
                }
                velocity.x *= friction;
            }
            else {
                displacement.x = collide.intersection.width;
                velocity.x = std::abs(velocity.y) * elasticity;
                if(center.x < collideCenter.x) {
                    displacement.x *= -1;
                    velocity.x *= -1.0f;
                }
                velocity.y *= friction;
            }
            movableRef->setVelocity(velocity);
            spatialRef->move(displacement);
        }
    }
}