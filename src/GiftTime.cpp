#include "GiftTime.h"
#include "Player.h"
GiftTime::GiftTime(sf::Vector2f location)
	:Gift(location)
{

}
// --------------------------------------------------------------

void GiftTime::handleCollision(Player& gameObject)
{
	//call the player with myself
	gameObject.handleCollision(*this);
	m_isDisposed = true;
}