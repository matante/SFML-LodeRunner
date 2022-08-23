#pragma once 
#include "Consts.h"
#include "Bar.h"
#include "Board.h"
#include "Enemy.h"
#include "Gift.h"
#include "GiftEnemy.h"
#include "GiftGold.h"
#include "GiftHP.h"
#include "GiftTime.h"
#include "Gold.h"
#include "Ladder.h"
#include "Player.h"
#include "RandomEnemy.h"
#include "RegularEnemy.h"
#include "SharedInfo.h"
#include "SmartEnemy.h"
#include "StaticObject.h"
#include "Wall.h"

class Board {
public:
	Board();
	/*Functions:*/
	
	/*managing files and creating the objects functions:*/
	bool readSizeAndTime();
	float setBoardOfRectangles();
	void allocateObjects();
	void openStagesFile();
	void readMapTxtFromFileToStringVector();
	void setSizes();


	/* managing the objects while game is running functiosn:*/
	int checkForCollisons(MovingObject&);
	void addNewEnemy(sf::Vector2f);
	void drawAllObjects(sf::RenderWindow&);
	void isNewEnemy();
	void manageDigging();
	void manageTimer();
	void printBackground(sf::RenderWindow&);
	void setInfoBarValues();
	void addNewGift(sf::Vector2f);
	void moveMovables(sf::Time);

	

private: 	/*Members:*/

	/*files and information regarding it:*/
	std::vector<std::string> m_mapTextChars;
	std::vector<std::vector<sf::RectangleShape>> m_theMap;
	unsigned m_h; unsigned m_w;
	std::ifstream m_stagesFile;
	
	/*objects:*/
	std::vector<std::unique_ptr<Enemy>> m_enemies;
	std::vector<std::unique_ptr<StaticObject>> m_staticObjects;
	Player m_player;

	/*textures and drawing:*/
	sf::Font m_infoBarFont;
	sf::RectangleShape m_gameBackgroundRectangle;
	sf::Text m_texts[INFO_BAR_ITEMS];
	sf::Texture m_gameBackgroundTexture;
	float m_texturesSize;

};