#include "GiftEnemy.h"
#include "Player.h"
GiftEnemy::GiftEnemy(sf::Vector2f location)
	:Gift(location)
{

}
// --------------------------------------------------------------

void GiftEnemy::handleCollision(Player& gameObject)
{
	//call the player with myself
	gameObject.handleCollision(*this);
	m_isDisposed = true;
}