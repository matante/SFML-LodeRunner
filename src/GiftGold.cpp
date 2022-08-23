#include "GiftGold.h"
#include "Player.h"
GiftGold::GiftGold(sf::Vector2f location)
	:Gift(location)
{

}
// --------------------------------------------------------------

void GiftGold::handleCollision(Player& gameObject)
{
	//call the player with myself
	gameObject.handleCollision(*this);
	m_isDisposed = true;
}