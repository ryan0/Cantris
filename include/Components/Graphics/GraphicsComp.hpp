//
// Created by Ryan on 8/2/2015.
//

#ifndef RAINSFORD_GRAPHICSCOMP_HPP
#define RAINSFORD_GRAPHICSCOMP_HPP

#include <SFML/Graphics.hpp>
#include "Components/Component.hpp"

class GraphicsComp : public Component, public sf::Drawable {
public:
    GraphicsComp(Entity& entity);
    void setGraphic(sf::Drawable& newGraphic);
    const sf::Drawable& getGraphic();

protected:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

private:
    sf::Drawable* graphic;
};

#endif //RAINSFORD_GRAPHICSCOMP_HPP