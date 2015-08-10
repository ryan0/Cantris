//
// Created by Ryan on 8/6/2015.
//

#include "Engine/Engine.hpp"

void Engine::addEntity(std::unique_ptr<Entity> newEntity) {
    graphicsSystem.onNewEntity(newEntity.get());
    entities.push_back(std::move(newEntity));
}

void Engine::update(float tpf) {
    movementSystem.update(tpf, entities);
    graphicsSystem.update(tpf, entities);
    physicsSystem.update(tpf, entities);
}

void Engine::render(sf::RenderTarget &renderTarget) {
    graphicsSystem.render(renderTarget);
}
