//
// Created by Ryan on 8/10/2015.
//

#include "Engine/EntityLoader.hpp"
#include "Components/Renderable.hpp"
#include "Components/Graphical.hpp"
#include "Components/Animated.hpp"
#include "Components/Spatial.hpp"
#include "Components/Movable.hpp"
#include "Components/Collidable.hpp"
#include "Components/Physical.hpp"
#include "Components/PlayerControlled.hpp"


component_ptr EntityLoader::readRenderable() {
    std::unique_ptr<Renderable> renderable(new Renderable());
    while(readNextChar() && currentChar != '}') {
        if(currentChar == '=') {
            if(keyword == "zValue") {
                renderable->setZValue(readFloat());
            }
            else {
                std::cout <<keyword<<" not recognized"<<std::endl;
            }
        }
    }
    return std::move(renderable);
}


component_ptr EntityLoader::readGraphical() {
    std::unique_ptr<Graphical> graphical(new Graphical());
    while(readNextChar() && currentChar != '}') {
        if(currentChar == '=') {
            if(keyword == "texture") {
                graphical->setTexture(assetManagerRef.getTexture(readString()));
            }
            else if(keyword == "textureRect") {
                graphical->setTextureRect(readIntRect());
            }
            else {
                std::cout <<keyword<<" not recognized"<<std::endl;
            }
        }
    }
    return std::move(graphical);
}


component_ptr EntityLoader::readAnimated() {
    std::unique_ptr<Animated> animated(new Animated());
    while(readNextChar() && currentChar != '}') {
        if(currentChar == '=') {
            if(keyword == "animation") {
                animated->setAnimation(assetManagerRef.getAnimation(readString()));
            }
            else if(keyword == "frameTime") {
                animated->setFrameTime(sf::seconds(readFloat()));
            }
            else {
                std::cout <<keyword<<" not recognized"<<std::endl;
            }
        }
    }
    return std::move(animated);
}


component_ptr EntityLoader::readSpatial() {
    std::unique_ptr<Spatial> spatial(new Spatial());
    while(readNextChar() && currentChar != '}') {
        if(currentChar == '=') {
            if(keyword == "position") {
                spatial->setPosition(readVector2f());
            }
            else {
                std::cout <<keyword<<" not recognized"<<std::endl;
            }
        }
    }
    return std::move(spatial);
}


component_ptr EntityLoader::readMovable() {
    std::unique_ptr<Movable> movable(new Movable());
    while(readNextChar() && currentChar != '}') {
        if(currentChar == '=') {
            if(keyword == "velocity") {
                movable->setVelocity(readVector2f());
            }
            else {
                std::cout <<keyword<<" not recognized"<<std::endl;
            }
        }
    }
    return std::move(movable);
}


component_ptr EntityLoader::readCollidable() {
    std::unique_ptr<Collidable> collidable(new Collidable());
    while(readNextChar() && currentChar != '}') {
        if(currentChar == '=') {
            if(keyword == "bounds") {
                collidable->setBounds(readFloatRect());
            }
        }
    }
    return std::move(collidable);
}


component_ptr EntityLoader::readPhysical() {
    std::unique_ptr<Physical> physical(new Physical());
    while(readNextChar() && currentChar != '}') {
        if(currentChar == '=') {
            if(keyword == "restitude") {
                physical->setElasticity(readFloat());
            }
            else if(keyword == "friction") {
                physical->setFriction(readFloat());
            }
            else if(keyword == "mass") {
                physical->setMass(readFloat());
            }
        }
    }
    return std::move(physical);
}


component_ptr EntityLoader::readPlayerControlled() {
    std::unique_ptr<PlayerControlled> control(new PlayerControlled());
    while(readNextChar() && currentChar != '}') {
        if(currentChar == '=') {

        }
    }
    return std::move(control);
}
