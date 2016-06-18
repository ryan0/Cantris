//
// Created by Ryan on 8/6/2015.
//

#include <Engine/LuaSceneLoader.hpp>
#include "Engine/Engine.hpp"

void Engine::update(double timeStep) {
    graphicsSystem.update(timeStep, scene->getEntities());
    physicsSystem.doPhysics(timeStep, scene->getPhysicsSpace());
    physicsSystem.update(timeStep, scene->getEntities());
    scriptSystem.update(timeStep, scene->getEntities(), scene.get());
    scene->getCamera().update(timeStep);
}

void Engine::render(double alpha, sf::RenderTarget &renderTarget) {
    gameWindowRef->makeLetterBox(scene->getCamera());
    scene->getCamera().updatePosition(alpha);
    renderTarget.setView(scene->getCamera());
    graphicsSystem.render(alpha, renderTarget, scene->getSceneGraph());
    graphicsSystem.renderDebug();
}


void Engine::handleEvents(sf::Event &event) {
    if(event.type == sf::Event::KeyPressed) {
        if(event.key.code == sf::Keyboard::Return) {
            gameWindowRef->setState(windowState_ptr(new Engine()));
        }
    }
}

void Engine::initialize(GameWindow &gameWindow, AssetManager &assetManager) {
    gameWindowRef = &gameWindow;
    assetManagerRef = &assetManager;
    LuaSceneLoader sceneLoader(assetManager);
    scene = (sceneLoader.loadScene("testScene.lua"));
    scene->getPhysicsSpace().SetContactListener(&physicsSystem);
    graphicsSystem.setDebugDraw(gameWindow, scene->getPhysicsSpace());
}

void Engine::cleanup() {

}
