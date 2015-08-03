//
// Created by Ryan on 7/31/2015.
//

#ifndef RAINSFORD_STARTMENU_HPP
#define RAINSFORD_STARTMENU_HPP

#include "System/EngineState.hpp"
#include "System/Engine.hpp"
#include "System/Animation/AnimatedSprite.hpp"

class StartMenu : public EngineState {
public:
    virtual void update(float tpf) override;
    virtual void render(sf::RenderTarget &target) override;
    virtual void handleEvents(sf::Event &event);
    virtual void initialize(Engine& engine, GameWindow& gameWindow, AssetManager& assetManager) override;
    virtual void cleanup() override;

private:
    Engine* engineRef;
    GameWindow* gameWindowRef;
    sf::Sprite background;
    float timeSinceSmoke;
    sf::Font cyrilPix;
    sf::Text title;
    AnimatedSprite
            rainsford,
            fire;

    Animation
            rainsfordAnimation,
            fireAnimation;
};

#endif //RAINSFORD_STARTMENU_HPP
