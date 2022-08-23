#include "Wall.h"
#include "Player.h"
#include "Enemy.h"

Wall::Wall(sf::Vector2f location)
{
	m_rectangleShape.setTexture(&Textures::instance().getIconTexture(WALL));
	m_rectangleShape.setPosition(location);
	m_rectangleShape.setScale(sf::Vector2f(0.98f, 0.98f));
	m_originalPos = location;
}
// --------------------------------------------------------------

 void Wall::handleCollision(Player& gameObject){
	//call the player with myself
	gameObject.handleCollision(*this);
}
 // --------------------------------------------------------------


 void Wall::handleCollision(Enemy& gameObject)
 {
	 //call the enemy with myself
	 gameObject.handleCollision(*this);
 }
 // --------------------------------------------------------------

 sf::Vector2f Wall::getWallPos() const
 {
	 return m_rectangleShape.getPosition();
 }
 // --------------------------------------------------------------
