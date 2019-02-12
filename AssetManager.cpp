#include "AssetManager.hpp"

namespace Alex
{
	bool AssetManager::LoadTexture(std::string name, std::string fileName) {
		sf::Texture tex;
		
		if (CreateTextureAndBitmask(tex, fileName)) {
			_textures.insert(std::make_pair(name, tex));
			std::cout << "[TEXTURAS]  Size: " << _textures.size() << " | Cargado en memoria: " << name << std::endl;
			return true;
		}
		else return false;
	}

	sf::Texture &AssetManager::GetTexture(std::string name) {
		return this->_textures.at(name);
	}

	bool AssetManager::LoadFont(std::string name, std::string fileName) {
		sf::Font font;

		if (font.loadFromFile(fileName)) {
			_fonts.insert(std::make_pair(name, font));
			std::cout << "[FUENTES]   Size: " << _fonts.size() << " | Cargado en memoria: " << name << std::endl;
			return true;
		}
		else return false;
	}

	sf::Font &AssetManager::GetFont(std::string name) {
		return this->_fonts.at(name);
	}

	bool AssetManager::LoadAudio(std::string name, std::string fileName) {
		sf::SoundBuffer audio;

		if (audio.loadFromFile(fileName)) {
			_audios.insert(std::make_pair(name, audio));
			std::cout << "[AUDIOS]    Size: "<< _audios.size() << " | Cargado en memoria: " << name << std::endl;
			return true;
		}
		else return false;
	}

	sf::SoundBuffer &AssetManager::GetAudio(std::string name) {
		return this->_audios.at(name);
	}
	
	bool AssetManager::LoadConfig(std::string fileName) {
		std::string name, config, line; int startIndex = _cfgLines.size();

		readFile.open(fileName);
		if (readFile.is_open()) {
			while (std::getline(readFile, line)) {
				std::stringstream ss(line);
				while (ss >> config) {
					if (config == "#") { _cfgLines.push_back(line); break; }
					else {
						name = config;
						ss >> config >> config;
						_configs.insert(std::make_pair(name, config));
						_cfgLines.push_back(line);
						break;
					}
				}
			}
			_configs.insert(std::make_pair(fileName, std::to_string(startIndex) + " " +  std::to_string(_cfgLines.size()-1)));
			std::cout << "[CONFIGS]   File name: " << fileName << " | Cargado en memoria: " << _cfgLines.size() - startIndex << " configuraciones" << std::endl;
		}
		else return false;

		readFile.close();

		return true;
	}
	
	const std::string &AssetManager::GetConfig(std::string name) {
		return this->_configs.at(name);
	}
	
	void AssetManager::SaveConfig(std::string name, std::string value) {
		this->_configs[name] = value;
	}
	
	bool AssetManager::SaveConfig(std::string fileName) {
		std::string temp, line; int startIndex = 0; int endIndex = 0;
		if (not this->_configs.count(fileName)) return false;
		temp = this->_configs.at(fileName);
		std::stringstream ss(temp);
		ss >> startIndex >> endIndex;
		
		writeFile.open(fileName);
		if (writeFile.is_open())
		{
			for (int i = startIndex; i <= endIndex; i++) {
				std::stringstream ss(_cfgLines[i]);
				ss >> temp;
				if (temp == "#") writeFile << _cfgLines[i] << std::endl; 
				else writeFile << temp << " : " << this->_configs.at(temp) << std::endl;
			}
		}
		else return false;

		writeFile.close();
		return true;
	}

	void AssetManager::Animate(float dt, sf::Sprite &_Sprite, std::vector<sf::Texture> &_animationFrames, unsigned int &_animationIterator, const float _animationDuration, sf::Clock &_clock)
	{
		if (_clock.getElapsedTime().asSeconds() > _animationDuration / _animationFrames.size())
		{
			if (_animationIterator < _animationFrames.size() - 1) _animationIterator++;
			else _animationIterator = 0;
	
			_Sprite.setTexture(_animationFrames.at(_animationIterator));
			_clock.restart();
		}
	}

	void AssetManager::Animate(float dt, sf::Sprite &_Sprite, const float _animationDuration, sf::Texture &_spriteSheet, const int width, const int height, const int cols, const int rows, sf::Clock &_clock)
	{
		if (_clock.getElapsedTime().asSeconds() > _animationDuration / (cols*rows))
		{
			_spriteHolder.width = width / cols;
			_spriteHolder.height = height / rows;
			
			if (_spriteHolder.left == width - (width / cols))
			{
				_spriteHolder.left = 0;
				if (_spriteHolder.top == height - (height / rows)) _spriteHolder.top = 0;
				else _spriteHolder.top += (height / rows);
			}
			else _spriteHolder.left += (width / cols);

			_Sprite.setTextureRect(_spriteHolder);
			_clock.restart();
		}
	}

}