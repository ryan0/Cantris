//
// Created by Ryan on 5/1/2015.
//

#ifndef RAINSFORD_SCENE_HPP
#define RAINSFORD_SCENE_HPP

#include <Box2D/Box2D.h>
#include <vector>
#include <memory>
#include "Core/AssetManager.hpp"
#include "Camera.hpp"
#include "Entity.hpp"

class Scene {
public:
    Scene();
    Scene(AssetManager& assetManager);
    void addEntity(std::unique_ptr<Entity> newEntity);

    std::vector<std::unique_ptr<Entity>>& getEntities();
    std::multimap<float, Entity*>& getSceneGraph();
    b2World& getPhysicsSpace();
    Camera& getCamera();

private:
    std::vector<std::unique_ptr<Entity>> entities;
    std::multimap<float, Entity*> sceneGraph;
    std::unique_ptr<b2World> physicsSpace;
    Camera camera;
};

#endif //RAINSFORD_SCENE_HPP