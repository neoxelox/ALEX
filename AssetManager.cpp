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
	//DONT USE WORK IN PROGRESS
	bool AssetManager::LoadConfig(std::string fileName) {
		std::string name, config; char h; int startLine = _cfgLines.size() - 1, line = 0;
		readFile.open(fileName);
	
		if (readFile.is_open()) {
			while (!readFile.eof()) {
				readFile >> std::noskipws >> h;
				//TODO:CORREGIR ACCENTOS Y COMENTARIOS
				switch (h)
				{
				case ':':
					name = config;
					config = "";
					break;
				case ',':
					_configs.insert(std::make_pair(name, config));
					_cfgLines.push_back("cfginliner");
					_cfgLines.push_back(config);
					line += 2;
					std::cout << "[CONFIGS]    Size: " << _configs.size() << " | Cargado en memoria: " << name << " = " << config << std::endl;
					name = "";
					config = "";
					break;
				case ';':
					_cfgLines.push_back(config + ";\n");
					line++;
					name = "";
					config = "";
					break;
				case '\n':
					break;
				default:
					config += h;
					break;
				}
			}
			line += startLine;
			_configs.insert(std::make_pair(fileName, std::to_string(startLine) + "/" + std::to_string(line)));
		}
		else return false;

		readFile.close();
		return true;
	}
	//DONT USE WORK IN PROGRESS
	const std::string &AssetManager::GetConfig(std::string name) {
		return this->_configs.at(name);
	}
	//DONT USE WORK IN PROGRESS
	void AssetManager::SaveConfig(std::string name, std::string value) {
		this->_configs.insert(std::make_pair(name, value));
	}
	//DONT USE WORK IN PROGRESS
	bool AssetManager::SaveConfig(std::string fileName) {
		std::string temp, sIndex, eIndex; char h; int startIndex; int endIndex;
		temp = _configs.at(fileName);
		std::getline(std::cin, sIndex, '/');
		std::getline(std::cin, eIndex);
		startIndex = atoi(sIndex.c_str());
		endIndex = atoi(eIndex.c_str());

		writeFile.open(fileName);

		if (writeFile.is_open())
		{
			for (int i = startIndex; i <= endIndex; i++) 
			{
				if (_cfgLines[i] == "cfginliner")
				{
					i++;
					writeFile << _cfgLines[i] + ":" + _configs.at(_cfgLines[i]) + "\n";
				}
				else writeFile << _cfgLines[i];
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