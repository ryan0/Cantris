//
// Created by Ryan on 6/4/2016.
//
#include "Components/Graphical.hpp"

void Graphical::loadFromLua(sel::Selector& luaData, AssetManager& assetManagerRef, b2World& physicsSpace) {
    if(luaData["texture"]) {
        std::string textureFile = luaData["texture"];
        setTexture(assetManagerRef.getTexture(textureFile));
    }
    if(luaData["textureRect"]) {
        int x1 = luaData["textureRect"][1];
        int y1 = luaData["textureRect"][2];
        int x2 = luaData["textureRect"][3];
        int y2 = luaData["textureRect"][4];
        setTextureRect(sf::IntRect(x1, y1, x2, y2));
    }
    if(luaData["position"]) {
        float x = (float)double(luaData["position"][1]);
        float y = (float)double(luaData["position"][2]);
        setPosition(x, y);
    }
    if(luaData["scale"]) {
        float v = (float) double(luaData["scale"]);
        std::cout<<v;
        setScale(v, v);
    }
}