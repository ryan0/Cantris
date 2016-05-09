//
// Created by Ryan on 8/12/2015.
//

#include "Engine/Camera.hpp"
#include "Components/Spatial.hpp"
#include "Systems/GraphicsSystem.hpp"

Camera::Camera() : entityRef(NULL) { }

void Camera::follow(Entity &entity) {
    entityRef = &entity;
}

void Camera::updatePosition(double alpha) {
    if(entityRef) {
        Spatial* spatialRef = entityRef->getComponent<Spatial>();
        float interpol = GraphicsSystem::Lerp(spatialRef->lastPosition.x, spatialRef->getPosition().x, alpha);
        setCenter(interpol, getCenter().y);
    }
}
