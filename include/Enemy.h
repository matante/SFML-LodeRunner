#pragma once
#include "Consts.h"
#include "MovingObject.h"
#include "Textures.h" 

class RegularEnemy;
class Enemy : public MovingObject
{
public:
	Enemy(sf::Vector2f );
	
	/*Functions:*/
	static int getNewEnemyCounter();
	void setPos(sf::Vector2f);
	sf::Vector2f getLastPos() const;
	void virtual setEnemyDirection(sf::Vector2f);
	
	virtual void handleCollision(Object& ) override;
	virtual void handleCollision(Player& ) override;
	virtual void handleCollision(Gold& ) override;
	virtual void handleCollision(Bar& ) override;
	virtual void handleCollision(Ladder& ) override;
	virtual void handleCollision(Enemy& ) override;
	virtual void handleCollision(Wall& ) = 0 ;




private: /*members:*/
	static int m_newEnemyCounter;
};