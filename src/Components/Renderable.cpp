//
// Created by Ryan on 8/2/2015.
//

#include "Components/Renderable.hpp"

const sf::Drawable& Renderable::getGraphic() {
    return *graphic;
}

void Renderable::setGraphic(std::shared_ptr<sf::Drawable> newGraphic) {
    graphic = newGraphic;
}
