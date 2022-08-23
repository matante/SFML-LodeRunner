#include "GiftHP.h"
#include "Player.h"
GiftHP::GiftHP(sf::Vector2f location)
	:Gift(location)
{
	
}
// --------------------------------------------------------------

void GiftHP::handleCollision(Player& gameObject)
{
	//call the player with myself
	gameObject.handleCollision(*this);
	m_isDisposed = true;
}