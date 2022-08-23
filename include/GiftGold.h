#pragma once
#include "Consts.h"
#include "Gift.h"

class GiftGold : public Gift {
public:
	GiftGold(sf::Vector2f);

	virtual void handleCollision(Player& ) override;

private:
};
