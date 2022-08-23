#pragma once
#include "Consts.h"
#include "StaticObject.h"
#include "Textures.h" 

class Bar : public StaticObject {
public: 
	Bar(sf::Vector2f);

	/*Functions:*/
	virtual void handleCollision(Enemy&) override;
	virtual void handleCollision(Player&) override;

private:/*Members:*/
};
