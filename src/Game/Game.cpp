//
// Created by Ryan on 7/31/2015.
//

#include "Game/Game.hpp"
#include "Core/GameWindow.hpp"
#include "Components/Renderable.hpp"
#include "Components/Spatial.hpp"
#include "Core/AnimatedSprite.hpp"

void Game::update(float tpf) {
    gameEngine.update(tpf);
}

void Game::render(sf::RenderTarget &target) {
    gameWindowRef->makeLetterBox(sf::Vector2f(200, 113));
    gameEngine.render(target);
}

void Game::handleEvents(sf::Event &event) {

}

void Game::initialize(GameWindow& gameWindow, AssetManager& assetManager) {
    gameWindowRef = &gameWindow;

    std::unique_ptr<Entity> test(new Entity());
    std::unique_ptr<Renderable> testRender(new Renderable());
    std::unique_ptr<Spatial> testSpatial(new Spatial());

    std::shared_ptr<AnimatedSprite> animated(new AnimatedSprite());
    animated->setAnimation(assetManager.getAnimation("startMenu/fire.ani"));
    animated->play();

    testRender->setGraphic(animated);
    test->addComponent(std::move(testRender));
    test->addComponent(std::move(testSpatial));
    gameEngine.addEntity(std::move(test));
}

void Game::cleanup() {

}
