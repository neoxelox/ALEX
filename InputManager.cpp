#include "InputManager.hpp"

namespace Alex
{
	bool InputManager::IsSpriteClicked(sf::Sprite object, sf::Mouse::Button button, sf::RenderWindow &window) {
		if (sf::Mouse::isButtonPressed(button)) if (object.getGlobalBounds().contains(GetMousePosition(window))) return true;
		return false;
	}

	bool InputManager::IsSpriteHovering(sf::Sprite object, sf::RenderWindow &window) {
		if (object.getGlobalBounds().contains(GetMousePosition(window))) return true;
		return false;
	}

	sf::Vector2f InputManager::GetMousePosition(sf::RenderWindow &window) {
		return sf::Vector2f(float(sf::Mouse::getPosition(window).x), float(sf::Mouse::getPosition(window).y));
	}
}