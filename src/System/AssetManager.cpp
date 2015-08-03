//
// Created by Ryan on 8/2/2015.
//

#include "System/AssetManager.hpp"
#include <iostream>

const sf::Texture &AssetManager::getTexture(std::string filename) {
    filename = "../assets/" + filename;
    if(textures.count(filename)) {
        return textures[filename];
    }
    else {
        sf::Texture tex;
        if(!tex.loadFromFile(filename)) {
            std::cout<<"Failed to load texture from "<<filename<<std::endl;
        }
        textures[filename] = tex;
        return textures[filename];
    }
}

const sf::SoundBuffer &AssetManager::getSoundBuffer(std::string filename) {
    filename = "../assets/" + filename;
    if(soundBuffers.count(filename)) {
        return soundBuffers[filename];
    }
    else {
        sf::SoundBuffer buffer;
        if(!buffer.loadFromFile(filename)) {
            std::cout<<"Failed to load SoundBuffer texture from "<<filename<<std::endl;
        }
        soundBuffers[filename] = buffer;
        return soundBuffers[filename];
    }
}

void AssetManager::playSong(std::string filename) {
    filename = "../assets/" + filename;
    if (!music.openFromFile(filename)) {
        std::cout << "Failed to load musicgay texture from " << filename << std::endl;
    }
    music.setLoop(true);
    music.play();
}
