#include "Enemy.h"
#include "Player.h"
#include "RegularEnemy.h"

Enemy::Enemy(sf::Vector2f location)
{
	m_rectangleShape.setPosition(location);
	m_originalPos = location;
	m_rectangleShape.setTexture(&Textures::instance().getIconTexture(ENEMY));
	m_rectangleShape.setScale(sf::Vector2f(0.95f, 0.95f));
}
// --------------------------------------------------------------
/* static things*/
int Enemy::m_newEnemyCounter = 0;

int Enemy::getNewEnemyCounter()
{
	// behaves in series, not "real" random
	if (m_newEnemyCounter < 2)
		m_newEnemyCounter++;
	else
		m_newEnemyCounter = 0;

	return m_newEnemyCounter;

} // end static function getCount
// --------------------------------------------------------------

void Enemy::setEnemyDirection(sf::Vector2f direction)
{
	m_direction = direction;
}
// --------------------------------------------------------------

void Enemy::handleCollision(Object& gameObject)
{
	if (&gameObject == this) return;
	//double dispatch
	gameObject.handleCollision(*this);
}
// --------------------------------------------------------------

// --------------------------------------------------------------


void Enemy::handleCollision(Gold& gameObject) {} //empty
// --------------------------------------------------------------


void Enemy::handleCollision(Bar& gameObject)
{
	m_wasOnBar = true;
	if (this->m_direction == sf::Vector2f(0,1))
		m_rectangleShape.move(sf::Vector2f(0, 7));
}
// --------------------------------------------------------------


void Enemy::handleCollision(Ladder& gameObject)
{
	m_isOnLadder = true;
}
// --------------------------------------------------------------

void Enemy::handleCollision(Enemy& gameObject) {} //empty
// --------------------------------------------------------------

void Enemy::handleCollision(Player& gameObject)
{
	gameObject.handleCollision(*this); 
}

// --------------------------------------------------------------

void Enemy::setPos(sf::Vector2f newPos)
{
	m_rectangleShape.setPosition(newPos);
}

// --------------------------------------------------------------

sf::Vector2f Enemy::getLastPos() const
{
	return m_lastPos;
}