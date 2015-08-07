//
// Created by Ryan on 8/2/2015.
//

#ifndef RAINSFORD_GRAPHICSCOMP_HPP
#define RAINSFORD_GRAPHICSCOMP_HPP

#include <SFML/Graphics.hpp>
#include <memory>

#include "Components/Component.hpp"

class Renderable : public Component {
public:
    const sf::Drawable& getGraphic();
    void setGraphic(std::shared_ptr<sf::Drawable> newGraphic);

private:
    std::shared_ptr<sf::Drawable> graphic;
};

#endif //RAINSFORD_GRAPHICSCOMP_HPP