//
// Created by Ryan on 8/5/2015.
//

#ifndef RAINSFORD_ENGINE_HPP
#define RAINSFORD_ENGINE_HPP

#include <vector>
#include <memory>

#include "Camera.hpp"
#include "Entity.hpp"
#include "Core/WindowState.hpp"
#include "Core/GameWindow.hpp"
#include "Systems/GraphicsSystem.hpp"
#include "Systems/MovementSystem.hpp"
#include "Systems/CollisionSystem.hpp"
#include "Systems/PhysicsSystem.hpp"
#include "Systems/PlayerController.hpp"

class Engine : public WindowState {
public:
    void addEntity(std::unique_ptr<Entity> newEntity);
    virtual void update(float tpf) override;
    virtual void render(sf::RenderTarget &target) override;
    virtual void handleEvents(sf::Event &event);
    virtual void initialize(GameWindow& gameWindow, AssetManager& assetManager) override;
    virtual void cleanup() override;

private:
    GameWindow* gameWindowRef;
    AssetManager* assetMangerRef;
    Camera camera;

    std::vector<std::unique_ptr<Entity>> entities;
    GraphicsSystem graphicsSystem;
    MovementSystem movementSystem;
    CollisionSystem collisionSystem;
    PhysicsSystem physicsSystem;
    PlayerController playerController;
};

#endif //RAINSFORD_ENGINE_HPP
