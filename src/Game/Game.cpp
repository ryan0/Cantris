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
    std::unique_ptr<Animated> testAnimated(new Animated());
    std::unique_ptr<Renderable> testRender(new Renderable());
    std::unique_ptr<Spatial> testSpatial(new Spatial());
    std::unique_ptr<Movable> testMovable(new Movable());

    testAnimated->setAnimation(assetManager.getAnimation("startMenu/fire.ani"));
    testAnimated->play();
    testSpatial->move(50, 50);
    testMovable->setVelocity(sf::Vector2f(10, 0));

    test->addComponent(std::move(testAnimated));
    test->addComponent(std::move(testRender));
    test->addComponent(std::move(testSpatial));
    test->addComponent(std::move(testMovable));
    gameEngine.addEntity(std::move(test));
}

void Game::cleanup() {

}
