
#include "AssetManager.h""
#include <assert.h>


AssetManager::AssetManager()
{
	assert(sInstance == nullptr);
	sInstance = this;
}

sf::Texture& AssetManager::GetTexture(std::string const& filename)
{
	auto& texMap = sInstance->m_Texture;

	//See if the texture is already loaded
	auto pairFound = texMap.find(filename);

	//if yes,reutrn the texture
	if (pairFound != texMap.end())
		return pairFound->second;

	else  //else load the texture and return it
	{
		//create an element in the texture map
		auto& texture = texMap[filename];
		texture.loadFromFile(filename);
		return texture;
	}
}

sf::SoundBuffer& AssetManager::GetSoundBuffer(std::string const& filename)
{
	auto& sBufferMap = sInstance->m_SoundBuffer;

	auto pairFound = sBufferMap.find(filename);
	if (pairFound != sBufferMap.end())
	{
		return pairFound->second;
	}
	else
	{
		auto& sBuffer = sBufferMap[filename];
		sBuffer.loadFromFile(filename);
		return sBuffer;
	}
}

sf::Font& AssetManager::GetFont(std::string const& filename)
{
	auto& fontMap = sInstance->m_Font;

	auto pairFound = fontMap.find(filename);
	if (pairFound != fontMap.end())
	{
		return pairFound->second;
	}
	else
	{
		auto& font = fontMap[filename];
		font.loadFromFile(filename);
		return font;
	}
}
AssetManager* AssetManager::sInstance = NULL;