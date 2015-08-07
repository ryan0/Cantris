//
// Created by Ryan on 8/2/2015.
//

#ifndef RAINSFORD_GRAPHICSCOMP_HPP
#define RAINSFORD_GRAPHICSCOMP_HPP

#include <SFML/Graphics.hpp>
#include <memory>

#include "Components/Component.hpp"

class Renderable : public Component {
    friend class GraphicsSystem;
public:
    void setZValue(float newZValue);
    float getZValue();

private:
    void setDrawable(sf::Drawable* newDrawable);
    sf::Drawable* getDrawable();
    sf::Drawable* drawableRef;
    float ZValue;
};

#endif //RAINSFORD_GRAPHICSCOMP_HPP