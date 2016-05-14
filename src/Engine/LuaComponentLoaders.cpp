//
// Created by Ryan on 5/1/2016.
//

#include <Components/Animator.hpp>
#include "Components/Animated.hpp"
#include "Components/Physical.hpp"
#include "Components/Renderable.hpp"
#include "Components/Graphical.hpp"
#include "Components/Spatial.hpp"
#include "Components/Scriptable.hpp"


void Renderable::loadFromLua(sel::Selector& luaData, AssetManager& assetManagerRef, b2World& physicsSpace) {
    if(luaData["zValue"] == true) {
        zValue = (float)double(luaData["zValue"]);
    }
}

void Graphical::loadFromLua(sel::Selector& luaData, AssetManager& assetManagerRef, b2World& physicsSpace) {
    if(luaData["texture"] == true) {
        std::string textureFile = luaData["texture"];
        setTexture(assetManagerRef.getTexture(textureFile));
    }
    if(luaData["textureRect"] == true) {
        int x1 = luaData["textureRect"][1];
        int y1 = luaData["textureRect"][2];
        int x2 = luaData["textureRect"][3];
        int y2 = luaData["textureRect"][4];
        setTextureRect(sf::IntRect(x1, y1, x2, y2));
    }
    if(luaData["position"] == true) {
        float x = (float)double(luaData["position"][1]);
        float y = (float)double(luaData["position"][2]);
        setPosition(x, y);
    }
    if(luaData["scale"] == true) {
            float v = (float) double(luaData["scale"]);
            std::cout<<v;
            setScale(v, v);
    }
}

void Animated::loadFromLua(sel::Selector& luaData, AssetManager& assetManagerRef, b2World& physicsSpace) {
    if(luaData["animation"] == true) {
        sel::Selector selector = luaData["animation"];
        std::string name = selector["name"];
        std::string file = selector["file"];
        setAnimation(assetManagerRef.getAnimation(file, name));
    }
    if(luaData["frametime"] == true) {
        float time = (float)double(luaData["frametime"]);
        setFrameTime(sf::seconds(time));
    }
    if(luaData["position"] == true) {
        float x = (float)double(luaData["position"][1]);
        float y = (float)double(luaData["position"][2]);
        setPosition(x, y);
    }
}

void Animator::loadFromLua(sel::Selector& luaData, AssetManager& assetManagerRef, b2World& physicsSpace) {
    if(luaData["animations"] == true) {
        int count = 1;
        while(luaData["animations"][count] == true) {
            std::string name = luaData["animations"][count][1];
            std::string file = luaData["animations"][count][2];
            AnimatedSprite animation;
            animation.setAnimation(assetManagerRef.getAnimation(file, name));
            addAnimation(name, animation);
            setCurrentAnimation(name);
            count++;
        }
    }
    if(luaData["position"] == true) {
        float x = (float)double(luaData["position"][1]);
        float y = (float)double(luaData["position"][2]);
        setPosition(x, y);
    }
}

void Spatial::loadFromLua(sel::Selector& luaData, AssetManager& assetManagerRef, b2World& physicsSpace) {
    if(luaData["position"] == true) {
        float x = (float)double(luaData["position"][1]);
        float y = (float)double(luaData["position"][2]);
        setPosition(x, y);
    }
    if(luaData["origin"] == true) {
        float x = (float)double(luaData["origin"][1]);
        float y = (float)double(luaData["origin"][2]);
        setOrigin(x, y);
    }
}

void Physical::loadFromLua(sel::Selector& luaData, AssetManager& assetManagerRef, b2World& physicsSpace) {
    b2BodyDef bodyDef;

    if(luaData["b2BodyDef"] == true) {
        sel::Selector selector = luaData["b2BodyDef"];
        bodyDef = loadLuaBodyDef(selector);
        b2BodyRef = physicsSpace.CreateBody(&bodyDef);

        if(luaData["b2FixtureDef"] == true) {
            sel::Selector selector = luaData["b2FixtureDef"];
            createLuaFixture(selector);
        }
    }
}

void Scriptable::loadFromLua(sel::Selector& luaData, AssetManager& assetManagerRef, b2World& physicsSpace) {
    int count = 1;
    while(luaData[count] == true) {
        ScriptData scriptData;
        scriptData.parameters = "NO_PARAMETERS";
        std::string file = luaData[count]["script"];
        scriptData.file = file;
        if(luaData[count]["parameters"]) {
            std::string parameters = luaData[count]["parameters"];
            scriptData.parameters = parameters;
        }
        scriptInfo.push_back(scriptData);
        count++;
    }
}