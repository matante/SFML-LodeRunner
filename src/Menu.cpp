#include "Menu.h"

Menu::Menu()
{
	if (!m_font.loadFromFile("RAVIE.TTF"))
		exit (EXIT_FAILURE);

	//may need a vector or an array, but this way is more dynamic and elastic
	m_msgOpening.setFont(m_font);
	m_msgStart.setFont(m_font);
	m_msgEsc.setFont(m_font);

	m_msgOpening.setCharacterSize(60);
	m_msgStart.setCharacterSize(45);
	m_msgEsc.setCharacterSize(45);


	m_msgOpening.setPosition(20.f, 100.f); // find right place
	m_msgStart.setPosition(40.f, 380.f); // find right place
	m_msgEsc.setPosition(40.f, 520.f); // find right place

	m_msgOpening.setOutlineColor(sf::Color::Black);
	m_msgStart.setOutlineColor(sf::Color::Black);
	m_msgEsc.setOutlineColor(sf::Color::Black);

	m_msgOpening.setOutlineThickness(1.0f);
	m_msgStart.setOutlineThickness(1.0f);
	m_msgEsc.setOutlineThickness(1.0f);


	m_msgOpening.setFillColor(sf::Color::Green);
	m_msgStart.setFillColor(sf::Color::Blue);
	m_msgEsc.setFillColor(sf::Color::Red);

	
	m_msgOpening.setString( "Welcome to the\n    Lode Runner\n        Game!");
	m_msgStart.setString(" Press the Space Bar\n        to start");
	m_msgEsc.setString("  Press ESC to exit");

	m_menuBackgroundRectangle.setTexture(&Textures::instance().getBackgroundTexture(MENU_BACKGROUND));
	m_menuBackgroundRectangle.setSize(sf::Vector2f(WIDTH, HEIGHT + INFO_BAR));
	m_menuBackgroundRectangle.setFillColor(sf::Color(255, 255, 255, 128));

}

// --------------------------------------------------------------

void Menu::showMenu(sf::RenderWindow& window){
		
	window.draw(m_menuBackgroundRectangle);
	window.draw(m_msgOpening);
	window.draw(m_msgStart);
	window.draw(m_msgEsc);


}
