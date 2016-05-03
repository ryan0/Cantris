//
// Created by Ryan on 8/12/2015.
//

#include "Engine/Camera.hpp"
#include "Components/Spatial.hpp"

void Camera::follow(Entity &entity) {
    entityRef = &entity;
}

void Camera::updatePosition(float tpf) {
    if(entityRef) {
        Spatial* spatialRef = entityRef->getComponent<Spatial>();
        setCenter(spatialRef->getPosition().x, 36.0f);
    }
}
