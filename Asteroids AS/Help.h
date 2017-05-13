#ifndef HELPPAGE_H
#define HELPPAGE_H

#include <SFML\Graphics.hpp>


class HelpPage
{
public:
	HelpPage();
	~HelpPage();
	void initialise(sf::Font&);
	void render(sf::RenderWindow&);
	void processInput(sf::Event);
	void update(sf::Time);

protected:
	sf::Font m_font;
	sf::Text m_message;
	bool m_quitPressed;
};

#endif // !HELPPAGE_H
