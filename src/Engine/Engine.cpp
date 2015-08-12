//
// Created by Ryan on 8/6/2015.
//

#include "Engine/Engine.hpp"
#include "Engine/EntityLoader.hpp"

void Engine::addEntity(std::unique_ptr<Entity> newEntity) {
    graphicsSystem.onNewEntity(newEntity.get());
    entities.push_back(std::move(newEntity));
}

void Engine::update(float tpf) {
    collisionSystem.update(tpf, entities);
    physicsSystem.update(tpf, entities);
    movementSystem.update(tpf, entities);
    graphicsSystem.update(tpf, entities);
    playerController.update(tpf, entities);

    camera.updatePosition(tpf);
}

void Engine::render(sf::RenderTarget &renderTarget) {
    gameWindowRef->makeLetterBox(camera);
    graphicsSystem.render(renderTarget);
}


void Engine::handleEvents(sf::Event &event) {

}

void Engine::initialize(GameWindow &gameWindow, AssetManager &assetManager) {
    gameWindowRef = &gameWindow;
    assetMangerRef = &assetManager;
    EntityLoader entityLoader(*assetMangerRef);

    std::unique_ptr<Entity> player = entityLoader.loadEntity("rainsford.dat");
    camera.follow(*player);
    camera.setSize(sf::Vector2f(128, 72));
    gameWindowRef->makeLetterBox(camera);

    addEntity(std::move(player));
    addEntity(entityLoader.loadEntity("box1.dat"));
    addEntity(entityLoader.loadEntity("box3.dat"));
    addEntity(entityLoader.loadEntity("floor.dat"));
    addEntity(entityLoader.loadEntity("wall1.dat"));
    addEntity(entityLoader.loadEntity("wall2.dat"));
}

void Engine::cleanup() {

}
