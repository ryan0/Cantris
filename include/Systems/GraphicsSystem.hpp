//
// Created by Ryan on 8/1/2015.
//

#ifndef RAINSFORD_GRAPHICSSYSTEM_HPP
#define RAINSFORD_GRAPHICSSYSTEM_HPP

#include <Box2D/Box2D.h>
#include <SFML/Graphics.hpp>
#include <map>

#include "System.hpp"
#include "Core/DebugDraw.hpp"

class GraphicsSystem : System {
public:
    void render(sf::RenderTarget& renderTarget, std::multimap<float, Entity*>& sceneGraph);
    void renderDebug();

    virtual void update(float tpf, std::vector<std::unique_ptr<Entity>>& entities) override;
    void setDebugDraw(sf::RenderTarget& renderTarget, b2World& physicsSpace);
private:
    DebugDraw debugDraw;
};

#endif //RAINSFORD_CAMERA_HPP
