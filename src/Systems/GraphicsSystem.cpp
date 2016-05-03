//
// Created by Ryan on 8/3/2015.
//

#include "Engine/Entity.hpp"
#include "Systems/GraphicsSystem.hpp"
#include "Components/Renderable.hpp"
#include "Components/Graphical.hpp"
#include "Components/Animated.hpp"
#include "Components/Spatial.hpp"

void GraphicsSystem::render(sf::RenderTarget& renderTarget, std::multimap<float, Entity*>& sceneGraph) {
    for(auto& it : sceneGraph) {
            Renderable *renderRef = it.second->getComponent<Renderable>();
            Graphical *graphicRef = it.second->getComponent<Graphical>();
            Animated *animatedRef = it.second->getComponent<Animated>();
            Spatial *spatialRef = it.second->getComponent<Spatial>();

            if (graphicRef) {
                renderRef->setDrawable(graphicRef);
            }
            if (animatedRef) {
                renderRef->setDrawable(animatedRef);
            }


            if (renderRef && spatialRef && renderRef->getDrawable()) {
                sf::Transform transform = spatialRef->getTransform() * renderRef->getTransform();
                transform.scale(sf::Vector2f(.5f, .5f));
                sf::RenderStates states(transform);

                renderTarget.draw(*renderRef->getDrawable(), states);
            }
    }
}

void GraphicsSystem::renderDebug() {
    debugDraw.drawDebug();
}

void GraphicsSystem::update(float tpf, std::vector<std::unique_ptr<Entity>>& entities) {
    for(auto& e : entities) {
        if(e->hasComponent<Renderable>() && e->hasComponent<Spatial>()) {
            Animated *animatedRef = e->getComponent<Animated>();

            if (animatedRef) {
                animatedRef->update(sf::seconds(tpf));
            }
        }
    }
}

void GraphicsSystem::setDebugDraw(sf::RenderTarget &renderTarget, b2World &physicsSpace) {
    debugDraw.setRenderTarget(renderTarget);
    debugDraw.setAsTargetOf(physicsSpace);
}
