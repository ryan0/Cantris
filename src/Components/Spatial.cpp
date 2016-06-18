//
// Created by Ryan on 6/4/2016.
//
#include "Components/Spatial.hpp"

void Spatial::loadFromLua(sel::Selector& luaData, AssetManager& assetManagerRef, b2World& physicsSpace) {
    if(luaData["position"]) {
        float x = (float)double(luaData["position"][1]);
        float y = (float)double(luaData["position"][2]);
        setPosition(x, y);
    }
    if(luaData["origin"]) {
        float x = (float)double(luaData["origin"][1]);
        float y = (float)double(luaData["origin"][2]);
        setOrigin(x, y);
    }
}