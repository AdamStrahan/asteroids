
#include <iostream> 
#include "Opening.h"
#include "Game.h"




Opening::Opening()
{
}


Opening::~Opening()
{
}



void Opening::initialise(sf::Font& font)
{
	m_font = font;
	// load texture and setup sprite
	if (!m_openingTexture.loadFromFile("ASSETS/IMAGES/planet0.png"))
	{
		std::cout << "error with  splash file";
	}
	m_openingTexture.setRepeated(true);
	m_openingSprite.setTexture(m_openingTexture);
	m_openingSprite.setTextureRect(sf::IntRect(0, 0, static_cast<int>(Game::screenWidth), static_cast<int>(Game::screenHeight)));
	m_openingSprite.setPosition(0, 0);

	//setup message
	m_message.setFont(m_font);
	m_message.setString("By: Adam Strahan");
	m_message.setCharacterSize(64);
	m_message.setStyle(sf::Text::Italic);
	m_message.setColor(sf::Color::White);

	sf::FloatRect textSize = m_message.getGlobalBounds();
	float xposition = Game::screenWidth / 2 - textSize.width / 2;
	m_message.setPosition(xposition, Game::screenHeight * 0.45f);
	m_proceedKeyPressed = false;
}



void Opening::processInput(sf::Event event)
{
	if (event.type == sf::Event::KeyPressed)
	{
		if (event.key.code == sf::Keyboard::Space)
		{
			m_proceedKeyPressed = true;
		}
	}
}



void Opening::update(sf::Time time)
{
	if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
	{
		m_proceedKeyPressed = true;
	}
	if (m_proceedKeyPressed)
	{
		Game::gameState = GameState::Title;
	}
	m_proceedKeyPressed = false;
}



void Opening::render(sf::RenderWindow& window)
{
	window.draw(m_openingSprite);
	window.draw(m_message);
}