#pragma once
#include "Consts.h"

class SharedInfo // this is our singleton! 
{
public:
	/*settings for static class*/
	~SharedInfo();
	static SharedInfo& instance();
	
	/*set functions*/
	void addHPBy(int);
	void incGoldOnBoardCounterBy(int);
	void levelUpReward();
	void resetClock();
	void resetScore();
	void resetGoldOnBoardCounter();
	void setCurrLevel(int);
	void setGameStatus(bool);
	void foundGold();
	void setGoldOnBoard(int);
	void setObjectsSize(float);
	void setTimeForLevel(float);
	void addTimeBy(float);
	void setPlayerLocation(sf::Vector2f);

	/*get functions*/
	bool isGame() const;
	bool isThereATimeLimit() const;
	float getObjectsSize() const;
	float getTimer() const;
	int getCurrLevel() const;
	int getGold() const;
	int getGoldOnBoard() const;
	int getHP() const;
	sf::Time getTimeForLevel()const;
	sf::Vector2f getPlayerLocation() const;
	sf::Time getElapsedTime();

private:
	/*static class related*/
	SharedInfo();
	SharedInfo(const SharedInfo&) = default;
	SharedInfo& operator=(const SharedInfo&) = default;
	
private: /*members*/
	bool m_isGame;
	bool m_isThereATimeLimit;
	float m_objectsSize;
	float m_timer;
	int m_currLevel;
	int m_gold;
	int m_goldOnBoard;
	int m_hp;
	int m_timeForLevel;
	sf::Clock m_clock;
	sf::Vector2f m_playerLocation;
};