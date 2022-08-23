#include "RandomEnemy.h"


RandomEnemy::RandomEnemy(sf::Vector2f pos)
	:Enemy(pos)
{
		m_direction = LEFT; //arbiratoy -- shriruti
		m_clock.restart();

}

// --------------------------------------------------------------

void RandomEnemy::move(float deltaTime)
{

	
		
		if (m_clock.getElapsedTime().asSeconds() > RND_ENMY_TIME ||
			m_isOnGround)
		{
			setRandomDirection();
			// move in the same dir for RND_ENMY_TIME sec
			m_clock.restart();
		}
		m_isOnGround = m_wasOnBar = false;

		m_lastPos = m_rectangleShape.getPosition();

		if (m_isOnLadder || m_direction != UP) // valid move
			m_rectangleShape.move(m_direction * SPEED * deltaTime);


}
// --------------------------------------------------------------

void RandomEnemy::handleCollision(Wall& gameObject)
{
	m_isOnGround = true;
	m_rectangleShape.setPosition(m_lastPos);
}
// --------------------------------------------------------------

void RandomEnemy:: setRandomDirection()
{
	int newDir;
	
	if (m_isOnLadder)
		newDir = rand() % 4; // we have 4 dir's
	else
		newDir = rand() % 2; // only right or left
	switch (newDir)
	{
	case 0:
		m_direction = LEFT;
		break;
	case 1:
		m_direction = RIGHT;
		break;
	case 2:
		m_direction = DOWN;
		break;
	case 3: 
		m_direction = UP;
		break;
	}
}
// --------------------------------------------------------------
