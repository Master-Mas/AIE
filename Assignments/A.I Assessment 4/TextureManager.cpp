#include "TextureManager.h"

TextureManager::TextureManager()
{
	loadTexture("nodeBlue");
	loadTexture("nodeGreen");
	loadTexture("nodeRed");
}

TextureManager::~TextureManager()
{
	for (std::map<int, Texture*>::iterator it = textures.begin(); it != textures.end(); ++it)
	{
		delete it->second;
	}

	textures.clear();
}

void TextureManager::releaseTexture(int id)
{
	delete (textures.find(id)->second);
	textures.erase(id);
}

Texture * TextureManager::getTexture(int id)
{
	return textures.find(id)->second;
}

bool TextureManager::textureExists(int id)
{
	if (textures.find(id) == textures.end()) 
	{
		return false;
	}
	else
	{
		return true;
	}
}

int TextureManager::loadTexture(std::string name)
{
	std::stringstream ss;
	ss << "./bin/textures/" << name << ".png";
	Texture* temp = new Texture(ss.str().c_str());
	int tempID = id++;
	textures.insert(std::pair<int, Texture*>(tempID, temp));
	return tempID;
}


