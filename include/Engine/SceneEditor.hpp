//
// Created by Ryan on 5/26/2016.
//

#ifndef RAINSFORD_SCENEEDITOR_HPP
#define RAINSFORD_SCENEEDITOR_HPP

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
#include "GUI/StringSelector.hpp"

class SceneEditor : public WindowState {
public:
    virtual void update(double timeStep) override;
    virtual void render(double alpha, sf::RenderTarget &target) override;
    virtual void handleEvents(sf::Event &event) override ;
    virtual void initialize(GameWindow& gameWindow, AssetManager& assetManager) override;
    virtual void cleanup() override;

    void saveSceneData();

private:
    GameWindow* gameWindowRef;
    AssetManager* assetManagerRef;
    std::unique_ptr<Scene> scene;
    GraphicsSystem graphicsSystem;

    sf::CircleShape selectedIndicator;
    StringSelector entitySelector;
    sf::Font openSans;

    float cameraSpeed = .04f;
    sf::Vector2f mouseDragDelta;
};

#endif //RAINSFORD_SCENEEDITOR_HPP
