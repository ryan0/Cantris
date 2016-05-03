//
// Created by Ryan on 8/2/2015.
//

#include "Core/AssetManager.hpp"
#include <iostream>
#include <fstream>
#include "selene.h"

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

const Animation &AssetManager::getAnimation(std::string filename) {
    filename = "../assets/" + filename;
    if(animations.count(filename)) {
        return animations[filename];
    }
    else {
        Animation animation;
        std::ifstream file(filename);
        if (file.is_open()) {
            std::string texFile;
            std::getline(file, texFile);
            animation.setSpriteSheet(getTexture("../assets/" + texFile));

            int frameWidth, frameHeight;
            int frameRow, firstFrame, lastFrame;
            file >> frameWidth;
            file >> frameHeight;
            file >> frameRow;
            file >> firstFrame;
            file >> lastFrame;
            for (int i = firstFrame; i < lastFrame + 1; ++i) {
                animation.addFrame(sf::IntRect(frameWidth * i, frameRow * frameHeight, frameWidth, frameHeight));
            }
            file.close();
        }
        else {
            std::cout << "Unable to open " << filename << std::endl;
        }
        animations[filename] = animation;
        return animations[filename];
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
