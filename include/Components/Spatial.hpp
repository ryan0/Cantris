//
// Created by Ryan on 8/5/2015.
//

#ifndef RAINSFORD_POSITIONCOMP_HPP
#define RAINSFORD_POSITIONCOMP_HPP

#include <SFML/Graphics.hpp>
#include "Component.hpp"
#include "selene.h"

class Spatial : public Component, public sf::Transformable {
public:
    virtual void loadFromLua(sel::Selector& luaData, AssetManager& assetManagerRef, b2World& physicsSpace) override;
};

#endif //RAINSFORD_POSITIONCOMP_HPP
