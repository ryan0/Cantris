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
}

void Engine::render(double alpha, sf::RenderTarget &renderTarget) {
    scene->getCamera().updatePosition(alpha);
    renderTarget.setView(scene->getCamera());
    graphicsSystem.render(alpha, renderTarget, scene->getSceneGraph());
    //graphicsSystem.renderDebug();
}


void Engine::handleEvents(sf::Event &event) {
    if(event.type == sf::Event::KeyPressed) {
        if(event.key.code == sf::Keyboard::Return) {
            gameWindowRef->setState(windowState_ptr(new Engine()));
        }
    }
}

void Engine::initialize(GameWindow &gameWindow, AssetManager &assetManager) {
    static int count = 0;
    std::cout<<"Reloads"<< count<<std::endl;
    count++;

    gameWindowRef = &gameWindow;
    assetManagerRef = &assetManager;
    LuaSceneLoader sceneLoader(assetManager);
    scene = (sceneLoader.loadScene("testScene.lua"));
    graphicsSystem.setDebugDraw(gameWindow, scene->getPhysicsSpace());
    gameWindowRef->makeLetterBox(scene->getCamera());
}

void Engine::cleanup() {

}
