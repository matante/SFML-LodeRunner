#pragma once
#include "Object.h"
#include "Consts.h"

class MovingObject : public Object
{
public:/*Functions:*/

	void virtual move(float) = 0;
	void gravity(); 

	void setLadderCondition(bool);
	void setGroundCondition(bool);
	void setBarCondition(bool);
	void setLastPos();

	bool isOnLadder() const;
	bool isOnGround() const;
	bool wasOnBar() const;
	 
	sf::Vector2f getDirection() const;

protected: /*members:*/
	sf::Vector2f m_direction;
	bool m_isOnLadder = false;
	bool m_isOnGround = false;
	bool m_wasOnBar = false;
	sf::Vector2f m_lastPos;

private:

};
