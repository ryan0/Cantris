//
// Created by Ryan on 7/31/2015.
//

#ifndef RAINSFORD_STARTMENU_HPP
#define RAINSFORD_STARTMENU_HPP

#include "Core/GameWindow.hpp"
#include "Core/WindowState.hpp"
#include "Core/AnimatedSprite.hpp"

class StartMenu : public WindowState {
public:
    virtual void update(float tpf) override;
    virtual void render(sf::RenderTarget &target) override;
    virtual void handleEvents(sf::Event &event);
    virtual void initialize(GameWindow& gameWindow, AssetManager& assetManager) override;
    virtual void cleanup() override;

private:
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
