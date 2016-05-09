//
// Created by Ryan on 5/3/2016.
//

#ifndef RAINSFORD_LUASCENELOADER_HPP
#define RAINSFORD_LUASCENELOADER_HPP

#include "Core/AssetManager.hpp"
#include "Engine/LuaEntityLoader.hpp"
#include "Engine/Scene.hpp"

class LuaSceneLoader {
public:
    LuaSceneLoader(AssetManager& assetManager);
    std::unique_ptr<Scene> loadScene(std::string luafile);
private:
    AssetManager& assetManagerRef;
};

#endif //RAINSFORD_LUASCENELOADER_HPP
