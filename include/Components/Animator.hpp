//
// Created by Ryan on 5/7/2016.
//

#ifndef RAINSFORD_ANIMATOR_HPP
#define RAINSFORD_ANIMATOR_HPP

#include <SFML/Graphics.hpp>
#include "Core/AnimatedSprite.hpp"
#include "Component.hpp"


class Animator : public Component, public sf::Drawable, public sf::Transformable {
public:
    virtual void loadFromLua(sel::Selector& luaData, AssetManager& assetManagerRef, b2World& physicsSpace) override;
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    void addAnimation(std::string str, AnimatedSprite animtaion);
    void setCurrentAnimation(std::string str);
    AnimatedSprite* getCurrentAnimation();
    std::string getCurrentAnimationName();
    void update(sf::Time deltaTime);

private:
    std::unordered_map<std::string, AnimatedSprite> animations;
    AnimatedSprite* currentAnimation;
    std::string currentAnimationKey;
};

#endif //RAINSFORD_ANIMATOR_HPP
