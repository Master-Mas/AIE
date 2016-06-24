#pragma once

#include <map>
#include <sstream> 
#include "src/Texture.h";

class TextureManager
{
public:
	TextureManager();
	~TextureManager();

	void releaseTexture(int id);
	Texture* getTexture(int id);
	bool textureExists(int id);
	int loadTexture(std::string name);

private:
	std::map<int, Texture*> textures;
	int id = 0;
};

