//
// Created by Ryan on 8/6/2015.
//

#include "Engine/Engine.hpp"

void Engine::addEntity(std::unique_ptr<Entity> newEntity) {
    entities.push_back(std::move(newEntity));
}

void Engine::update(float tpf) {

}

void Engine::render(sf::RenderTarget &renderTarget) {
    graphicsSystem.render(renderTarget, entities);
}
