//
// Created by Ryan on 8/10/2015.
//

#include "Components/Collidable.hpp"

void Collidable::setBounds(sf::FloatRect rect) {
    bounds = rect;
}

const sf::FloatRect& Collidable::getBounds() {
    return bounds;
}
