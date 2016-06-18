//
// Created by Ryan on 8/1/2015.
//

#ifndef RAINSFORD_PHYSICSSPACE_HPP
#define RAINSFORD_PHYSICSSPACE_HPP

#include <Box2D/Box2D.h>
#include "Engine/Entity.hpp"

class PhysicsSystem : public b2ContactListener {
public:
    void update(double timeStep, std::vector<std::unique_ptr<Entity>> &entities);
    void doPhysics(double timeStep, b2World& physicsSpace);

    /// Called when two fixtures begin to touch.
    virtual void BeginContact(b2Contact* contact) override;
    /// Called when two fixtures cease to touch.
    virtual void EndContact(b2Contact* contact) override;

private:
    const int32 velocityIterations = 8;
    const int32 positionIterations = 4;
};

#endif //RAINSFORD_PHYSICSSPACE_HPP
