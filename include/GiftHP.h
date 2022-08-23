#pragma once
#include "Consts.h"
#include "Gift.h"

class GiftHP : public Gift {
public:
	GiftHP(sf::Vector2f);

	virtual void handleCollision(Player& ) override;

private:
};
