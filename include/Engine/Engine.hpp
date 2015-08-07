//
// Created by Ryan on 8/5/2015.
//

#ifndef RAINSFORD_ENGINE_HPP
#define RAINSFORD_ENGINE_HPP

#include <vector>
#include <memory>

#include "Systems/GraphicsSystem.hpp"
#include "Systems/MovementSystem.hpp"
#include "Systems/CollisionSystem.hpp"
#include "Systems/PhysicsSystem.hpp"
#include "Entity.hpp"

class Engine {
public:
    void update(float tpf);
    void render(sf::RenderTarget& renderTarget);
    void addEntity(std::unique_ptr<Entity> newEntity);

private:
    std::vector<std::unique_ptr<Entity>> entities;
    GraphicsSystem graphicsSystem;
    MovementSystem movementSystem;

};

#endif //RAINSFORD_ENGINE_HPP
