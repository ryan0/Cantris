//
// Created by Ryan on 5/7/2016.
//

#include "Components/Animator.hpp"


void Animator::setCurrentAnimation(std::string str) {
    currentAnimation = &animations[str];
    currentAnimationKey = str;
}

std::string Animator::getCurrentAnimation() {
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