//
// Created by Ryan on 5/6/2016.
//

#ifndef RAINSFORD_LUABINDINGS_HPP
#define RAINSFORD_LUABINDINGS_HPP

#include "Engine/Entity.hpp"
#include "Engine/Scene.hpp"
#include "Core/AnimatedSprite.hpp"

namespace lua {
    typedef sf::Vector2<double> Vector;

    void print(std::string str);
    bool isKeyPressed(std::string key);

    Entity* getEntityById(Scene* scene, std::string id);

    Vector getPosition(Entity* entity);
    double getRotation(Entity* entity);
    Vector getScale(Entity* entity);
    void move(Entity* entity, Vector vec);
    void rotate(Entity* entity, double angle);
    void scale(Entity* entity, Vector vec);
    void setPosition(Entity* entity, Vector vec);
    void setRotation(Entity* entity, float angle);
    void setScale(Entity* entity, Vector vec);

    Vector getVelocity(Entity* entity);
    Vector getLocalCenter(Entity* entity);
    void setPhysicalPosition(Entity* entity, Vector vec);
    void applyLinearImpulse(Entity* entity, Vector impulse, Vector point, bool wake = true);
    void applyForceToCenter(Entity* entity, Vector force, bool wake = true);

    AnimatedSprite* getCurrentAnimation(Entity* entity);
    std::string getCurrentAnimationName(Entity* entity);
    void setCurrentAnimation(Entity* entity, std::string animation);
    void play(AnimatedSprite* animation);
    void pause(AnimatedSprite* animation);
    void stop(AnimatedSprite* animation);
    void setLooped(AnimatedSprite* animation, bool looped);
    bool isLooped(AnimatedSprite* animation);
    bool isPlaying(AnimatedSprite* animation);
}


#endif //RAINSFORD_LUABINDINGS_HPP
