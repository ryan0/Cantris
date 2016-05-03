//
// Created by Ryan on 8/5/2015.
//

#ifndef RAINSFORD_SYSTEM_HPP
#define RAINSFORD_SYSTEM_HPP

#include <memory>
#include "Engine/Entity.hpp"

class System {
public:
    virtual void update(float tpf, std::vector<std::unique_ptr<Entity>>& entities) = 0;
    virtual ~System() {}
};

#endif //RAINSFORD_SYSTEM_HPP
