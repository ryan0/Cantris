//
// Created by Ryan on 8/7/2015.
//

#include "Engine/EntityLoader.hpp"
#include "Components/Renderable.hpp"
#include "Components/Graphical.hpp"
#include "Components/Animated.hpp"
#include "Components/Spatial.hpp"
#include "Components/Movable.hpp"
#include "Components/Physical.hpp"
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
    scriptMap.insert(std::make_pair("Physical", &EntityLoader::readPhysical));

    specialChars = {' ', '\n', '{', '}', '=', '\"', ';'};
    clearChars = {'{', '}', '=', ';', ','};
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
            while (readNextChar()) {
                if (currentChar == '=' && keyword == "include") {
                    filesToRead.push(readString());
                }
                else if (currentChar == '{') {
                    std::cout <<keyword<<std::endl;
                    compScriptMap::const_iterator it = scriptMap.find(keyword);
                    if (it == scriptMap.end()) {
                        std::cout <<keyword<<" not recognized in "<<filename<<std::endl;
                    }
                    else {
                        readCompScript func = it->second;
                        entity->addComponent((this->*func)());
                    }
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

bool EntityLoader::readNextChar() {
    if (std::find(clearChars.begin(), clearChars.end(), currentChar) != clearChars.end()) {
        keyword = "";
    }
    fileReader.get(currentChar);
    if(fileReader.eof()) {
        return false;
    }
    if (std::find(specialChars.begin(), specialChars.end(), currentChar) == specialChars.end()) {
        keyword += currentChar;
    }
    return true;
}

float EntityLoader::readFloat() {
    while(readNextChar() && currentChar != ';') {}
    float f = (float)std::atof(keyword.c_str());
    return f;
}


sf::Vector2f EntityLoader::readVector2f() {
    float x, y;
    while(readNextChar() && currentChar != ';') {
        if(currentChar == ',') {
            x = (float)std::atof(keyword.c_str());
        }
    }
    y = (float)std::atof(keyword.c_str());
    return sf::Vector2f(x, y);
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


component_ptr EntityLoader::readPhysical() {
    std::unique_ptr<Physical> physical(new Physical());
    while(readNextChar() && currentChar != '}') {
        if(currentChar == '=') {

        }
    }
    return std::move(physical);
}
