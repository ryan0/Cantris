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
#include "Systems/MovementSystem.hpp"
#include "Systems/PhysicsSystem.hpp"
#include "Systems/PlayerController.hpp"

class Engine : public WindowState {
public:
    virtual void update(float tpf) override;
    virtual void render(sf::RenderTarget &target) override;
    virtual void handleEvents(sf::Event &event) override ;
    virtual void initialize(GameWindow& gameWindow, AssetManager& assetManager) override;
    virtual void cleanup() override;

private:
    GameWindow* gameWindowRef;
    AssetManager* assetManagerRef;
    Scene scene;

    GraphicsSystem graphicsSystem;
    MovementSystem movementSystem;
    PhysicsSystem physicsSystem;
    PlayerController playerController;
};

#endif //RAINSFORD_ENGINE_HPP
