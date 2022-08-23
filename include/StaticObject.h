#pragma once
#include "Object.h"
#include "Consts.h"

class StaticObject : public Object {
public:
	
	bool isDisposed() const;
	void hideMe();
	void checkForUnhide();
	
	virtual void handleCollision(Object& ) override;
	virtual void handleCollision(Wall& ) override;
	virtual void handleCollision(Gold& ) override;
	virtual void handleCollision(Bar& ) override;
	virtual void handleCollision(Ladder& ) override;
	virtual void handleCollision(Enemy&) override;


protected:
	bool m_isDisposed = false;
	
private:
	sf::Time m_time;
	sf::Clock m_clock;

};
