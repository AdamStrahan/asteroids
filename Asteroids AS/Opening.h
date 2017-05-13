#ifndef SPLASHSCREEN_H
#define SPLASHSCREEN_H

#include <SFML\Graphics.hpp>


class Opening
{
public:
	Opening();
	~Opening();

	void initialise(sf::Font&);
	void render(sf::RenderWindow&);
	void processInput(sf::Event);
	void update(sf::Time);

protected:
	/// opening texture
	sf::Texture m_openingTexture;
	/// opening sprite
	sf::Sprite m_openingSprite;
	/// font
	sf::Font m_font;
	/// text to display press space message
	sf::Text m_message;
	/// used to pass intent from event processing to update loop
	bool m_proceedKeyPressed;
};

#endif // !SPLASHSCREEN_H
