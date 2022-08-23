#pragma once
#include "Consts.h"
#include "Textures.h"
class Menu {
public:
	Menu();
	void showMenu(sf::RenderWindow&);

private:

	sf::Font m_font;
	
	sf::Text m_msgOpening;
	sf::Text m_msgStart;
	sf::Text m_msgEsc;

	
	sf::RectangleShape m_gameOverBackgroundRectangle;
	sf::RectangleShape m_gameOverRectangle;
	sf::RectangleShape m_menuBackgroundRectangle;

};