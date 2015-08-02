//
// Created by Ryan on 8/1/2015.
//

#ifndef RAINSFORD_ASSETMANAGER_HPP
#define RAINSFORD_ASSETMANAGER_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <unordered_map>
#include <string>

class AssetManager {
public:
    const sf::Texture& getTexture(std::string filename);
    const sf::SoundBuffer& getSoundBuffer(std::string filename);
    const sf::Music& getMusic(std::string filename);

private:
    std::unordered_map<std::string, sf::Texture> textures;
    std::unordered_map<std::string, sf::SoundBuffer> soundBuffers;
    std::unordered_map<std::string, sf::Music> music;
};

#endif //RAINSFORD_ASSETMANAGER_HPP
