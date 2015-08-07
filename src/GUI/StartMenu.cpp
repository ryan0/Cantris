//
// Created by Ryan on 7/31/2015.
//

#include <SFML/Graphics.hpp>

#include "GUI/StartMenu.hpp"
#include "Game/Game.hpp"

void StartMenu::update(float tpf) {
    rainsford.update(sf::seconds(tpf));
    fire.update(sf::seconds(tpf));

    if(!rainsford.isPlaying()) {
        timeSinceSmoke += tpf;
    }
    if(timeSinceSmoke > 5) {
        timeSinceSmoke = 0;
        rainsford.play();
    }
}

void StartMenu::render(sf::RenderTarget &target) {
    gameWindowRef->makeLetterBox(sf::Vector2f(200, 113));
    target.draw(background);
    target.draw(rainsford);
    target.draw(fire);

    gameWindowRef->makeLetterBox(sf::Vector2f(1600, 904));
    target.draw(title);
}

void StartMenu::handleEvents(sf::Event &event) {
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
        gameWindowRef->setState(windowState_ptr(new Game()));
}

void StartMenu::initialize(GameWindow& gameWindow, AssetManager& assetManager) {
    gameWindowRef = &gameWindow;
    assetManager.playSong("music/RainsfordTheme.ogg");
    background.setTexture(assetManager.getTexture("startMenu/titleScreen.png"));

    cyrilPix.loadFromFile("../assets/fonts/cyrillic_pixel-7.ttf");
    title.setFont(cyrilPix);
    title.setString("Rainsford");
    title.setCharacterSize(185);
    title.setPosition(550, 50);

    rainsford.setAnimation(assetManager.getAnimation("startMenu/rainsford.ani"));
    rainsford.setPosition(170, 95);
    rainsford.setLooped(false);
    rainsford.play();

    fire.setAnimation(assetManager.getAnimation("startMenu/fire.ani"));
    fire.setPosition(155, 95);
    fire.play();
}

void StartMenu::cleanup() {

}
