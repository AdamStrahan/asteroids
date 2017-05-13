#ifndef TITLE_H
#define TITLE_H

#include <SFML\Graphics.hpp>


class Title
{
public:
	Title();
	~Title();

	void initialise(sf::Font&);
	void render(sf::RenderWindow&);
	void processInput(sf::Event);
	void update(sf::Time);
	int timer = 0;

protected:
	/// title texure
	sf::Texture m_titleTexture;
	/// title sprite
	sf::Sprite m_titleSprite;
	/// font
	sf::Font m_font;
	/// text to display message
	sf::Text m_message;
	/// used to pass intent from event processing to update loop
	bool m_proceedKeyPressed;
};

#endif // !SPLASHSCREEN_H

