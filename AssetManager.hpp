#pragma once

#include <map>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Physics.hpp"

namespace Alex
{
	class AssetManager
	{
	public:
		AssetManager() {}
		~AssetManager() {}

		bool LoadTexture(std::string name, std::string fileName);
		sf::Texture &GetTexture(std::string name);

		bool LoadFont(std::string name, std::string fileName);
		sf::Font &GetFont(std::string name);

		bool LoadAudio(std::string name, std::string fileName);
		sf::SoundBuffer &GetAudio(std::string name);

		bool LoadConfig(std::string fileName);
		const std::string &GetConfig(std::string name);
		void SaveConfig(std::string name, std::string value);
		bool SaveConfig(std::string fileName);

		void Animate(float dt, sf::Sprite &_Sprite, std::vector<sf::Texture> &_animationFrames, unsigned int &_animationIterator, const float _animationDuration, sf::Clock &_clock);
		void Animate(float dt, sf::Sprite &_Sprite, const float _animationDuration, sf::Texture &_spriteSheet, const int width, const int height, const int cols, const int rows, sf::Clock &_clock);
		
	private:
		std::map<std::string, sf::Texture> _textures;
		std::map<std::string, sf::Font> _fonts;
		std::map<std::string, sf::SoundBuffer> _audios;

		std::map<std::string, std::string> _configs;
		std::vector<std::string> _cfgLines;
		
		std::ifstream readFile;
		std::ofstream writeFile;

		sf::IntRect _spriteHolder;
	};
}