#pragma once
#include "Consts.h"
#include "StaticObject.h"
#include "Textures.h" 

class Wall : public StaticObject {
public:
	Wall(sf::Vector2f);

	sf::Vector2f getWallPos() const;

	virtual void handleCollision(Enemy& ) override;
	virtual void handleCollision(Player& ) override;

private:
};
