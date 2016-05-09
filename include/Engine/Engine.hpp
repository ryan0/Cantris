//
// Created by Ryan on 8/5/2015.
//

#ifndef RAINSFORD_ENGINE_HPP
#define RAINSFORD_ENGINE_HPP

#include <vector>
#include <memory>
#include <map>

#include "Camera.hpp"
#include "Entity.hpp"
#include "Scene.hpp"
#include "Core/WindowState.hpp"
#include "Core/GameWindow.hpp"
#include "Systems/GraphicsSystem.hpp"
#include "Systems/PhysicsSystem.hpp"
#include "Systems/ScriptSystem.hpp"

class Engine : public WindowState {
public:
    virtual void update(double timeStep) override;
    virtual void render(double alpha, sf::RenderTarget &target) override;
    virtual void handleEvents(sf::Event &event) override ;
    virtual void initialize(GameWindow& gameWindow, AssetManager& assetManager) override;
    virtual void cleanup() override;

private:
    GameWindow* gameWindowRef;
    AssetManager* assetManagerRef;
    std::unique_ptr<Scene> scene;

    GraphicsSystem graphicsSystem;
    PhysicsSystem physicsSystem;
    ScriptSystem scriptSystem;
};

#endif //RAINSFORD_ENGINE_HPP
