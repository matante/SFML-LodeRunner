#include "Ladder.h"
#include "Player.h"
#include"Enemy.h"
Ladder::Ladder(sf::Vector2f location)
{
	m_rectangleShape.setTexture(&Textures::instance().getIconTexture(LADDER));
	m_rectangleShape.setPosition(sf::Vector2f(location.x, location.y - 2));
	m_originalPos = location;
}
// --------------------------------------------------------------

void Ladder::handleCollision(Enemy& gameObject)
{
	//call the enemy with myself
	gameObject.handleCollision(*this);
}
// --------------------------------------------------------------

void Ladder::handleCollision(Player& gameObject) 
{
	//call the player with myself
	gameObject.handleCollision(*this);
}