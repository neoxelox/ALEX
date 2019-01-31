#pragma once

#include <map>
#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

namespace Alex
{
	class AssetManager
	{
	public:
		AssetManager() {}
		~AssetManager() {}

		void LoadTexture(std::string name, std::string fileName);
		sf::Texture &GetTexture(std::string name);

		void LoadFont(std::string name, std::string fileName);
		sf::Font &GetFont(std::string name);

		void LoadAudio(std::string name, std::string fileName);
		sf::SoundBuffer &GetAudio(std::string name);

		void Animate(float dt, sf::Sprite &_Sprite, std::vector<sf::Texture> &_animationFrames, unsigned int &_animationIterator, const float _animationDuration);

	private:
		std::map<std::string, sf::Texture> _textures;
		std::map<std::string, sf::Font> _fonts;
		std::map<std::string, sf::SoundBuffer> _audios;

		sf::Clock _clock;
	};
}