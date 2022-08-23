#include "StaticObject.h"

void StaticObject::handleCollision(Object& gameObject) {}

// --------------------------------------------------------------

void StaticObject::handleCollision(Wall& gameObject) {}
// --------------------------------------------------------------

// --------------------------------------------------------------

void StaticObject::handleCollision(Gold& gameObject) {}
// --------------------------------------------------------------

void StaticObject::handleCollision(Bar& gameObject) {}
// --------------------------------------------------------------

void StaticObject::handleCollision(Ladder& gameObject) {}
// --------------------------------------------------------------

void StaticObject::handleCollision(Enemy& gameObject) {} // nothing

// --------------------------------------------------------------


bool StaticObject::isDisposed() const
{
	return m_isDisposed;
}
// --------------------------------------------------------------

void StaticObject::hideMe()
{
	m_drawMe = false;
	m_clock.restart();

}
// --------------------------------------------------------------

void StaticObject::checkForUnhide()
{
	
	if (!m_drawMe) // this floor was deleted, restore after 3 sec
		if (m_clock.getElapsedTime().asSeconds() > SECONDS_UNTIL_RESTORE)
		{
			m_drawMe = true;
			m_clock.restart();

		}
}

// --------------------------------------------------------------
