//
// Created by Ryan on 8/12/2015.
//

#include "Engine/Camera.hpp"
#include "Components/Spatial.hpp"
#include "Systems/GraphicsSystem.hpp"

Camera::Camera() : entityRef(NULL) { }

void Camera::follow(Entity &entity) {
    entityRef = &entity;
    Spatial* spatialRef = entityRef->getComponent<Spatial>();
    state = spatialRef->getPosition();
    prevState = spatialRef->lastPosition;
}

void Camera::stopFollow() {
    entityRef = NULL;
}

void Camera::update(double tpf) {
    prevState = state;
    if(entityRef) {
        Spatial *spatialRef = entityRef->getComponent<Spatial>();
        state = GraphicsSystem::Lerp(state, spatialRef->getPosition(), 4.0f * (float)tpf);
    }
}

void Camera::updatePosition(double alpha) {
    sf::Vector2f interpol;
    interpol = GraphicsSystem::Lerp(prevState, state, (float)alpha);
    setCenter(interpol + offset);
}
