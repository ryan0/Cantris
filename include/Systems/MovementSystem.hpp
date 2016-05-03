//
// Created by Ryan on 8/7/2015.
//

#ifndef RAINSFORD_MOVEMENTSYSTEM_HPP
#define RAINSFORD_MOVEMENTSYSTEM_HPP

#include "System.hpp"

class MovementSystem : public System {
public:
    virtual void update(float tpf, std::vector<std::unique_ptr<Entity>>& entities) override;
};

#endif //RAINSFORD_MOVEMENTSYSTEM_HPP
