//
// Created by Ryan on 8/12/2015.
//

#ifndef RAINSFORD_PLAYERCONTROLLER_HPP
#define RAINSFORD_PLAYERCONTROLLER_HPP

#include "System.hpp"

class PlayerController : public System {
public:
    virtual void onNewEntity(Entity *entityRef);
    virtual void update(float tpf, std::vector<std::unique_ptr<Entity>> &entities);
};

#endif //RAINSFORD_PLAYERCONTROLLER_HPP
