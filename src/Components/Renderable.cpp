//
// Created by Ryan on 8/2/2015.
//

#include "Components/Renderable.hpp"

float Renderable::getZValue() {
    return zValue;
}

void Renderable::setZValue(float newZValue) {
    zValue = newZValue;
}

sf::Drawable* Renderable::getDrawable() {
    return drawableRef;
}

void Renderable::setDrawable(sf::Drawable* newDrawable) {
    drawableRef = newDrawable;
}

void Renderable::loadFromLua(sel::Selector& luaData, AssetManager& assetManagerRef, b2World& physicsSpace) {
    if(luaData["zValue"] == true) {
        zValue = (float)double(luaData["zValue"]);
    }
}