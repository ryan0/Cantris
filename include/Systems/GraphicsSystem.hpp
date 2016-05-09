//
// Created by Ryan on 8/1/2015.
//

#ifndef RAINSFORD_GRAPHICSSYSTEM_HPP
#define RAINSFORD_GRAPHICSSYSTEM_HPP

#include <Box2D/Box2D.h>
#include <SFML/Graphics.hpp>
#include <map>

#include "Core/DebugDraw.hpp"

class GraphicsSystem {
public:
    void render(double alpha, sf::RenderTarget& renderTarget, std::multimap<float, Entity*>& sceneGraph);
    void renderDebug();

    void update(double timeStep, std::vector<std::unique_ptr<Entity>>& entities);
    void setDebugDraw(sf::RenderTarget& renderTarget, b2World& physicsSpace);

    static float Lerp(float v0, float v1, float alpha);
    static sf::Vector2f Lerp(sf::Vector2f v0, sf::Vector2f  v1, float alpha);
private:
    DebugDraw debugDraw;
};

#endif //RAINSFORD_CAMERA_HPP
