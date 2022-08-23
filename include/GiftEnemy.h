#pragma once
#include "Consts.h"
#include "Gift.h"

class GiftEnemy : public Gift {
public:
	GiftEnemy(sf::Vector2f);

	virtual void handleCollision(Player& ) override;

private:
};
