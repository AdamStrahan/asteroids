
#ifdef _DEBUG 
#pragma comment(lib,"sfml-graphics-d.lib") 
#pragma comment(lib,"sfml-audio-d.lib") 
#pragma comment(lib,"sfml-system-d.lib") 
#pragma comment(lib,"sfml-window-d.lib") 
#pragma comment(lib,"sfml-main-d.lib")
#pragma comment(lib,"sfml-network-d.lib") 
#else 
#pragma comment(lib,"sfml-graphics.lib") 
#pragma comment(lib,"sfml-audio.lib") 
#pragma comment(lib,"sfml-system.lib") 
#pragma comment(lib,"sfml-main.lib")
#pragma comment(lib,"sfml-window.lib") 
#pragma comment(lib,"sfml-network.lib") 
#endif 
#pragma comment(lib,"opengl32.lib") 
#pragma comment(lib,"glu32.lib") 

#include <SFML/Graphics.hpp>
#include "SFML/OpenGL.hpp" 
#include <iostream> 
#include <math.h>

#include "Game.h"


int main()
{
	Game game;
	game.run();
}

float Game::screenWidth = 600;
float Game::screenHeight = 400;
GameState Game::gameState = GameState::Opening;


Game::Game() : m_Window(sf::VideoMode(static_cast<int>(Game::screenWidth), static_cast<int>(Game::screenHeight)), "SMFL Game", sf::Style::Default)
{
	loadContent();
	m_Window.setKeyRepeatEnabled(false);
}

void Game::loadContent()
{

	if (!m_arialFont.loadFromFile("ASSETS/FONTS/BebasNeue.otf"))
	{
		std::cout << "error with font file file";
	}



	m_opening.initialise(m_arialFont);
	m_title.initialise(m_arialFont);
	m_gamePlay.initialise(m_arialFont);
	m_mainMenu.initialise(m_arialFont);
	m_helpPage.initialise(m_arialFont);

}


void Game::run()
{
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	sf::Time timePerFrame = sf::seconds(1.f / 60.f);
	while (m_Window.isOpen())
	{
		processEvents();
		timeSinceLastUpdate += clock.restart();
		while (timeSinceLastUpdate > timePerFrame)
		{
			timeSinceLastUpdate -= timePerFrame;

			processEvents();
			update(timePerFrame);
		}
		render();

	}
}

void Game::processEvents()
{
	sf::Event event;
	while (m_Window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			m_Window.close();
		}
		switch (gameState)
		{
		case GameState::Opening:
			m_opening.processInput(event);
			break;
		case GameState::Title:
			m_title.processInput(event);
			break;
		case GameState::MainMenu:
			break;
		case GameState::HelpPage:
			m_helpPage.processInput(event);
			break;
		case GameState::Game:
			m_gamePlay.processInput(event);
			break;
		default:
			break;
		}
	}
}

void Game::update(sf::Time time)
{
	switch (gameState)
	{
	case GameState::Opening:
		m_opening.update(time);
		break;
	case GameState::Title:
		m_title.update(time);
		break;
	case GameState::MainMenu:
		m_mainMenu.update(time, m_Window);
		break;
	case GameState::HelpPage:
		m_helpPage.update(time);
		break;
	case GameState::Game:
		m_gamePlay.update(time);
		break;
	default:
		break;
	}
}


void Game::render()
{
	m_Window.clear();
	switch (gameState)
	{
	case GameState::Opening:
		m_opening.render(m_Window);
		break;
	case GameState::Title:
		m_title.render(m_Window);
		break;
	case GameState::MainMenu:
		m_mainMenu.render(m_Window);
		break;
	case GameState::HelpPage:
		m_helpPage.render(m_Window);
		break;
	case GameState::Game:
		m_gamePlay.render(m_Window);
		break;
	default:
		break;
	}
	m_Window.display();
}