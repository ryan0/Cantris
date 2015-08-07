//
// Created by Ryan on 8/1/2015.
//

#ifndef RAINSFORD_CAMERA_HPP
#define RAINSFORD_CAMERA_HPP

#include <SFML/Graphics.hpp>
#include <vector>

#include "System.hpp"
#include "Engine/Entity.hpp"

class GraphicsSystem : System {
public:
    void render(sf::RenderTarget& renderTarget, std::vector<std::unique_ptr<Entity>>& entities);
};

#endif //RAINSFORD_CAMERA_HPP
