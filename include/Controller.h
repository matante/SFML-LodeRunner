#pragma once
#include "Consts.h"
#include "Audio.h"
#include "Bar.h"
#include "Board.h"
#include "Enemy.h"
#include "Gift.h"
#include "Gold.h"
#include "Ladder.h"
#include "Menu.h"
#include "Object.h"
#include "Player.h"
#include "RegularEnemy.h"
#include "SmartEnemy.h"
#include "StaticObject.h"
#include "Wall.h"

class Controller {
public: //constructor and destructor
	Controller();
	~Controller() = default;

public: //funcs
	void run();

private://funcs
	void setNewLevel();
	void checkIfPlayerStandsInTime(sf::Time);
	void startNewGame(int&);

private: //members
	Board m_board;
	Menu m_menu;	
};
