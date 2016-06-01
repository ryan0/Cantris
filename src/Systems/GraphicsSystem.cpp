//
// Created by Ryan on 8/3/2015.
//

#include <Components/Animator.hpp>
#include "Engine/Entity.hpp"
#include "Systems/GraphicsSystem.hpp"
#include "Components/Renderable.hpp"
#include "Components/Graphical.hpp"
#include "Components/Animated.hpp"
#include "Components/Spatial.hpp"

void GraphicsSystem::render(double alpha, sf::RenderTarget& renderTarget, std::multimap<float, Entity*>& sceneGraph) {
    for(auto& it : sceneGraph) {
        Renderable* renderRef = it.second->getComponent<Renderable>();
        Graphical* graphicRef = it.second->getComponent<Graphical>();
        Animated* animatedRef = it.second->getComponent<Animated>();
        Animator* animatorRef = it.second->getComponent<Animator>();
        Spatial* spatialRef = it.second->getComponent<Spatial>();

        if (graphicRef) {
            renderRef->setDrawable(graphicRef);
        }
        if (animatedRef) {
            renderRef->setDrawable(animatedRef);
        }
        if (animatorRef) {
            renderRef->setDrawable(animatorRef);
        }


        if (renderRef && spatialRef && renderRef->getDrawable()) {
            sf::Transform transform;
            sf::Vector2f interpol = Lerp(spatialRef->lastPosition, spatialRef->getPosition(), alpha);
            transform.translate(interpol);
            transform.rotate(spatialRef->getRotation());
            transform.scale(spatialRef->getScale());

            transform.scale(sf::Vector2f(.12f, .12f));
            sf::RenderStates states(transform);
            renderTarget.draw(*renderRef->getDrawable(), states);
        }
    }
}

void GraphicsSystem::renderDebug() {
    debugDraw.drawDebug();
}

void GraphicsSystem::update(double timeStep, std::vector<std::unique_ptr<Entity>>& entities) {
    for(auto& e : entities) {
        Spatial* spatialRef = e->getComponent<Spatial>();
        Animated* animatedRef = e->getComponent<Animated>();
        Animator* animatorRef = e->getComponent<Animator>();

        if(spatialRef) {
            spatialRef->lastPosition = spatialRef->getPosition();
        }
        if (animatedRef) {
            animatedRef->update(sf::seconds(timeStep));
        }
        if (animatorRef) {
            animatorRef->update(sf::seconds(timeStep));
        }
    }
}

void GraphicsSystem::setDebugDraw(sf::RenderTarget &renderTarget, b2World &physicsSpace) {
    debugDraw.setRenderTarget(renderTarget);
    debugDraw.setAsTargetOf(physicsSpace);
}

float GraphicsSystem::Lerp(float v0, float v1, float alpha) {
    return (1-alpha)*v0 + alpha*v1;
}

sf::Vector2f  GraphicsSystem::Lerp(sf::Vector2f v0, sf::Vector2f  v1, float alpha) {
    float x = Lerp(v0.x, v1.x, alpha);
    float y = Lerp(v0.y, v1.y, alpha);
    return sf::Vector2f(x, y);
}
