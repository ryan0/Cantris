//
// Created by Ryan on 8/3/2015.
//

#include "Engine/Entity.hpp"
#include "Systems/GraphicsSystem.hpp"
#include "Components/Renderable.hpp"
#include "Components/Graphical.hpp"
#include "Components/Animated.hpp"
#include "Components/Spatial.hpp"

void GraphicsSystem::render(sf::RenderTarget& renderTarget) {
    for(auto& it : renderables) {
        Renderable* renderRef = it.second->getComponent<Renderable>();
        Spatial* spatialRef = it.second->getComponent<Spatial>();

        if(renderRef && spatialRef && renderRef->getDrawable()) {
            sf::RenderStates states(spatialRef->getTransform());
            renderTarget.draw(*renderRef->getDrawable(), states);
        }
    }
}

void GraphicsSystem::update(float tpf, std::vector<std::unique_ptr<Entity>>& entities) {
    for(auto& it : renderables) {
        Entity* entityRef = it.second;
        Renderable* renderRef = entityRef->getComponent<Renderable>();
        Graphical* graphicRef = entityRef->getComponent<Graphical>();
        Animated* animatedRef = entityRef->getComponent<Animated>();

        if(graphicRef) {
            renderRef->setDrawable(graphicRef);
        }

        if(animatedRef) {
            animatedRef->update(sf::seconds(tpf));
            renderRef->setDrawable(animatedRef);
        }
    }
}

void GraphicsSystem::onNewEntity(Entity* entityRef) {
    if(entityRef->hasComponent<Renderable>() && entityRef->hasComponent<Spatial>()) {
        Renderable * graphic = entityRef->getComponent<Renderable>();
        renderables.insert(std::pair<float, Entity*>(graphic->getZValue(), entityRef));
    }
}
