//
// Created by Ryan on 6/4/2016.
//

#include "Components/Animated.hpp"

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