
#ifndef GAMEPLAY_H
#define GAMEPLAY_H

#include <SFML\Graphics.hpp>




class GamePlay
{
public:
	GamePlay();
	~GamePlay();
	void initialise(sf::Font&);
	void render(sf::RenderWindow&);
	void processInput(sf::Event);
	void update(sf::Time);

protected:
	sf::Font m_font;
	sf::Text m_message;
	bool m_proceedKeyPressed;

};

#endif // !GAMEPLAY_H

