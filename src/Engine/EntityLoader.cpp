//
// Created by Ryan on 8/7/2015.
//

#include "Engine/EntityLoader.hpp"
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
    scriptMap.insert(std::make_pair("Collidable", &EntityLoader::readCollidable));
    scriptMap.insert(std::make_pair("Physical", &EntityLoader::readPhysical));

    specialChars = {' ', '\n', '{', '}', '=', '\"', ';'};
    clearChars = {'{', '}', '=', ';', ','};
}

std::unique_ptr<Entity> EntityLoader::loadEntity(std::string filename) {
    std::unique_ptr<Entity> entity(new Entity());
    std::queue<std::string> filesToRead;
    filesToRead.push(filename);
    std::cout <<filename<<std::endl;

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
    std::cout<<std::endl;
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

sf::IntRect EntityLoader::readIntRect() {
    int data[4];
    int count = 0;
    while(readNextChar() && currentChar != ';') {
        if(currentChar == ',') {
            data[count] = std::atoi(keyword.c_str());
            count++;
        }
    }
    data[3] = std::atoi(keyword.c_str());
    return sf::IntRect(data[0], data[1], data[2], data[3]);
}

sf::FloatRect EntityLoader::readFloatRect() {
    float data[4];
    int count = 0;
    while(readNextChar() && currentChar != ';') {
        if(currentChar == ',') {
            data[count] = (float)std::atof(keyword.c_str());
            count++;
        }
    }
    data[3] = (float)std::atof(keyword.c_str());
    return sf::FloatRect(data[0], data[1], data[2], data[3]);
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