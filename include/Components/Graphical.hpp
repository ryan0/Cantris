//
// Created by Ryan on 8/7/2015.
//

#ifndef RAINSFORD_IMAGE_HPP
#define RAINSFORD_IMAGE_HPP

#include <SFML/Graphics.hpp>
#include "Component.hpp"
#include "selene.h"

class Graphical : public Component, public sf::Sprite {
public:
    virtual void loadFromLua(sel::Selector& luaData, AssetManager& assetManagerRef, b2World& physicsSpace) override;
};

#endif //RAINSFORD_IMAGE_HPP
