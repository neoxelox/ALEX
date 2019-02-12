#include <sstream>
#include <iostream>
#include "SplashState.hpp"
#include "DEFINITIONS.hpp"

namespace Alex {
	SplashState::SplashState(GameDataRef data) : _data(data) 
	{

	}

	void SplashState::Init()
	{
		//-->>>LOAD BIG MEMORY ASSETS<<<--
		this->_data->assets.LoadAudio("Hit", HIT_SOUND_FILEPATH);
		this->_data->assets.LoadAudio("Wing", WING_SOUND_FILEPATH);
		this->_data->assets.LoadAudio("Point", POINT_SOUND_FILEPATH);
		//<------------------------------>

		//-->**********[LOAD]**********<--
		this->_data->assets.LoadTexture("Splash State Background", SPLASH_SCENE_BACKGROUND_FILEPATH);
		//<------------------------------>

		//-->**********[SET]***********<--
		_background.setTexture(this->_data->assets.GetTexture("Splash State Background"));
		//<------------------------------>

		//-->*******[INITIALIZE]*******<--
		_background.setOrigin(_background.getGlobalBounds().width / 2, _background.getGlobalBounds().height / 2);
		_background.setPosition(this->_data->window.getSize().x / 2, this->_data->window.getSize().y / 2);
		//<------------------------------>
	}

	void SplashState::HandleInput()
	{
		//-->*********[MOUSE-FAST]********<--
		//<--------------------------------->

		//-->*******[KEYBOARD-FAST]*******<--
		//<--------------------------------->
		
		sf::Event event;
		while (this->_data->window.pollEvent(event)) 
		{
			switch (event.type)
			{
			//-->**********[WINDOWS]**********<--
			case sf::Event::Closed: this->_data->window.close(); break;
			//<--------------------------------->
			default: break;
			}

			//-->***********[MOUSE]***********<--
			//<--------------------------------->

			//-->*********[KEYBOARD]**********<--
			//<--------------------------------->			
		}
	}

	void SplashState::Update(float dt)
	{
		if (this->_clock.getElapsedTime().asSeconds() > SPLASH_STATE_SHOW_TIME)
		{
			//Change Screen
			//this->_data->machine.AddState(StateRef(new MainMenuState(_data)), true);
		}
	}

	void SplashState::Draw(float dt) 
	{
		//-->********[PRE-RENDER]********<--
		this->_data->window.clear();
		this->_data->window.draw(this->_background);
		//<-------------------------------->

		//-->**********[RENDER]**********<--
		//<-------------------------------->

		//-->********[POS-RENDER]********<--
		this->_data->window.display();
		glFinish();
		//<-------------------------------->
	}
}