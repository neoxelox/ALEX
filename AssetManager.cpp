#include "AssetManager.hpp"
#include "Physics.hpp"
#include <iostream>

namespace Alex
{
	void AssetManager::LoadTexture(std::string name, std::string fileName) {
		sf::Texture tex;
		
		if (CreateTextureAndBitmask(tex, fileName)) {
			this->_textures[name] = tex;
			std::cout << "[TEXTURAS]  Size: " << _textures.size() << " | Cargado en memoria: " << name << std::endl;
		}
	}

	sf::Texture &AssetManager::GetTexture(std::string name) {
		return this->_textures.at(name);
	}

	void AssetManager::LoadFont(std::string name, std::string fileName) {
		sf::Font font;

		if (font.loadFromFile(fileName)) {
			this->_fonts[name] = font;
			std::cout << "[FUENTES]   Size: " << _fonts.size() << " | Cargado en memoria: " << name << std::endl;
		}
	}

	sf::Font &AssetManager::GetFont(std::string name) {
		return this->_fonts.at(name);
	}

	void AssetManager::LoadAudio(std::string name, std::string fileName) {
		sf::SoundBuffer audio;

		if (audio.loadFromFile(fileName)) {
			this->_audios[name] = audio;
			std::cout << "[AUDIOS]    Size: "<< _audios.size() << " | Cargado en memoria: " << name << std::endl;
		}
	}

	sf::SoundBuffer &AssetManager::GetAudio(std::string name) {
		return this->_audios.at(name);
	}

	void AssetManager::Animate(float dt, sf::Sprite &_Sprite, std::vector<sf::Texture> &_animationFrames, unsigned int &_animationIterator, const float _animationDuration)
	{
		if (_clock.getElapsedTime().asSeconds() > _animationDuration / _animationFrames.size())
		{
			if (_animationIterator < _animationFrames.size() - 1)
			{
				_animationIterator++;
			}
			else
			{
				_animationIterator = 0;
			}

			_Sprite.setTexture(_animationFrames.at(_animationIterator));
			_clock.restart();
		}
	}
}