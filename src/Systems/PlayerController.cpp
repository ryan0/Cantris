//
// Created by Ryan on 8/12/2015.
//

#include <Components/Physical.hpp>
#include "Systems/PlayerController.hpp"
#include "Components/PlayerControlled.hpp"
#include "Components/Movable.hpp"
#include "Components/Movable.hpp"

void PlayerController::update(float tpf, std::vector<std::unique_ptr<Entity>> &entities) {
    for(auto& e : entities) {
        if(e->hasComponent<PlayerControlled>()) {
            Physical* physicalRef = e->getComponent<Physical>();

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
                physicalRef->getBodyRef().ApplyForceToCenter(b2Vec2(95.0f, 0.0f), true);
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
                physicalRef->getBodyRef().ApplyForceToCenter(b2Vec2(-145.0f, 0.0f), true);
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
                physicalRef->getBodyRef().ApplyForceToCenter(b2Vec2(0.0f, -95.0f), true);
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
                physicalRef->getBodyRef().ApplyForceToCenter(b2Vec2(0.0f, 95.0f), true);
            }
        }
    }
}
