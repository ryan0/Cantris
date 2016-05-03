//
// Created by Ryan on 8/7/2015.
//

#ifndef RAINSFORD_ANIMATED_HPP
#define RAINSFORD_ANIMATED_HPP

#include <Box2D/Box2D.h>
#include "Component.hpp"
#include "Core/AnimatedSprite.hpp"

class Animated : public Component, public AnimatedSprite {
public:
    virtual void loadFromLua(sel::Selector& luaData, AssetManager& assetManagerRef, b2World& physicsSpace) override;
};

#endif //RAINSFORD_ANIMATED_HPP
