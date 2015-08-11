//
// Created by Ryan on 8/1/2015.
//

#ifndef RAINSFORD_PHYSICSSPACE_HPP
#define RAINSFORD_PHYSICSSPACE_HPP

#include <Components/Collided.hpp>
#include "System.hpp"

class PhysicsSystem : public System {
public:
    virtual void onNewEntity(Entity *entityRef) override;
    virtual void update(float tpf, std::vector<std::unique_ptr<Entity>> &entities) override;

private:
    void handleCollide(Entity& entity, float tpf);

    sf::Vector2f gravity = sf::Vector2f(0, 100);
};

#endif //RAINSFORD_PHYSICSSPACE_HPP
