#include "Object.h"

Object::Object() :m_drawMe(true)
{

}
// --------------------------------------------------------------

void Object::draw(sf::RenderWindow& the_window) {
	the_window.draw(m_rectangleShape);
}
// --------------------------------------------------------------

void Object::setSize(float size)
{
	m_rectangleShape.setSize(sf::Vector2f(size, size));
}
// --------------------------------------------------------------


sf::FloatRect Object::getGlobalRectBound()
{
	return m_rectangleShape.getGlobalBounds();
}
// --------------------------------------------------------------


bool Object::checkCollision(const sf::FloatRect& floatRect) const
{
	return m_rectangleShape.getGlobalBounds().intersects(floatRect);
}
// --------------------------------------------------------------

void Object::restoreOriginalPos()
{
	m_rectangleShape.setPosition(m_originalPos);
}
// --------------------------------------------------------------

bool Object::shouldBeDrawn() const
{
	return m_drawMe;
}



void Object::handleCollision(GiftTime& gameObject) {}
// --------------------------------------------------------------
void Object::handleCollision(GiftHP& gameObject) {}
// --------------------------------------------------------------


void Object::handleCollision(GiftEnemy& gameObject) {}
// --------------------------------------------------------------

void Object::handleCollision(GiftGold& gameObject) {}
