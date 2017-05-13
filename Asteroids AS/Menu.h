#ifndef MAINMENU_H
#define MAINMENU_H

#include <SFML\Graphics.hpp>


class Menu
{
public:
	Menu();
	~Menu();

	void initialise(sf::Font&);
	void render(sf::RenderWindow&);
	void update(sf::Time, sf::Window&);

protected:

	/// Number of buttons on menu
	static const int m_buttons = 3;
	/// menu texture
	sf::Texture m_menuTexture;
	/// menu sprite
	sf::Sprite m_menuSprite;
	/// green button background
	sf::Texture m_buttonTexture;
	/// array of sprites used to display buttons
	sf::Sprite m_buttonSprites[m_buttons];
	/// local refrence to font used by whole game
	sf::Font m_font;
	/// array of text objects for text on buttons
	sf::Text m_buttonText[m_buttons];
	/// text to display press space message
	sf::Text m_name;

	/// top left of area used for menu
	float m_spaceTop;
	/// top left of area used for menu
	float m_spaceLeft;
	/// gap between tops of buttons
	float m_spaceButtons;
	/// width of all buttons
	float m_buttonWidth;
	/// height of buttons
	float m_buttonHeight;

};

#endif // !MAINMENU_H
