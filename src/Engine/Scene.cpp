//
// Created by Ryan on 5/1/2016.
//

#include "Engine/Scene.hpp"
#include "Components/Renderable.hpp"
#include "Components/Spatial.hpp"
#include "Engine/LuaEntityLoader.hpp"

Scene::Scene() {}

Scene::Scene(std::unique_ptr<b2World> newPhysicsSpace)
        : physicsSpace(std::move(newPhysicsSpace)) { }

Scene::Scene(AssetManager& assetManager) {

}

void Scene::addEntity(std::unique_ptr<Entity> newEntity) {
    if(newEntity->hasComponent<Renderable>() && newEntity->hasComponent<Spatial>()) {
        Renderable* graphic = newEntity->getComponent<Renderable>();
        sceneGraph.insert(std::pair<float, Entity*>(graphic->getZValue(), newEntity.get()));
    }

    entities.push_back(std::move(newEntity));
}

std::vector<std::unique_ptr<Entity>>& Scene::getEntities() {
    return  entities;
}

std::multimap<float, Entity*>& Scene::getSceneGraph() {
    return  sceneGraph;
}

Entity* Scene::getEntity(std::string id) {
    for (auto& it : entities) {
        if(it->getId() == id) {
            return it.get();
        }
    }
    return nullptr;
}

Camera& Scene::getCamera() {
    return camera;
}

b2World& Scene::getPhysicsSpace() {
    return *physicsSpace;
}