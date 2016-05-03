//
// Created by Ryan on 8/6/2015.
//

#include "Engine/Engine.hpp"
#include "Engine/LuaEntityLoader.hpp"

void Engine::update(float tpf) {
    movementSystem.update(tpf, scene.getEntities());
    graphicsSystem.update(tpf, scene.getEntities());
    playerController.update(tpf, scene.getEntities());

    physicsSystem.doPhysics(tpf, scene. getPhysicsSpace());
    physicsSystem.update(tpf, scene.getEntities());

    scene.getCamera().updatePosition(tpf);
}

void Engine::render(sf::RenderTarget &renderTarget) {
    gameWindowRef->makeLetterBox(scene.getCamera());
    graphicsSystem.render(renderTarget, scene.getSceneGraph());
    graphicsSystem.renderDebug();
}


void Engine::handleEvents(sf::Event &event) {
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
        gameWindowRef->setState(windowState_ptr(new Engine()));
}

void Engine::initialize(GameWindow &gameWindow, AssetManager &assetManager) {
    gameWindowRef = &gameWindow;
    assetManagerRef = &assetManager;
    scene = Scene(assetManager);
    graphicsSystem.setDebugDraw(gameWindow, scene.getPhysicsSpace());
}

void Engine::cleanup() {

}
