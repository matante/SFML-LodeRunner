#pragma once
#include "Consts.h"
#include "Gift.h"

class GiftTime : public Gift {
public:
	GiftTime(sf::Vector2f);

	virtual void handleCollision(Player& ) override;

private:
};
