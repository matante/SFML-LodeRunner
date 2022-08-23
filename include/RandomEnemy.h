#pragma once
#include "Consts.h"
#include "Enemy.h"
#include "SharedInfo.h"

class RandomEnemy : public Enemy
{
public:
	RandomEnemy(sf::Vector2f);

	/*Functions:*/
	virtual void move(float) override;
	virtual void handleCollision(Wall&) override;

private:/*Functions:*/
	void setRandomDirection();

private: /* Members*/
	sf::Time m_time;
	sf::Clock m_clock;
};