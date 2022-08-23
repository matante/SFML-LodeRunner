#pragma once
#include "Consts.h"
#include "MovingObject.h"
#include "SharedInfo.h"
#include "Textures.h" 
#include "Audio.h"

class Player : public MovingObject {
public:
	Player();

	/*Set Functions:*/
	void setPlayerLocation(sf::Vector2f);
	void setNewEnemyCon(bool);
	void resetDeleteFloorCon();

	/*Get Functions:*/
	sf::Vector2f getPlayerLocation() const;
	sf::Vector2f getOriginalPos() const;
	sf::Vector2f shouldDeleteFloor(bool&); // not private as it return value and modify
	bool isNewEnemy() const;

	/*other functiosn*/
	virtual void move(float) override;

	virtual void handleCollision(Bar& ) override;
	virtual void handleCollision(Enemy& ) override;
	virtual void handleCollision(Gold& ) override;
	virtual void handleCollision(Ladder& ) override;
	virtual void handleCollision(Player& ) override;
	virtual void handleCollision(Wall& ) override;
	virtual void handleCollision(Object& ) override;
	virtual void handleCollision(GiftTime& )override ;
	virtual void handleCollision(GiftHP& )override;
	virtual void handleCollision(GiftEnemy& )override;
	virtual void handleCollision(GiftGold& )override;


private: //funcs
	void dig(sf::Vector2f);

	/*Members:*/	
	bool m_gameOver;
	bool m_isNewEnemy;
	bool m_shouldDeleteFloor;

	sf::Vector2f m_diggedFloorPos;
};
