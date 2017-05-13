
#include <iostream> 
#include "Menu.h"
#include "Game.h"




Menu::Menu()
{
}


Menu::~Menu()
{
}



void Menu::initialise(sf::Font& font)
{
	m_spaceTop = 130;
	m_spaceButtons = 90;
	m_buttonWidth = 200;
	m_spaceLeft = (Game::screenWidth - m_buttonWidth) / 2;
	m_buttonHeight = 50;
	int textDropOffset = 10;
	sf::String m_menuTexts[] = { "Start", "Help", "Quit" };

	m_font = font;

	//setup message
	m_name.setFont(m_font);
	m_name.setString("Asteroids");
	m_name.setCharacterSize(68);
	m_name.setStyle(sf::Text::Bold);
	m_name.setColor(sf::Color::White);
	
	sf::FloatRect textSize = m_name.getGlobalBounds();
	float xposition = Game::screenWidth / 2 - textSize.width / 2;
	m_name.setPosition(xposition, Game::screenHeight * 0.05f);

	if (!m_buttonTexture.loadFromFile("ASSETS/IMAGES/button.png"))
	{
		std::cout << "error with button file";
	}
	for (int i = 0; i < m_buttons; i++)
	{
		m_buttonSprites[i].setTexture(m_buttonTexture);
		m_buttonSprites[i].setPosition(m_spaceLeft, m_spaceButtons * i + m_spaceTop);
		sf::Vector2u textureSize = m_buttonTexture.getSize();
		m_buttonSprites[i].setScale(m_buttonWidth / textureSize.x, m_buttonHeight / textureSize.y);

		m_buttonText[i].setFont(m_font);
		m_buttonText[i].setString(m_menuTexts[i]);
		m_buttonText[i].setColor(sf::Color::White);
		m_buttonText[i].setCharacterSize(24);
		sf::FloatRect textSize = m_buttonText[i].getGlobalBounds();
		float textOffset = (m_buttonWidth - textSize.width) / 2;
		m_buttonText[i].setPosition(m_spaceLeft + textOffset, m_spaceButtons * i + m_spaceTop + textDropOffset);
	}
}



void Menu::update(sf::Time time, sf::Window& window)
{
	if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
	{
		sf::Vector2i mouseLocation;
		mouseLocation = sf::Mouse::getPosition(window);
		if (mouseLocation.x > m_spaceLeft && mouseLocation.x < m_spaceLeft + m_buttonWidth)
		{
			if (mouseLocation.y > m_spaceTop && mouseLocation.y && mouseLocation.y <  m_spaceTop + m_buttonHeight)
			{
				Game::gameState = GameState::Game;
			}
			if (mouseLocation.y > m_spaceTop + m_spaceButtons && mouseLocation.y <  m_spaceTop + m_spaceButtons + m_buttonHeight)
			{
				Game::gameState = GameState::HelpPage;
			}
			if (mouseLocation.y > m_spaceTop + m_spaceButtons * 2 && mouseLocation.y <  m_spaceTop + m_spaceButtons * 2 + m_buttonHeight)
			{
				window.close();
			}
		}
	}
}


void Menu::render(sf::RenderWindow& window)
{
	for (int i = 0; i < m_buttons; i++)
	{
		window.draw(m_menuSprite);
		window.draw(m_name);
		window.draw(m_buttonSprites[i]);
		window.draw(m_buttonText[i]);
	}
}