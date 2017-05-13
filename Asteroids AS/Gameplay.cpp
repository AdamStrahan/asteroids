

#include "Gameplay.h"
#include "Game.h"
#include <iostream>



GamePlay::GamePlay()
{
}


GamePlay::~GamePlay()
{
}


void GamePlay::initialise(sf::Font& font)
{
	m_font = font;

	m_message.setFont(m_font);
	m_message.setString("couldn't get this working \n press space to return to menu");
	m_message.setCharacterSize(24);
	m_message.setColor(sf::Color::White);

	sf::FloatRect textSize = m_message.getGlobalBounds();
	float xposition = Game::screenWidth / 2 - textSize.width / 2;
	m_message.setPosition(xposition, Game::screenHeight * 0.25f);

	m_proceedKeyPressed = false;

}

void GamePlay::processInput(sf::Event event)
{
	if (event.type == sf::Event::KeyPressed)
	{
		if (event.key.code == sf::Keyboard::Space)
		{
			m_proceedKeyPressed = true;
		}
	}
}

void GamePlay::update(sf::Time time)
{
	if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Right))
	{
		m_proceedKeyPressed = true;
	}
	if (m_proceedKeyPressed)
	{
		Game::gameState = GameState::MainMenu;
	}
	m_proceedKeyPressed = false;

}

void GamePlay::render(sf::RenderWindow& window)
{
	window.draw(m_message);

}