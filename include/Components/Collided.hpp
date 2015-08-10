//
// Created by Ryan on 8/10/2015.
//

#ifndef RAINSFORD_COLLIDED_HPP
#define RAINSFORD_COLLIDED_HPP

#include <SFML/Graphics.hpp>
#include <vector>

#include "Component.hpp"

struct collide_data {
    sf::FloatRect bounds;
    sf::Vector2f position;
    sf::Vector2f velocity;
    bool staticObj;
    float restitude;
    float mass;
};

class Collided : public Component {
public:
    const std::vector<collide_data>& getCollisions();
    void addCollision(const collide_data& newCollide);
    void setCollisions(std::vector<collide_data>& collisionData);

private:
    std::vector<collide_data> collisions;
};

#endif //RAINSFORD_COLLIDED_HPP
