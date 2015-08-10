//
// Created by Ryan on 8/1/2015.
//

#ifndef RAINSFORD_COLLISIONCOMP_HPP
#define RAINSFORD_COLLISIONCOMP_HPP

#include <SFML/Graphics.hpp>
#include "Components/Component.hpp"

class Collidable : public Component {
public:
    void setBounds(sf::FloatRect);
    const sf::FloatRect& getBounds();

private:
    sf::FloatRect bounds;
};

#endif //RAINSFORD_COLLISIONCOMP_HPP
