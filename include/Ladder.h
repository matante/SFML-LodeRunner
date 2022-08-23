#pragma once
#include "Consts.h"
#include "StaticObject.h"
#include "Textures.h" 

class Ladder : public StaticObject {
public:
	Ladder(sf::Vector2f);

	virtual void handleCollision(Player& ) override;
	virtual void handleCollision(Enemy& ) override;

private:
};
