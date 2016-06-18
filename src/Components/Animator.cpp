//
// Created by Ryan on 5/7/2016.
//

#include "Components/Animator.hpp"


void Animator::setCurrentAnimation(std::string str) {
    currentAnimation = &animations[str];
    currentAnimationKey = str;
}

AnimatedSprite* Animator::getCurrentAnimation() {
    return currentAnimation;
}

std::string Animator::getCurrentAnimationName() {
    return  currentAnimationKey;
}

void Animator::addAnimation(std::string str, AnimatedSprite animtaion) {
    animations[str] = animtaion;
}

void Animator::update(sf::Time deltaTime) {
    currentAnimation->update(deltaTime);
}

void Animator::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    states.transform *= getTransform();
    target.draw(*currentAnimation, states);
}

void Animator::loadFromLua(sel::Selector& luaData, AssetManager& assetManagerRef, b2World& physicsSpace) {
    if(luaData["position"] == true) {
        float x = (float)double(luaData["position"][1]);
        float y = (float)double(luaData["position"][2]);
        setPosition(x, y);
    }
    if(luaData["animations"] == true) {
        sel::Selector selector = luaData["animations"];
        int count = 1;
        while(selector[count] == true) {
            std::string name = selector[count][1];
            std::string file = selector[count][2];
            AnimatedSprite animation;
            animation.setAnimation(assetManagerRef.getAnimation(file, name));
            addAnimation(name, animation);
            setCurrentAnimation(name);

            if(selector[count]["offset"] == true) {
                float x = (float)double(selector[count]["offset"][1]);
                float y = (float)double(selector[count]["offset"][2]);
                currentAnimation->setPosition(x, y);
            }
            if(selector[count]["frametime"] == true) {
                float time = (float)double(selector[count]["frametime"]);
                currentAnimation->setFrameTime(sf::seconds(time));
            }
            count++;
        }
    }
}