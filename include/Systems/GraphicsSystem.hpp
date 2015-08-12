//
// Created by Ryan on 8/1/2015.
//

#ifndef RAINSFORD_GRAPHICSSYSTEM_HPP
#define RAINSFORD_GRAPHICSSYSTEM_HPP

#include <SFML/Graphics.hpp>
#include <map>

#include "System.hpp"

class GraphicsSystem : System {
public:
    void render(sf::RenderTarget& renderTarget);
    virtual void onNewEntity(Entity* entityRef) override;
    virtual void update(float tpf, std::vector<std::unique_ptr<Entity>>& entities) override;

private:
    std::multimap<float, Entity*> renderables;
};

#endif //RAINSFORD_CAMERA_HPP
