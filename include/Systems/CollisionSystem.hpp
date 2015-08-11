//
// Created by Ryan on 8/1/2015.
//

#ifndef RAINSFORD_COLLISIONSPACE_HPP
#define RAINSFORD_COLLISIONSPACE_HPP

#include "System.hpp"

class CollisionSystem : public System {
public:
    virtual void onNewEntity(Entity *entityRef) override;
    virtual void update(float tpf, std::vector<std::unique_ptr<Entity>> &entities) override;

private:
    void genCollided(Entity& entity, Entity& collided, sf::FloatRect intersection);
};

#endif //RAINSFORD_COLLISIONSPACE_HPP
