#pragma once
#include "Consts.h"
#include "StaticObject.h"
#include "Textures.h" 

class Gold : public StaticObject {
public:
	Gold(sf::Vector2f);
		
	virtual void handleCollision(Player& ) override;
	virtual void handleCollision(Enemy& ) override;

private:
};
