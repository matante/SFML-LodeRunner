#pragma once
#include "Consts.h"
#include "Enemy.h"
#include "SharedInfo.h"

class SmartEnemy : public Enemy
{
public:
	SmartEnemy(sf::Vector2f);
	void chasePlayer(sf::Vector2f);
	virtual void move(float ) override;
	virtual void handleCollision(Wall& ) override;

private:
	bool m_needToChangeDir;

};