#include "RegularEnemy.h"
#include "Wall.h"

RegularEnemy::RegularEnemy(sf::Vector2f pos)
	:Enemy(pos), m_needToChangeDir(false)
{
	m_direction = LEFT; //arbiratoy -- shriruti

}
// --------------------------------------------------------------


void RegularEnemy::move(float deltaTime)
{	
	m_lastPos = m_rectangleShape.getPosition();
	m_dirBeforeGravity = m_rectangleShape.getPosition();

	m_isOnGround = m_wasOnBar = false;
	if (m_needToChangeDir) // hit a wall
	{
		{
			if (m_direction == LEFT)
				m_direction = RIGHT;
			else
				m_direction = LEFT;
		}
	}

	m_rectangleShape.move(m_direction);
	m_needToChangeDir = false;

}
// --------------------------------------------------------------

void RegularEnemy::handleCollision(Wall& gameObject)
{
	if (round(m_rectangleShape.getPosition().x) == round(m_dirBeforeGravity.x))
		m_needToChangeDir = true;

	if (gameObject.shouldBeDrawn())
	{
		m_isOnGround = true;	
		m_rectangleShape.setPosition(m_lastPos);

	}

	
}