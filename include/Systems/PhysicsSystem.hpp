//
// Created by Ryan on 8/1/2015.
//

#ifndef RAINSFORD_PHYSICSSPACE_HPP
#define RAINSFORD_PHYSICSSPACE_HPP

#include <Box2D/Box2D.h>
#include "System.hpp"

class PhysicsSystem : public System {
public:
    virtual void update(float tpf, std::vector<std::unique_ptr<Entity>> &entities) override;
    void doPhysics(float tpf, b2World& physicsSpace);

private:
    int32 velocityIterations = 8;
    int32 positionIterations = 3;
};

#endif //RAINSFORD_PHYSICSSPACE_HPP
