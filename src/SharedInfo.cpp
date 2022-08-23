#include "SharedInfo.h"  
using std::cout;
using std::endl;


SharedInfo::SharedInfo() :m_hp(3), m_timer(-1), m_gold(0),
m_currLevel(0), m_goldOnBoard(0), m_isGame(false), m_objectsSize(0.0f),
m_timeForLevel(-1), m_isThereATimeLimit(false)
{
	//constructor
};

// --------------------------------------------------------------

SharedInfo::~SharedInfo() { }
SharedInfo& SharedInfo::instance() {
	static SharedInfo inst;
	return inst;
}

// --------------------------------------------------------------

void SharedInfo::setPlayerLocation(sf::Vector2f recievedLocation)
{
	m_playerLocation = recievedLocation;
}
// --------------------------------------------------------------


sf::Vector2f SharedInfo::getPlayerLocation() const
{
	return m_playerLocation;
}
// --------------------------------------------------------------

void SharedInfo::addTimeBy(float val)
{
	//for when need to add or reduce time
	m_timer += val;

}

// --------------------------------------------------------------

void SharedInfo::resetClock()
{
	m_clock.restart(); // start measuring time
}
// --------------------------------------------------------------

sf::Time SharedInfo::getElapsedTime()
{
	return m_clock.getElapsedTime();
}
// --------------------------------------------------------------

void SharedInfo::addHPBy(int val)
{
	m_hp += val;
}
// --------------------------------------------------------------

void SharedInfo::foundGold()
{
	m_gold += GOLD_VAL * m_currLevel; // consider const
	m_goldOnBoard--;
}
// --------------------------------------------------------------

void SharedInfo::levelUpReward()
{
	m_gold += LEVEL_REWARD *m_currLevel; // bonus for level
}
// --------------------------------------------------------------

void SharedInfo::setCurrLevel(int val)
{
	if (val == NEW_GAME)
		m_currLevel = 1; 
	else
		m_currLevel++;
}
// --------------------------------------------------------------

void SharedInfo::setTimeForLevel(float time)
{
// used for when die and still have hp left (game is not over yet)
	m_timeForLevel = time;
	if (time < 0)
		m_isThereATimeLimit = false;
	else
		m_isThereATimeLimit = true;
	m_timer = time;
}
// --------------------------------------------------------------

sf::Time SharedInfo::getTimeForLevel()const
{
	return sf::seconds(m_timeForLevel);
}
// --------------------------------------------------------------

float SharedInfo::getTimer() const
{
	//return current time left
	return m_timer;
}
// --------------------------------------------------------------

int SharedInfo::getHP() const
{
	return m_hp;
}
// --------------------------------------------------------------

bool SharedInfo::isGame() const
{
	return m_isGame;
}
// --------------------------------------------------------------

int SharedInfo::getGold() const
{
	return m_gold;
}
// --------------------------------------------------------------

int SharedInfo::getCurrLevel() const
{
	return m_currLevel;
}
// --------------------------------------------------------------

int SharedInfo::getGoldOnBoard() const
{
	return m_goldOnBoard;
}
// --------------------------------------------------------------


void SharedInfo::setGameStatus(bool condition)
{
	m_isGame = condition;
}
// --------------------------------------------------------------

void SharedInfo::incGoldOnBoardCounterBy(int val)
{
	m_goldOnBoard += val;
}
// --------------------------------------------------------------

void SharedInfo::setObjectsSize(float size)
{
	m_objectsSize = size;
}
// --------------------------------------------------------------

float SharedInfo::getObjectsSize() const
{
	return m_objectsSize;
}
// --------------------------------------------------------------

bool SharedInfo::isThereATimeLimit()const
{
	return m_isThereATimeLimit;
}
// --------------------------------------------------------------

void SharedInfo::setGoldOnBoard(int val)
{
	m_goldOnBoard = val;
}
// --------------------------------------------------------------

void SharedInfo::resetScore()
{
	m_gold = 0;
}
// --------------------------------------------------------------


void SharedInfo::resetGoldOnBoardCounter()
{
	m_goldOnBoard = 0;
}
// --------------------------------------------------------------
