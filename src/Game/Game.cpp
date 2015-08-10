//
// Created by Ryan on 7/31/2015.
//

#include "Game/Game.hpp"
#include "Core/GameWindow.hpp"
#include "Core/AnimatedSprite.hpp"
#include "Components/Animated.hpp"
#include "Components/Renderable.hpp"
#include "Components/Spatial.hpp"
#include "Components/Movable.hpp"
#include "Engine/EntityLoader.hpp"

void Game::update(float tpf) {
    gameEngine.update(tpf);
}

void Game::render(sf::RenderTarget &target) {
    gameWindowRef->makeLetterBox(sf::Vector2f(128, 72));
    gameEngine.render(target);
}

void Game::handleEvents(sf::Event &event) {

}

void Game::initialize(GameWindow& gameWindow, AssetManager& assetManager) {
    gameWindowRef = &gameWindow;
    EntityLoader entityLoader(assetManager);

    gameEngine.addEntity(entityLoader.loadEntity("rainsford.dat"));
    gameEngine.addEntity(entityLoader.loadEntity("bottom.dat"));
    gameEngine.addEntity(entityLoader.loadEntity("top.dat"));

}

void Game::cleanup() {

}
