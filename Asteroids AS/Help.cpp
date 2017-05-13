#include "Help.h"
#include "Game.h"
#include <iostream>

HelpPage::HelpPage()
{
}

HelpPage::~HelpPage()
{
}

void HelpPage::initialise(sf::Font& font)
{
	m_font = font;

	m_message.setFont(m_font);
	m_message.setString("INFORMATION \nThe goal of the game is to manoeuvre your ship \naround the asteroids and avoid colliding with them. \n \nControls \nArrow keys : Move ship \n \npress space to return to menu");
	m_message.setCharacterSize(24);
	m_message.setColor(sf::Color::White);

	sf::FloatRect textSize = m_message.getGlobalBounds();
	float xposition = Game::screenWidth / 2 - textSize.width / 2;
	m_message.setPosition(xposition, Game::screenHeight * 0.15f);
	m_quitPressed = false;
}

void HelpPage::processInput(sf::Event event)
{
	if (event.type == sf::Event::KeyPressed)
	{
		if (event.key.code == sf::Keyboard::Space)
		{
			m_quitPressed = true;
		}
	}
}

void HelpPage::update(sf::Time time)
{
	if (m_quitPressed)
	{
		Game::gameState = GameState::MainMenu;
	}
	m_quitPressed = false;
}

void HelpPage::render(sf::RenderWindow& window)
{
	window.draw(m_message);
}