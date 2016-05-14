//
// Created by Ryan on 5/6/2016.
//

#include <Components/Animator.hpp>
#include "Engine/LuaBindings.hpp"
#include "Components/Spatial.hpp"
#include "Components/Physical.hpp"

namespace {
    lua::Vector toVector(sf::Vector2f vecf) {
        return lua::Vector(vecf.x, vecf.y);
    }
    lua::Vector toVector(b2Vec2 vecf) {
        return lua::Vector(vecf.x, vecf.y);
    }

    sf::Vector2f toVector2f(lua::Vector vec) {
        return sf::Vector2f(float(vec.x), float(vec.y));
    }
    b2Vec2 tob2Vec(lua::Vector vec) {
        return b2Vec2(float(vec.x), float(vec.y));
    }

    std::map<std::string, sf::Keyboard::Key> keyMap= {
            {"A", sf::Keyboard::A},
            {"W", sf::Keyboard::W},
            {"D", sf::Keyboard::D},
            {"S", sf::Keyboard::S},
            {"E", sf::Keyboard::E},
            {"C", sf::Keyboard::C},
    };
}

namespace lua {
    void print(std::string str) {
        std::cout<<str<<std::endl;
    }
    bool isKeyPressed(std::string str) {
        return sf::Keyboard::isKeyPressed(keyMap[str]);
    }


    Entity* getEntityById(Scene* scene, std::string id) {
        return scene->getEntity(id);
    }


    Vector getPosition(Entity* entity) {
        if(entity->hasComponent<Spatial>()) {
            Spatial* spatial = entity->getComponent<Spatial>();
            return toVector(spatial->getPosition());
        }
        else return  Vector();
    }
    double getRotation(Entity* entity) {
        if(entity->hasComponent<Spatial>()) {
            Spatial* spatial = entity->getComponent<Spatial>();
            return spatial->getRotation();
        }
        else return 0;
    }
    Vector getScale(Entity* entity) {
        if(entity->hasComponent<Spatial>()) {
            Spatial* spatial = entity->getComponent<Spatial>();
            return toVector(spatial->getScale());
        }
        else return  Vector();
    }
    void move(Entity* entity, Vector vec) {
        if(entity->hasComponent<Spatial>()) {
            Spatial* spatial = entity->getComponent<Spatial>();
            spatial->move(toVector2f(vec));
        }
    }
    void rotate(Entity* entity, double angle) {
        if(entity->hasComponent<Spatial>()) {
            Spatial* spatial = entity->getComponent<Spatial>();
            spatial->rotate(angle);
        }
    }
    void scale(Entity* entity, Vector vec) {
        if(entity->hasComponent<Spatial>()) {
            Spatial* spatial = entity->getComponent<Spatial>();
            spatial->scale(toVector2f(vec));
        }
    }
    void setPosition(Entity* entity, Vector vec) {
        if(entity->hasComponent<Spatial>()) {
            Spatial* spatial = entity->getComponent<Spatial>();
            spatial->setPosition(toVector2f(vec));
        }
    }
    void setRotation(Entity* entity, float angle) {
        if(entity->hasComponent<Spatial>()) {
            Spatial* spatial = entity->getComponent<Spatial>();
            spatial->setRotation(angle);
        }
    }
    void setScale(Entity* entity, Vector vec) {
        if(entity->hasComponent<Spatial>()) {
            Spatial* spatial = entity->getComponent<Spatial>();
            spatial->setScale(toVector2f(vec));
        }
    }


    Vector getLocalCenter(Entity* entity) {
        if(entity->hasComponent<Physical>()) {
            Physical* physical = entity->getComponent<Physical>();
            return toVector(physical->getBodyRef().GetLocalCenter());
        }
        else return Vector();
    }

    Vector getVelocity(Entity* entity) {
        if(entity->hasComponent<Physical>()) {
            Physical* physical = entity->getComponent<Physical>();
            return toVector(physical->getBodyRef().GetLinearVelocity());
        }
        else return  Vector();
    }

    void setPhysicalPosition(Entity* entity, Vector vec) {
        if(entity->hasComponent<Physical>()) {
            Physical* physical = entity->getComponent<Physical>();
            physical->getBodyRef().SetTransform(tob2Vec(vec), physical->getBodyRef().GetAngle());
        }
    }

    void applyLinearImpulse(Entity* entity, Vector impulse, Vector point, bool wake) {
        if(entity->hasComponent<Physical>()) {
            Physical* physical = entity->getComponent<Physical>();
            physical->getBodyRef().ApplyLinearImpulse(tob2Vec(impulse), tob2Vec(point), wake);
        }
    }

    void applyForceToCenter(Entity* entity, Vector force, bool wake) {
        if(entity->hasComponent<Physical>()) {
            Physical* physical = entity->getComponent<Physical>();
            physical->getBodyRef().ApplyForceToCenter(tob2Vec(force), wake);
        }
    }


    AnimatedSprite* getCurrentAnimation(Entity* entity) {
        if(entity->hasComponent<Animator>()) {
            Animator* animator = entity->getComponent<Animator>();
            return animator->getCurrentAnimation();
        }
        else return nullptr;
    }

    std::string getCurrentAnimationName(Entity* entity) {
        std::string str;
        if(entity->hasComponent<Animator>()) {
            Animator* animator = entity->getComponent<Animator>();
            return animator->getCurrentAnimationName();
        }
        else return "";
    }

    void  setCurrentAnimation(Entity* entity, std::string animation) {
        if(entity->hasComponent<Animator>()) {
            Animator* animator = entity->getComponent<Animator>();
            animator->setCurrentAnimation(animation);
        }
    }

    void play(AnimatedSprite* animation) {
        animation->play();
    }

    void pause(AnimatedSprite* animation) {
        animation->pause();
    }

    void stop(AnimatedSprite* animation) {
        animation->stop();
    }

    void setLooped(AnimatedSprite* animation, bool looped) {
        animation->setLooped(looped);
    }

    bool isLooped(AnimatedSprite* animation) {
        return animation->isLooped();
    }

    bool isPlaying(AnimatedSprite* animation) {
        return  animation->isPlaying();
    }
}