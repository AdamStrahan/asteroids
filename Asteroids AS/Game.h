// Name: Adam Strahan
// No.: C00216499
// Time: Many Hours
// Asteroids project


#ifndef GAME_H
#define GAME_H
#include <stdio.h>
#include <tchar.h>

#include "Menu.h"
#include "Help.h"
#include "Gameplay.h"
#include "Opening.h"
#include "Title.h"

enum class
	GameState
{
	None,
	Opening,
	Title,
	MainMenu,
	HelpPage,
	Game,
};

class Game
{
public:
	Game();
	void run();

	//	static properties accessed by all classes
	/// width of the screen
	static float screenWidth;
	/// screen height
	static float screenHeight;
	/// current game state
	static GameState gameState;

protected:
	void	processEvents();
	void	update(sf::Time);
	void	render();
	void	loadContent();

	/// /// font variable
	sf::Font m_arialFont;
	/// screen variable
	sf::RenderWindow m_Window;

	//instances of classes used to handle the different behaviours needed in the complete game
	/// instance used to run opening screen
	Opening m_opening;
	/// instance used to run title screen
	Title m_title;
	/// instance used to run main menu
	Menu m_mainMenu;
	/// instance used for help menu
	HelpPage m_helpPage;
	//instance used for GamePlay
	GamePlay m_gamePlay;


};
#endif // !GAME_H
