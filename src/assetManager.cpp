#include "assetManager.h"
#include <iostream>

AssetManager::~AssetManager()
{
  UnloadAllTextures();
}

Texture2D *AssetManager::LoadTexture(const std::string &key, const std::string &path)
{
  if (heroTextures.find(key) != heroTextures.end())
  {
    std::cout << "Texture already loaded with key: " << key << std::endl;
    return heroTextures[key];
  }

  Texture2D texture = ::LoadTexture(path.c_str());
  if (texture.id == 0)
  {
    std::cerr << "Failed to load texture: " << path << std::endl;
    return nullptr;
  }

  Texture2D *newTexture = new Texture2D;
  *newTexture = texture;
  heroTextures[key] = newTexture;
  return newTexture;
}

Texture2D *AssetManager::GetTexture(const std::string &key)
{
  auto it = heroTextures.find(key);
  if (it != heroTextures.end())
  {
    return it->second;
  }
  return nullptr;
}

void AssetManager::UnloadAllTextures()
{
  for (auto &pair : heroTextures)
  {
    UnloadTexture(*pair.second);
    delete pair.second;
  }
  heroTextures.clear();
}