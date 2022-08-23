#include "SmartEnemy.h"
#include "Wall.h"

SmartEnemy::SmartEnemy(sf::Vector2f pos)
	:Enemy(pos), m_needToChangeDir(false)
{
	m_direction = LEFT;
}

// --------------------------------------------------------------

void SmartEnemy::move(float deltaTime)
{
		m_isOnGround = m_wasOnBar = false;
		if (m_needToChangeDir)
			chasePlayer(SharedInfo::instance().getPlayerLocation());

		m_lastPos = m_rectangleShape.getPosition();

		if (m_isOnLadder || m_direction != UP)
			m_rectangleShape.move(m_direction * SPEED * deltaTime);

}
// --------------------------------------------------------------

void SmartEnemy::chasePlayer(sf::Vector2f playerLocation)
{
	float enemyX = round (m_rectangleShape.getPosition().x);
	float enemyY = round (m_rectangleShape.getPosition().y);

	if (enemyX > round(playerLocation.x)) // enemy is to the right of the player, go left
		setEnemyDirection(LEFT);
	else if (enemyX < round(playerLocation.x))// go right
		setEnemyDirection(RIGHT);
	else if (enemyY > round(playerLocation.y)) // enemy is below player, need to go up
		setEnemyDirection(UP);
	else //if (enemyY < round(playerLocation.y) && m_rectangleShape.getPosition().x != m_lastPos.x) // enemy is above player, need to go down
		setEnemyDirection(DOWN);		
}

// --------------------------------------------------------------

void SmartEnemy::handleCollision(Wall& gameObject)
{
	if (gameObject.shouldBeDrawn())
	{
		m_isOnGround = true;
		if (round(m_rectangleShape.getPosition().x) != round(m_lastPos.x) &&
			m_direction != DOWN)
			m_needToChangeDir = true;
		m_rectangleShape.setPosition(m_lastPos);

	}
}

// --------------------------------------------------------------
