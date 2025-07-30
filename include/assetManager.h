#pragma once
#include "raylib.h"
#include <unordered_map>
#include <string>

class AssetManager
{
private:
  std::unordered_map<std::string, Texture2D *> heroTextures;

public:
  ~AssetManager();

  // Load a texture and store it with a key
  Texture2D *LoadTexture(const std::string &key, const std::string &path);

  // Get a loaded texture by key
  Texture2D *GetTexture(const std::string &key);

  // Unload all textures
  void UnloadAllTextures();
};