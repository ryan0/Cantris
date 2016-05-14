//
// Created by Ryan on 8/1/2015.
//

#ifndef RAINSFORD_ASSETMANAGER_HPP
#define RAINSFORD_ASSETMANAGER_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <Box2D/Box2D.h>
#include <unordered_map>
#include <string>

#include "Animation.hpp"

class AssetManager {
public:
    const sf::Texture& getTexture(std::string filename);
    const Animation& getAnimation(std::string filename, std::string name);
    const sf::SoundBuffer& getSoundBuffer(std::string filename);
    void playSong(std::string filename);

private:
    std::unordered_map<std::string, sf::Texture> textures;
    std::unordered_map<std::string, Animation> animations;
    std::unordered_map<std::string, sf::SoundBuffer> soundBuffers;
    sf::Music music;
};

#endif //RAINSFORD_ASSETMANAGER_HPP
