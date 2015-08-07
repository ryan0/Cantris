//
// Created by Ryan on 8/1/2015.
//

#ifndef RAINSFORD_CAMERA_HPP
#define RAINSFORD_CAMERA_HPP

#include <SFML/Graphics.hpp>
#include <map>

#include "System.hpp"
#include "Engine/Entity.hpp"

class GraphicsSystem : System {
public:
    void render(sf::RenderTarget& renderTarget);
    virtual void onNewEntity(Entity* entityRef) override;
    virtual void update(float tpf, std::vector<std::unique_ptr<Entity>>& entities) override;

private:
    std::multimap<float, Entity*> renderables;
};

#endif //RAINSFORD_CAMERA_HPP
