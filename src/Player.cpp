#include "Player.h"
#include "Board.h"
#include "GiftHP.h"
#include "GiftGold.h"
#include "GiftTime.h"
#include "GiftEnemy.h"

Player::Player()
	: m_gameOver (false), m_isNewEnemy (false), m_shouldDeleteFloor (false)
{
	m_rectangleShape.setTexture(&Textures::instance().getIconTexture(PLAYER));
	m_rectangleShape.setScale(sf::Vector2f(0.95f, 0.95f));
	m_direction = DOWN; // by default
}

// --------------------------------------------------------------

void Player::setPlayerLocation(sf::Vector2f location)
{
	m_rectangleShape.setPosition(location);
	m_originalPos = location;
	m_lastPos = m_originalPos;
	SharedInfo::instance().setPlayerLocation(m_rectangleShape.getPosition());
}

// --------------------------------------------------------------

sf::Vector2f Player::getPlayerLocation() const
{
	return m_rectangleShape.getPosition();
}
// --------------------------------------------------------------

void Player::handleCollision(Player& gameObject){} // empty
// --------------------------------------------------------------

void Player::handleCollision(Object& gameObject) {
	if (&gameObject == this) return;
	//double dispatch
	gameObject.handleCollision(*this);
}
// --------------------------------------------------------------

void Player::handleCollision(Wall& gameObject)
{
	if (gameObject.shouldBeDrawn()) // floor is not digged 
	{
		m_isOnGround = true;

		m_rectangleShape.setPosition(m_lastPos);
		SharedInfo::instance().setPlayerLocation(m_rectangleShape.getPosition());
	}
	
}
// --------------------------------------------------------------


void Player::handleCollision(Gold& gameObject)
{
	SharedInfo::instance().foundGold();
	Audio::instance().playSound(GOLD_AUD);
}

// --------------------------------------------------------------

bool Player::isNewEnemy() const
{
	return m_isNewEnemy;
}
// --------------------------------------------------------------

sf::Vector2f Player::getOriginalPos() const
{
	return m_originalPos;
}

// --------------------------------------------------------------

void Player::setNewEnemyCon(bool con)
{
	m_isNewEnemy = con;
}
// --------------------------------------------------------------

void Player::handleCollision(Bar& gameObject)
{
	m_wasOnBar = true;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
		m_rectangleShape.move(DOWN * 7.0f); // fall further
	SharedInfo::instance().setPlayerLocation(m_rectangleShape.getPosition());

}
// --------------------------------------------------------------

void Player::handleCollision(Ladder& gameObject)
{
	
	m_isOnLadder = true;
		
}
// --------------------------------------------------------------

void Player::handleCollision(Enemy& gameObject)
{
	SharedInfo::instance().addHPBy(-1);
	if (SharedInfo::instance().getHP() == 0) // dead
		SharedInfo::instance().setGameStatus(false);
	
	Audio::instance().playSound(DIED_AUD);

}


// --------------------------------------------------------------


void Player::move(float deltaTime)
{
	//act according to the key pressed
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		m_direction = UP;
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		m_direction = DOWN;
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		m_direction = LEFT;
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		m_direction = RIGHT;

	// press the dig buttons 
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
		dig(LEFT);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::X))
		dig(RIGHT);

	m_lastPos = m_rectangleShape.getPosition();
	
	if (m_isOnLadder || m_direction != UP) // valid move
		m_rectangleShape.move(m_direction * SPEED * deltaTime);
	m_direction = sf::Vector2f(0, 0); // stops from "sliding" uncontrolablly
	SharedInfo::instance().setPlayerLocation(m_rectangleShape.getPosition());
}
// --------------------------------------------------------------

void Player::dig(sf::Vector2f direction)
{
	//calculate how to find the right floor to delete
	float width = m_rectangleShape.getGlobalBounds().width / 2;
	float middlePoint = m_rectangleShape.getPosition().x + width;
	float bottom = m_rectangleShape.getPosition().y + m_rectangleShape.getGlobalBounds().height +5.0f;
	
	//inset result into a member
	m_diggedFloorPos = sf::Vector2f(middlePoint, bottom) +
		direction* width + DOWN;
	m_shouldDeleteFloor = true;
}
// --------------------------------------------------------------

sf::Vector2f Player::shouldDeleteFloor(bool & con)
{
	//returns the position of the floor that need to be deleted, 
	// and updates the boolean given by refference
	con = m_shouldDeleteFloor;
	return m_diggedFloorPos;
}
// --------------------------------------------------------------

void Player::resetDeleteFloorCon()
{
	m_shouldDeleteFloor = false;
}
// --------------------------------------------------------------


void Player::handleCollision(GiftHP& gameObject)
{
	SharedInfo& singleton = SharedInfo::instance();
	
	singleton.addHPBy(1);

	Audio::instance().playSound(GIFT_AUD);
}
// --------------------------------------------------------------

void Player::handleCollision(GiftEnemy& gameObject)
{
	SharedInfo& singleton = SharedInfo::instance();
	
		m_isNewEnemy = true;
	Audio::instance().playSound(GIFT_AUD);
}
// --------------------------------------------------------------

void Player::handleCollision(GiftGold& gameObject)
{
	SharedInfo& singleton = SharedInfo::instance();
	//act according to the gift picked

	
		singleton.foundGold();

	
	Audio::instance().playSound(GIFT_AUD);
}

void Player::handleCollision(GiftTime& gameObject)
// --------------------------------------------------------------

{
	SharedInfo& singleton = SharedInfo::instance();
	//act according to the gift picked

	
		if (singleton.getTimer() > 0)
			singleton.addTimeBy(10);

	Audio::instance().playSound(GIFT_AUD);
}