//
// Created by Ryan on 8/8/2015.
//

#ifndef RAINSFORD_PHYSICAL_HPP
#define RAINSFORD_PHYSICAL_HPP

#include <SFML/Graphics/Rect.hpp>
#include <Box2D/Box2D.h>
#include "selene.h"
#include "Component.hpp"
#include "Core/AssetManager.hpp"


class Physical : public Component {
public:
    virtual void loadFromLua(sel::Selector& luaData, AssetManager& assetManagerRef, b2World& physicsSpace) override;
    b2Body& getBodyRef();

private:
    b2Body* b2BodyRef;
    b2BodyDef loadLuaBodyDef(sel::Selector& luaData);
    void createLuaFixture(sel::Selector& luaData);
};

#endif //RAINSFORD_PHYSICAL_HPP
