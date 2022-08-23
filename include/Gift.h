#pragma once
#include "Consts.h"

#include "StaticObject.h"
#include "Textures.h" 

class Gift : public StaticObject {
public:
	Gift(sf::Vector2f);

	/*Functions:*/
	static int getNewGiftCounter();

	virtual void handleCollision(Player& ) = 0;

private:
	static int m_newGiftCounter;

};
