//
// Created by Ryan on 5/1/2016.
//

#include <Core/AssetManager.hpp>
#include <Components/Animated.hpp>
#include <Components/Movable.hpp>
#include <Components/Physical.hpp>
#include "Components/Renderable.hpp"
#include "Components/Graphical.hpp"
#include "Components/Spatial.hpp"


void Renderable::loadFromLua(sel::Selector& luaData, AssetManager& assetManagerRef, b2World& physicsSpace) {
    if(luaData["zValue"] == true) {
        zValue = (float)double(luaData["zValue"]);
    }
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
}

void Animated::loadFromLua(sel::Selector& luaData, AssetManager& assetManagerRef, b2World& physicsSpace) {
    if(luaData["animation"] == true) {
        std::string animation= luaData["animation"];
        setAnimation(assetManagerRef.getAnimation(animation));
    }
    if(luaData["frametime"] == true) {
        float time = (float)double(luaData["frametime"]);
        setFrameTime(sf::seconds(time));
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

void Movable::loadFromLua(sel::Selector& luaData, AssetManager& assetManagerRef, b2World& physicsSpace) {
    if(luaData["velocity"] == true) {

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