#pragma once
#include "Consts.h"

/*forward declartions*/
class Wall;
class Player;
class Bar;
class Ladder; 
class Gift;
class Gold;
class Enemy;
class GiftTime;
class GiftEnemy;
class GiftHP;
	class GiftGold;


class Object {
public:
	Object();
	virtual ~Object() = default;

	virtual void draw(sf::RenderWindow& );
	virtual void setSize(float);
	virtual sf::FloatRect getGlobalRectBound();

	void restoreOriginalPos();
	bool shouldBeDrawn() const;

	virtual void handleCollision(Object& ) = 0;
	virtual void handleCollision(Player& ) = 0;
	virtual void handleCollision(Wall&) = 0;
	virtual void handleCollision(Gold&) = 0;
	virtual void handleCollision(Bar&) = 0;
	virtual void handleCollision(Ladder&) = 0;
	virtual void handleCollision(Enemy&) = 0;
	virtual void handleCollision(GiftTime&);
	virtual void handleCollision(GiftHP&);
	virtual void handleCollision(GiftEnemy&);
	virtual void handleCollision(GiftGold&);
	bool checkCollision(const sf::FloatRect&) const;



protected:
	sf::RectangleShape m_rectangleShape;
	sf::Vector2f m_originalPos;
	bool m_drawMe; 

};
