//
// Created by Ryan on 8/2/2015.
//

#include "Components/GraphicsComp.hpp"


void GraphicsComp::setZValue(float newZValue) {
    ZValue = newZValue;
}

float GraphicsComp::getZValue() {
    return ZValue;
}

void GraphicsComp::draw(sf::RenderTarget &target, sf::RenderStates states) const {

}
