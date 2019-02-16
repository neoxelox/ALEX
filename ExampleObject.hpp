#pragma once

#include <SFML/Graphics.hpp>
#include "DEFINITIONS.hpp"
#include "Game.hpp"

namespace Alex
{
	class ExampleObject
	{
	public:
		ExampleObject(GameDataRef data);
		
		void Draw();
		void Update(float dt);
		const sf::Sprite &GetSprite() const;

	private:
		GameDataRef _data;
		sf::Clock _clock;
		sf::Sprite _ExampleObjectSprite;
	};
}