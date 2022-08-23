#include "Gift.h"
#include "Player.h"
Gift::Gift(sf::Vector2f location)
{
	m_rectangleShape.setTexture(&Textures::instance().getIconTexture(GIFT));
	m_rectangleShape.setPosition(location);
	m_rectangleShape.setScale(sf::Vector2f(0.75f, 0.75f));
	m_originalPos = location;
}
// --------------------------------------------------------------

// --------------------------------------------------------------

void Gift::handleCollision(Player& gameObject)
{
	//call the player with myself
	gameObject.handleCollision(*this);
	m_isDisposed = true; // need to be deleted upon taking
}
// --------------------------------------------------------------

/* static stuff*/
int Gift::m_newGiftCounter = 0;

int Gift::getNewGiftCounter()
{
	// behaves in series, not "real" random
	if (m_newGiftCounter < 3)
		m_newGiftCounter++;
	else
		m_newGiftCounter = 0;

	return m_newGiftCounter;

} // end static function getCount
