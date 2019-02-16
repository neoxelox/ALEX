#include "ExampleObject.hpp"

namespace Alex
{
	ExampleObject::ExampleObject(GameDataRef data) : _data(data)
	{
		_ExampleObjectSprite.setTexture(this->_data->assets.GetTexture("Splash State Background"));
	}
	
	const sf::Sprite &ExampleObject::GetSprite() const
	{
		return _ExampleObjectSprite;
	}
	
	void ExampleObject::Update(float dt)
	{
		
	}
	
	void ExampleObject::Draw()
	{
		this->_data->window.draw(_ExampleObjectSprite);
	}
}