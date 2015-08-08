//
// Created by Ryan on 8/7/2015.
//

#include "Engine/EntityLoader.hpp"
#include "Components/Renderable.hpp"
#include "Components/Graphical.hpp"
#include "Components/Animated.hpp"
#include "Components/Spatial.hpp"
#include "Components/Movable.hpp"
#include <stdlib.h>
#include <queue>

EntityLoader::EntityLoader(AssetManager& assetManager)
        : assetManagerRef(assetManager)
{
    scriptMap.insert(std::make_pair("Renderable", &EntityLoader::readRenderable));
    scriptMap.insert(std::make_pair("Graphical", &EntityLoader::readGraphical));
    scriptMap.insert(std::make_pair("Animated", &EntityLoader::readAnimated));
    scriptMap.insert(std::make_pair("Spatial", &EntityLoader::readSpatial));
    scriptMap.insert(std::make_pair("Movable", &EntityLoader::readMovable));
}

std::unique_ptr<Entity> EntityLoader::loadEntity(std::string filename) {
    std::unique_ptr<Entity> entity(new Entity());
    std::queue<std::string> filesToRead;
    filesToRead.push(filename);

    while(!filesToRead.empty()) {
        filename = "../assets/" + filesToRead.back();
        fileReader.open(filename);
        filesToRead.pop();

        if (fileReader.is_open()) {
            std::string keyword;
            while (true) {
                char c; fileReader.get(c);
                if(fileReader.eof()) break;

                if (c == ' ' || c == '\n') { }
                else if (keyword == "include") {
                    if(c == '\"') fileReader.unget();
                    filesToRead.push(readString());
                    keyword = "";
                }
                else if (c == '{') {
                    std::cout <<keyword<<std::endl;
                    compScriptMap::const_iterator it = scriptMap.find(keyword);
                    if (it == scriptMap.end()) {
                        std::cout <<keyword<<" not recognized in "<<filename<<std::endl;
                    }
                    else {
                        readCompScript func = it->second;
                        entity->addComponent((this->*func)());
                    }
                    keyword = "";
                }
                else {
                    keyword += c;
                }
            }
            fileReader.close();
        }
        else {
            std::cout <<"Could not open "<<filename<<std::endl;
        }
    }
    return std::move(entity);
}

float EntityLoader::readFloat() {
    std::string theString;
    char c; fileReader.get(c);
    while(c != ';' && !fileReader.eof()) {
        theString += c;
        fileReader.get(c);
    }
    float f = (float)std::atof(theString.c_str());
    return f;
}

std::string EntityLoader::readString() {
    std::string theString;
    char c; fileReader.get(c);
    while(c != '\"' && !fileReader.eof()) {
        fileReader.get(c);
    }
    fileReader.get(c);
    while(c != '\"' && !fileReader.eof()) {
        theString += c;
        fileReader.get(c);
    }
    return theString;
}

component_ptr EntityLoader::readRenderable() {
    std::unique_ptr<Renderable> renderable(new Renderable());
    std::string keyword;
    char c; fileReader.get(c);
    while(c != '}' && !fileReader.eof()) {
        if (c == ' ' || c == '\n') { }
        else if(c == '=') {
            if(keyword == "zValue") {
                renderable->setZValue(readFloat());
            }
            else {
                std::cout <<keyword<<" not recognized"<<std::endl;
            }
            keyword = "";
        }
        else {
            keyword += c;
        }
        fileReader.get(c);
    }
    return std::move(renderable);
}

component_ptr EntityLoader::readGraphical() {
    std::unique_ptr<Graphical> graphical(new Graphical());
    std::string keyword;
    char c; fileReader.get(c);
    while(c != '}' && !fileReader.eof()) {
        if (c == ' ' || c == '\n') { }
        else if(c == '=') {
            if(keyword == "texture") {
                graphical->setTexture(assetManagerRef.getTexture(readString()));
            }
            else {
                std::cout <<keyword<<" not recognized"<<std::endl;
            }
            keyword = "";
        }
        else {
            keyword += c;
        }
        fileReader.get(c);
    }
    return std::move(graphical);
}

component_ptr EntityLoader::readAnimated() {
    std::unique_ptr<Animated> animated(new Animated());
    std::string keyword;
    char c; fileReader.get(c);
    while(c != '}' && !fileReader.eof()) {
        if (c == ' ' || c == '\n') { }
        else if(c == '=') {
            if(keyword == "animation") {
                animated->setAnimation(assetManagerRef.getAnimation(readString()));
            }
            else if(keyword == "frameTime") {
                animated->setFrameTime(sf::seconds(readFloat()));
            }
            else {
                std::cout <<keyword<<" not recognized"<<std::endl;
            }
            keyword = "";
        }
        else {
            keyword += c;
        }
        fileReader.get(c);
    }
    return std::move(animated);
}

component_ptr EntityLoader::readSpatial() {
    std::unique_ptr<Spatial> spatial(new Spatial());
    std::string keyword;
    char c; fileReader.get(c);
    while(c != '}' && !fileReader.eof()) {
        if (c == ' ' || c == '\n') { }
        else if(c == '=') {
            if(keyword == "positionX") {
                spatial->setPosition(readFloat(), spatial->getPosition().y);
            }
            else if(keyword == "positionY") {
                spatial->setPosition(spatial->getPosition().x, readFloat());
            }
            else {
                std::cout <<keyword<<" not recognized"<<std::endl;
            }
            keyword = "";
        }
        else {
            keyword += c;
        }
        fileReader.get(c);
    }
    return std::move(spatial);
}

component_ptr EntityLoader::readMovable() {
    std::unique_ptr<Movable> movable(new Movable());
    std::string keyword;
    char c; fileReader.get(c);
    while(c != '}' && !fileReader.eof()) {
        if (c == ' ' || c == '\n') { }
        else if(c == '=') {
            if(keyword == "velocityX") {
                movable->setVelocity(sf::Vector2f(readFloat(), movable->getVelocity().y));
            }
            else if(keyword == "velocityY") {
                movable->setVelocity(sf::Vector2f(movable->getVelocity().x, readFloat()));
            }
            else {
                std::cout <<keyword<<" not recognized"<<std::endl;
            }
            keyword = "";
        }
        else {
            keyword += c;
        }
        fileReader.get(c);
    }
    return std::move(movable);
}
