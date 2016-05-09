//
// Created by Ryan on 5/3/2016.
//

#include <Box2D/Box2D.h>

#include "Engine/LuaSceneLoader.hpp"

LuaSceneLoader::LuaSceneLoader(AssetManager& assetManager) : assetManagerRef(assetManager) { }

std::unique_ptr<Scene> LuaSceneLoader::loadScene(std::string luafile) {
    std::cout<<luafile<<std::endl;
    luafile = "../lua/scenes/" + luafile;
    sel::State luaState{true};
    luaState.Load(luafile);

    b2Vec2 gravity;
    if(luaState["b2World"] == true) {
        sel::Selector selector = luaState["b2World"];
        if(selector["gravity"] == true) {
            float x = (float)double(selector["gravity"][1]);
            float y = (float)double(selector["gravity"][2]);
            gravity.Set(x, y);
        }
    }
    std::unique_ptr<b2World> physicsSpace(new b2World(gravity));


    std::unique_ptr<Scene> scene(new Scene(std::move(physicsSpace)));
    LuaEntityLoader entityLoader(assetManagerRef, scene->getPhysicsSpace());
    if(luaState["entities"] == true) {
        int count = 1;
        while(luaState["entities"][count] == true) {
            sel::Selector selector = luaState["entities"][count];
            scene->addEntity(entityLoader.loadEntity(selector));
            count++;
        }
    }

    if(luaState["Camera"] == true) {
        sel::Selector selector = luaState["Camera"];
        if(selector["size"] == true) {
            float x = (float)double(selector["size"][1]);
            float y = (float)double(selector["size"][2]);
            scene->getCamera().setSize(x, y);
        }
        if(selector["center"] == true) {
            float x = (float)double(selector["center"][1]);
            float y = (float)double(selector["center"][2]);
            scene->getCamera().setCenter(x, y);
        }
        if(selector["target"] == true) {
            std::string str = selector["target"];
            Entity* target = scene->getEntity(str);
            if(target) scene->getCamera().follow(*target);
        }
    }

    return scene;
}

