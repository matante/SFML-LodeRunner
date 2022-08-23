#include "Bar.h"
#include "Player.h"
#include "Enemy.h" // for collisons

Bar::Bar(sf::Vector2f location)
{
	m_rectangleShape.setTexture(&Textures::instance().getIconTexture(BAR));
	m_rectangleShape.setPosition(location);
	m_rectangleShape.setFillColor(sf::Color(255, 255, 255, 192));
	m_rectangleShape.setPosition(sf::Vector2f(location.x, location.y - 2.0f));
	m_originalPos = location;
}
// --------------------------------------------------------------

void Bar::handleCollision(Enemy& gameObject)
{
	gameObject.handleCollision(*this);
}
// --------------------------------------------------------------

void Bar::handleCollision(Player& gameObject) 
{
	//call the player with myself
	gameObject.handleCollision(*this);
}