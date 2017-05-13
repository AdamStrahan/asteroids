
#include <iostream> 
#include "Title.h"
#include "Game.h"




Title::Title()
{
}


Title::~Title()
{
}



void Title::initialise(sf::Font& font)
{
	
	m_font = font;
	// load texture and setup sprite
	if (!m_titleTexture.loadFromFile("ASSETS/IMAGES/splash.png"))
	{
		std::cout << "error with title file";
	}
	m_titleTexture.setRepeated(true);
	m_titleSprite.setTexture(m_titleTexture);
	m_titleSprite.setTextureRect(sf::IntRect(0, 0, static_cast<int>(Game::screenWidth), static_cast<int>(Game::screenHeight)));
	m_titleSprite.setPosition(0, 0);

	//setup message
	m_message.setFont(m_font);
	m_message.setString("Asteroids");
	m_message.setCharacterSize(64);
	m_message.setStyle(sf::Text::Italic);
	m_message.setColor(sf::Color::White);
	
	sf::FloatRect textSize = m_message.getGlobalBounds();
	float xposition = Game::screenWidth / 1.35f - textSize.width / 2;
	m_message.setPosition(xposition, Game::screenHeight * 0.75f);
	m_proceedKeyPressed = false;
}



void Title::processInput(sf::Event event)
{
	if (event.type == sf::Event::KeyPressed)
	{
		if (event.key.code == sf::Keyboard::Space)
		{
			m_proceedKeyPressed = true;
		}
	}
}



void Title::update(sf::Time time)
{
	if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
	{
		m_proceedKeyPressed = true;
	}
	if (m_proceedKeyPressed && timer >= 120)
	{
		Game::gameState = GameState::MainMenu;
	}
	m_proceedKeyPressed = false;
}



void Title::render(sf::RenderWindow& window)
{
	timer++;
	window.draw(m_titleSprite);
	window.draw(m_message);
}