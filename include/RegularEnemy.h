#pragma once
#include "Consts.h"
#include "Enemy.h"

class RegularEnemy : public Enemy
{
public:
	RegularEnemy(sf::Vector2f);
	
	/*Functions:*/
	virtual void move(float deltaTime) override;
	virtual void handleCollision(Wall& gameObject) override;

private:
	bool m_needToChangeDir;
	sf::Vector2f m_dirBeforeGravity;
};