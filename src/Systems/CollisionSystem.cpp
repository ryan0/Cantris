//
// Created by Ryan on 8/10/2015.
//

#include <Components/Movable.hpp>
#include "Systems/CollisionSystem.hpp"
#include "Components/Collidable.hpp"
#include "Components/Collided.hpp"
#include "Components/Physical.hpp"
#include "Components/Spatial.hpp"
#include "Components/Movable.hpp"
#include <iostream>

void CollisionSystem::onNewEntity(Entity *entityRef) {

}

void CollisionSystem::update(float tpf, std::vector<std::unique_ptr<Entity>> &entities) {
    for(auto& e : entities) {
        e->removeComponent<Collided>();
        Collidable* collidableRef = e->getComponent<Collidable>();
        Spatial* spatialRef = e->getComponent<Spatial>();
        if(collidableRef && spatialRef) {
            for(auto& c : entities) {
                if(c != e) {
                    Collidable* collideCheckRef = c->getComponent<Collidable>();
                    Spatial* collideSpatialRef = c->getComponent<Spatial>();
                    if (collideCheckRef && collideSpatialRef) {
                        sf::FloatRect entityRect = collidableRef->getBounds();
                        entityRect.top += spatialRef->getPosition().y;
                        entityRect.left += spatialRef->getPosition().x;

                        sf::FloatRect collideCheckRect = collideCheckRef->getBounds();
                        collideCheckRect.top += collideSpatialRef->getPosition().y;
                        collideCheckRect.left += collideSpatialRef->getPosition().x;

                        sf::FloatRect intersection;
                        if (entityRect.intersects(collideCheckRect, intersection)) {
                            genCollided(*e, *c, intersection);
                        }
                    }
                }
            }
        }
    }
}


void CollisionSystem::genCollided(Entity &entity, Entity &collided, sf::FloatRect intersection) {
    if(!entity.hasComponent<Collided>()) {
        entity.addComponent(std::unique_ptr<Collided>(new Collided));
    }
    Collided* collisionData = entity.getComponent<Collided>();
    Collidable* collidedCollidable = entity.getComponent<Collidable>();
    Physical* collidedPhysical = collided.getComponent<Physical>();
    Spatial* collidedSpatial = collided.getComponent<Spatial>();
    Movable* collidedMovable = collided.getComponent<Movable>();

    collide_data collision;
    collision.bounds = collidedCollidable->getBounds();
    collision.intersection = intersection;
    collision.position = collidedSpatial->getPosition();
    collision.elasticity = collidedPhysical->getElasticity();
    collision.mass = collidedPhysical->getMass();
    if(collidedMovable) {
        collision.velocity = collidedMovable->getVelocity();
    }
    collisionData->addCollision(collision);
}
