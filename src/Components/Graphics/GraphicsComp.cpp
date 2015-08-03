//
// Created by Ryan on 8/2/2015.
//

#include "Components/Graphics/GraphicsComp.hpp"

GraphicsComp::GraphicsComp(Entity &entity) : Component(entity){

}

void GraphicsComp::setGraphic(sf::Drawable &newGraphic) {
    graphic = &newGraphic;
}

const sf::Drawable &GraphicsComp::getGraphic() {
    return *graphic;
}


void GraphicsComp::draw(sf::RenderTarget &target, sf::RenderStates states) const {

}
