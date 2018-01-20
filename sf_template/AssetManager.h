#ifndef  ASSET_MANAGER_H
#define  ASSET_MANAGER_H

#include <SFML\Graphics.hpp>
#include <SFML/Audio.hpp>
#include <map>

class AssetManager
{
public:
	AssetManager();

	static sf::Texture& GetTexture(std::string const& filename);
	static sf::SoundBuffer& GetSoundBuffer(std::string const& filename);
	static sf::Font& GetFont(std::string const& filename);

private:
	std::map<std::string, sf::Texture> m_Texture;
	std::map<std::string, sf::SoundBuffer> m_SoundBuffer;
	std::map<std::string, sf::Font>m_Font;
	static AssetManager* sInstance;
};

#endif


