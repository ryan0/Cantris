//
// Created by Ryan on 5/1/2016.
//

#include "Engine/Scene.hpp"
#include "Components/Renderable.hpp"
#include "Components/Spatial.hpp"
#include "Engine/LuaEntityLoader.hpp"

Scene::Scene() {}

Scene::Scene(AssetManager& assetManager) {
    physicsSpace.reset(new b2World(b2Vec2(0.0f, 10.0f)));

    LuaEntityLoader luaLoader(assetManager, *physicsSpace);
    std::unique_ptr<Entity> player = luaLoader.loadEntity("demo/luaEntities/rainsford.lua");
    camera = Camera();
    camera.follow(*player);
    camera.setSize(sf::Vector2f(64, 36));

    addEntity(std::move(player));
    addEntity(luaLoader.loadEntity("demo/luaEntities/background.lua"));
    addEntity(luaLoader.loadEntity("demo/luaEntities/floor.lua"));
    addEntity(luaLoader.loadEntity("demo/luaEntities/testCollidable1.lua"));
    addEntity(luaLoader.loadEntity("demo/luaEntities/testCollidable2.lua"));
    addEntity(luaLoader.loadEntity("demo/luaEntities/box1.lua"));
    addEntity(luaLoader.loadEntity("demo/luaEntities/box2.lua"));
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

Camera& Scene::getCamera() {
    return camera;
}

b2World& Scene::getPhysicsSpace() {
    return *physicsSpace;
}