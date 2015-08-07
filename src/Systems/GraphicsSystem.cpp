//
// Created by Ryan on 8/3/2015.
//

#include "Systems/GraphicsSystem.hpp"
#include "Components/Renderable.hpp"
#include "Components/Spatial.hpp"

void GraphicsSystem::render(sf::RenderTarget& renderTarget, std::vector<std::unique_ptr<Entity>> &entities) {
    for(std::unique_ptr<Entity>& e : entities) {
        if(e->hasComponent<Renderable>() && e->hasComponent<Spatial>()) {
            Renderable* renderRef = e->getComponent<Renderable>();
            Spatial * spatialRef = e->getComponent<Spatial>();

            sf::RenderStates states(spatialRef->getTransform());
            renderTarget.draw(renderRef->getGraphic(), states);
        }
    }
}
