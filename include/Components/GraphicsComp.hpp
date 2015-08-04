//
// Created by Ryan on 8/2/2015.
//

#ifndef RAINSFORD_GRAPHICSCOMP_HPP
#define RAINSFORD_GRAPHICSCOMP_HPP

#include <SFML/Graphics.hpp>
#include "Components/Component.hpp"

class GraphicsComp : public Component, public sf::Drawable {
public:
    void setZValue(float newZValue);
    float getZValue();

protected:
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

private:
    float ZValue;
};

#endif //RAINSFORD_GRAPHICSCOMP_HPP