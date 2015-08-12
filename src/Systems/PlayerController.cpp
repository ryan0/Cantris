//
// Created by Ryan on 8/12/2015.
//

#include "Systems/PlayerController.hpp"
#include "Components/PlayerControlled.hpp"
#include "Components/Movable.hpp"
#include "Components/Movable.hpp"

void PlayerController::onNewEntity(Entity* entityRef){

}

void PlayerController::update(float tpf, std::vector<std::unique_ptr<Entity>> &entities) {
    for(auto& e : entities) {
        if(e->hasComponent<PlayerControlled>()) {
            Movable* movableRef = e->getComponent<Movable>();

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
                movableRef->accelerate(sf::Vector2f(50, 0) * tpf);
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
                movableRef->accelerate(sf::Vector2f(-50, 0) * tpf);
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
                movableRef->accelerate(sf::Vector2f(0, -160) * tpf);
            }
        }
    }
}
