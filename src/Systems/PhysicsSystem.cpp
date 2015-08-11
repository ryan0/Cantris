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
        sf::Vector2f center = sf::Vector2f(
                collidableRef->getBounds().left + spatialRef->getPosition().x - (collidableRef->getBounds().width / 2.0f),
                collidableRef->getBounds().top + spatialRef->getPosition().y - (collidableRef->getBounds().height / 2.0f));

        sf::Vector2f collideCenter = sf::Vector2f(
                collide.bounds.left + collide.position.x - (collide.bounds.width / 2.0f),
                collide.bounds.top + collide.position.y - (collide.bounds.height / 2.0f));


        sf::Vector2f displacement;
        bool VerticalCollide = false;

        if(collide.intersection.width > collide.intersection.height) {
            displacement.y = collide.intersection.height;
            if(center.y < collideCenter.y) {
                displacement.y *= -1;
            }
            VerticalCollide = true;
        }
        else {
            displacement.x = collide.intersection.width;
            if(center.x < collideCenter.x) {
                displacement.x *= -1;
            }
        }

        if(movableRef) {
            spatialRef->setPosition(spatialRef->getPosition() + displacement);
            sf::Vector2f velocity = movableRef->getVelocity();
            float elasticity = std::fmin(physicalRef->getElasticity(), collide.elasticity);
            if(VerticalCollide) {
                float newVel;
                if(collide.mass != 0) {
                    newVel = (((physicalRef->getMass() - collide.mass) * velocity.y) + (2.0f * collide.mass * collide.velocity.y * elasticity))
                             / (physicalRef->getMass() + collide.mass);
                }
                else {
                    newVel = velocity.y * -1 * elasticity;
                }
                movableRef->setVelocity(sf::Vector2f(velocity.x, newVel));
            }
            else {
                float newVel;
                if(collide.mass != 0) {
                    newVel = (((physicalRef->getMass() - collide.mass) * velocity.x) + (2.0f * collide.mass * collide.velocity.x * elasticity))
                             / (physicalRef->getMass() + collide.mass);
                }
                else {
                    newVel = velocity.x * -1 * elasticity;
                }
                movableRef->setVelocity(sf::Vector2f(newVel, velocity.y));
            }
        }
    }
}