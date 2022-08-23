#include "MovingObject.h"

bool MovingObject::isOnLadder() const
{
	return m_isOnLadder;
}
// --------------------------------------------------------------

bool MovingObject::isOnGround() const
{
	return m_isOnGround;
}
// --------------------------------------------------------------

bool MovingObject::wasOnBar() const
{
	return m_wasOnBar;
}
// --------------------------------------------------------------

sf::Vector2f MovingObject::getDirection() const
{
	return m_direction;
}
// --------------------------------------------------------------


void MovingObject::setLadderCondition(bool condition)
{
	m_isOnLadder = condition;
}
// --------------------------------------------------------------


void MovingObject::setGroundCondition(bool condition)
{
	m_isOnGround = condition;
}
// --------------------------------------------------------------

void MovingObject::setBarCondition(bool condition)
{
	m_wasOnBar = condition;
}
// --------------------------------------------------------------

void MovingObject::gravity()
{
	/*keep last pos, and move down*/
	m_lastPos = this->m_rectangleShape.getPosition();
	m_rectangleShape.move(DOWN);
}
// --------------------------------------------------------------

void MovingObject::setLastPos()
{
	m_rectangleShape.setPosition(m_lastPos);
}
// --------------------------------------------------------------
