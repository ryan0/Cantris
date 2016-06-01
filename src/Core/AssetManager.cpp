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

const Animation& AssetManager::getAnimation(std::string filename, std::string name) {
    filename = "../lua/animations/" + filename;
    if(animations.count(filename + name)) {
        return animations[filename + name];
    }
    else {
        Animation animation;
        sel::State luaState;
        luaState.Load(filename);

        if (luaState["file"] == true) {
            std::string spriteSheet = luaState["file"];
            animation.setSpriteSheet(getTexture("../assets/" + spriteSheet));
        }

        if (luaState[name.c_str()] == true) {
            sel::Selector selector = luaState[name.c_str()];
            if (luaState["file"] == true) {
                std::string spriteSheet = luaState["file"];
                animation.setSpriteSheet(getTexture("../assets/" + spriteSheet));
            }
            int frameWidth, frameHeight;
            int margin = 0, spacing = 0, row = 0, first, last;

            frameWidth = selector["frameWidth"];
            frameHeight = selector["frameHeight"];
            if(selector["row"] == true) {
                row = selector["row"];
                first = selector["first"];
                last = selector["last"];

                if(selector["margin"] == true) {
                    margin = selector["margin"];
                }
                if(selector["spacing"] == true) {
                    spacing = selector["spacing"];
                }

                if(last >= first) {
                    for (int i = (first - 1); i < last; ++i) {
                        animation.addFrame(
                                sf::IntRect(frameWidth * i + spacing * i + margin, (row - 1) * frameHeight + spacing * (row - 1) + margin, frameWidth, frameHeight));
                    }
                }
                else {
                    for (int i = (first - 1); i >= (last-1); --i) {
                        animation.addFrame(
                                sf::IntRect(frameWidth * i + spacing * i + margin, (row - 1) * frameHeight + spacing * (row - 1) + margin, frameWidth, frameHeight));
                    }
                }
            }
            else {
                int count = 1;
                while(selector[count] == true) {
                    std::cout<<count<<std::endl;
                    row = selector[count]["row"];
                    first = selector[count]["first"];
                    last = selector[count]["last"];

                    if(last >= first) {
                        for (int i = (first - 1); i < last; ++i) {
                            animation.addFrame(
                                    sf::IntRect(frameWidth * i + spacing * i + margin, (row - 1) * frameHeight + spacing * (row - 1) + margin, frameWidth, frameHeight));
                        }
                    }
                    else {
                        for (int i = (first - 1); i >= (last-1); --i) {
                            animation.addFrame(
                                    sf::IntRect(frameWidth * i + spacing * i + margin, (row - 1) * frameHeight + spacing * (row - 1) + margin, frameWidth, frameHeight));
                        }
                    }
                    count++;
                }
            }

            animations[filename + name] = animation;
            return animations[filename + name];
        }
    }
    std::cout<<"Unable to find animation:"<<name<<" in file:"<<filename<<std::endl;
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
