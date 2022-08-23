#include "Gold.h"
#include "Player.h"
Gold::Gold(sf::Vector2f location)
{
	m_rectangleShape.setTexture(&Textures::instance().getIconTexture(GOLD));
	m_rectangleShape.setPosition(location);
	m_rectangleShape.setScale(sf::Vector2f(0.75f, 0.75f));
	m_originalPos = location;
}
// --------------------------------------------------------------

void Gold::handleCollision(Enemy& gameObject) {}
// --------------------------------------------------------------

void Gold::handleCollision(Player& gameObject) 
{
	//call the player with myself
	gameObject.handleCollision(*this);
	m_isDisposed = true; // need to be deleted upon taking

}
