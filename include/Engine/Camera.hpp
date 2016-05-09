//
// Created by Ryan on 8/12/2015.
//

#ifndef RAINSFORD_CAMERA_HPP
#define RAINSFORD_CAMERA_HPP

#include <SFML/Graphics.hpp>
#include "Entity.hpp"

class Camera : public sf::View {
public:
    Camera();
    void follow(Entity& entity);
    void updatePosition(double alpha);

private:
    Entity* entityRef;
};



#endif //RAINSFORD_CAMERA_HPP
