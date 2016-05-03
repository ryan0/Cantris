//
// Created by Ryan on 8/2/2015.
//

#ifndef RAINSFORD_GRAPHICSCOMP_HPP
#define RAINSFORD_GRAPHICSCOMP_HPP

#include "selene.h"
#include <SFML/Graphics.hpp>
#include <memory>

#include "Components/Component.hpp"

class Renderable : public Component, public sf::Transformable {
    friend class GraphicsSystem;
public:
    virtual void loadFromLua(sel::Selector& luaData, AssetManager& assetManagerRef, b2World& physicsSpace) override;
    void setZValue(float newZValue);
    float getZValue();

private:
    void setDrawable(sf::Drawable* newDrawable);
    sf::Drawable* getDrawable();

    sf::Drawable* drawableRef;
    float zValue;
};

#endif //RAINSFORD_GRAPHICSCOMP_HPP