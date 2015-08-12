//
// Created by Ryan on 8/7/2015.
//

#ifndef RAINSFORD_ENTITYLOADER_HPP
#define RAINSFORD_ENTITYLOADER_HPP

#include <iostream>
#include <fstream>
#include <memory>
#include <string>
#include <memory>
#include <map>
#include "Entity.hpp"
#include "Components/Component.hpp"
#include "Core/AssetManager.hpp"


class EntityLoader {
public:
    EntityLoader(AssetManager& assetManager);
    std::unique_ptr<Entity> loadEntity(std::string filename);

private:
    typedef component_ptr (EntityLoader::*readCompScript) ();
    typedef std::map<std::string, readCompScript> compScriptMap;
    std::vector<char> specialChars;
    std::vector<char> clearChars;
    AssetManager& assetManagerRef;
    compScriptMap scriptMap;
    std::ifstream fileReader;
    std::string unfinishedWord;
    std::string keyword;
    char currentChar;

    bool readNextChar();
    float readFloat();
    sf::Vector2f readVector2f();
    sf::IntRect readIntRect();
    sf::FloatRect readFloatRect();
    std::string readString();

    component_ptr readRenderable();
    component_ptr readGraphical();
    component_ptr readAnimated();
    component_ptr readSpatial();
    component_ptr readMovable();
    component_ptr readCollidable();
    component_ptr readPhysical();
    component_ptr readPlayerControlled();
};

#endif //RAINSFORD_ENTITYLOADER_HPP
