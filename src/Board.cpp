#include "Board.h"
using std::cout;
using std::endl;

// --------------------------------------------------------------

Board::Board()
	: m_h(0), m_w(0), m_texturesSize(0.0f)
{
	/* set background*/
	m_gameBackgroundRectangle.setTexture(&Textures::instance().getBackgroundTexture(GAME_BACKGROUND));
	m_gameBackgroundRectangle.setSize(sf::Vector2f(WIDTH, HEIGHT + INFO_BAR));
	m_gameBackgroundRectangle.setFillColor(sf::Color(255, 255, 255, 128)); // half trasnparent

	/*set font and titles*/
	if (!m_infoBarFont.loadFromFile("BAUHS93.TTF"))
		exit(EXIT_FAILURE);

	for (int i = 0; i < INFO_BAR_ITEMS; i++)
	{
		m_texts[i].setFont(m_infoBarFont);
		m_texts[i].setCharacterSize(40);
		m_texts[i].setOutlineColor(sf::Color::Black);
		m_texts[i].setOutlineThickness(1.0f);
	}

	m_texts[GOLD_CURRENT].setFillColor(sf::Color::Green);
	m_texts[GOLD_TITLE].setFillColor(sf::Color::Green);
	m_texts[TIME_CURRENT].setFillColor(sf::Color::Blue);
	m_texts[TIME_TITLE].setFillColor(sf::Color::Blue);
	m_texts[HP_CURRENT].setFillColor(sf::Color::Red);
	m_texts[HP_TITLE].setFillColor(sf::Color::Red);


	m_texts[GOLD_TITLE].setString("Gold: ");
	m_texts[TIME_TITLE].setString("Time Left: ");
	m_texts[HP_TITLE].setString("HP: ");


	m_texts[GOLD_TITLE].setPosition(20.f, 5.f);
	m_texts[GOLD_CURRENT].setPosition(130.f, 5.f);
	m_texts[TIME_TITLE].setPosition(220.f, 5.f);
	m_texts[TIME_CURRENT].setPosition(400.f, 5.f);
	m_texts[HP_TITLE].setPosition(550.f, 5.f);
	m_texts[HP_CURRENT].setPosition(620.f, 5.f);

}

// --------------------------------------------------------------


void Board::setInfoBarValues()
{
	m_texts[GOLD_CURRENT].setString(std::to_string(SharedInfo::instance().getGold()));
	m_texts[HP_CURRENT].setString(std::to_string(SharedInfo::instance().getHP()));
	manageTimer(); // change the timer on the info bar
}

// --------------------------------------------------------------

void Board::openStagesFile() {
	m_stagesFile.open("Board.txt", std::fstream::in);
	m_stagesFile.clear();
	m_stagesFile.seekg(0); // jump to top of file
}
// --------------------------------------------------------------

bool Board::readSizeAndTime()
{
	m_stagesFile >> m_h >> m_w; // read from file to members
	int time;
	m_stagesFile >> time;
	if (m_stagesFile.eof())
	{
		SharedInfo::instance().setGameStatus(false);
		return false;
	}
	SharedInfo::instance().resetClock();
	SharedInfo::instance().setTimeForLevel(time);
	setInfoBarValues();

	return true; // succeedededed
}

// --------------------------------------------------------------


void Board::manageTimer()
{
	float time = SharedInfo::instance().getTimer();

	if (time > 0) // still have time left
		m_texts[TIME_CURRENT].setString(std::to_string(int(time)));

	if (!SharedInfo::instance().isThereATimeLimit())
		m_texts[TIME_CURRENT].setString(" INF ");

}

// --------------------------------------------------------------


void Board::readMapTxtFromFileToStringVector() {
	m_stagesFile.get(); // eat the new line char
	m_mapTextChars.clear(); //old vector

	for (int i = 0; i < m_h; i++)
	{
		auto line = std::string(); // set new string and read into it
		std::getline(m_stagesFile, line);
		m_mapTextChars.push_back(line); // place in the end of the vecotr
	}
}

// --------------------------------------------------------------

/*
* set empty grid of rectangles. this is used to place the objects on right spot
*/
float Board::setBoardOfRectangles() {

	/* first clear old vectors */
	for (int i = 0; i < m_theMap.size(); i++)
		for (int j = 0; j < m_theMap[i].size(); j++)
			m_theMap[i].clear();

	m_theMap.clear();

	/* now make the new grid */

	sf::RectangleShape my_rectangle; // a basic rectangle
	float size = std::min(((HEIGHT - INFO_BAR) / m_h), (WIDTH / m_w));
	// as get from the user, it will be squared rectangle

	my_rectangle.setSize(sf::Vector2f(size, size)); //sqaured 

	for (int row = 0; row < m_h; row++)
	{
		m_theMap.push_back(std::vector<sf::RectangleShape>()); // each line is a vector of rectangles
		for (int col = 0; col < m_w; col++)
		{
			my_rectangle.setPosition((float)(col * size),
				(float)(INFO_BAR + row * size));

			m_theMap[row].push_back(my_rectangle);
		}
	}
	return size;
}

// --------------------------------------------------------------


void Board::printBackground(sf::RenderWindow& window)
{
	window.draw(m_gameBackgroundRectangle);
}

// --------------------------------------------------------------

void Board::allocateObjects()
{
	//clear old vectors
	m_enemies.clear();
	m_staticObjects.clear();
	SharedInfo::instance().resetGoldOnBoardCounter();

	// for each char in the text file, set right object with the position, 
	// and add it to the correct vector

	for (int row = 0; row < m_h; row++)
	{
		for (int col = 0; col < m_w; col++)
		{
			sf::Vector2f pos = m_theMap[row][col].getPosition();

			switch (m_mapTextChars[row][col]) // on the char from the text file
			{

			case WALL_CHAR:
				m_staticObjects.push_back(std::move(std::make_unique<Wall>(pos)));
				break;

			case LADDER_CHAR:
				m_staticObjects.push_back(std::move(std::make_unique<Ladder>(pos)));
				break;

			case GOLD_CHAR:
				m_staticObjects.push_back(std::move(std::make_unique<Gold>(pos)));
				SharedInfo::instance().incGoldOnBoardCounterBy(1);
				break;

			case ENEMY_CHAR:
				addNewEnemy(pos);
				break;

			case PLAYER_CHAR:
				m_player.setPlayerLocation(m_theMap[row][col].getPosition());
				break;

			case BAR_CHAR:
				m_staticObjects.push_back(std::move(std::make_unique<Bar>(pos)));
				break;

			case GIFT_CHAR:
				addNewGift(pos);
				break;
			}
		}
	}
}

// --------------------------------------------------------------

void Board::addNewEnemy(sf::Vector2f pos)
{
	switch (Enemy::getNewEnemyCounter())//a static from the Enemy class
	{
	case 0:
		m_enemies.push_back(std::move(std::make_unique<SmartEnemy>(pos)));
		break;
	case 1:
		m_enemies.push_back(std::move(std::make_unique<RandomEnemy>(pos)));
		break;
	case 2:
		m_enemies.push_back(std::move(std::make_unique<RegularEnemy>(pos)));
		break;
	}
}
// --------------------------------------------------------------

void Board::addNewGift(sf::Vector2f pos)
{
	switch (Gift::getNewGiftCounter()) // a static from the Gift class
	{
	case 0:
		m_staticObjects.push_back(std::move(std::make_unique<GiftHP>(pos)));
		break;
	case 1:
		m_staticObjects.push_back(std::move(std::make_unique<GiftGold>(pos)));
		break;
	case 2:
		m_staticObjects.push_back(std::move(std::make_unique<GiftTime>(pos)));
		break;
	case 3:
		m_staticObjects.push_back(std::move(std::make_unique<GiftEnemy>(pos)));
		break;
	}
}

// --------------------------------------------------------------

void Board::setSizes()
{
	//set the corresponding size for the objects on the board
	float size = SharedInfo::instance().getObjectsSize();

	m_player.setSize(size);

	for (int i = 0; i < m_enemies.size(); i++)
		m_enemies[i]->setSize(size);

	for (int i = 0; i < m_staticObjects.size(); i++)
		m_staticObjects[i]->setSize(size);
}

// --------------------------------------------------------------
/* for each movable object, move it and check if move is valid */
void Board::moveMovables(sf::Time deltaTime)
{
	/* Moving the player:*/
	m_player.move(deltaTime.asSeconds());
	manageDigging();
	m_player.setLadderCondition(false);
	int currHP = SharedInfo::instance().getHP();
	checkForCollisons(m_player);

	if (SharedInfo::instance().getHP() >= currHP) //  did not lose hp in the prev collision
	{
		if (!m_player.isOnLadder() && !m_player.wasOnBar()) // in the air 
		{
			m_player.gravity();
			checkForCollisons(m_player);
		}
	}


	/*Move the enemies:*/
	for (int i = 0; i < m_enemies.size(); i++)
	{
		m_enemies[i]->move(deltaTime.asSeconds());
		m_enemies[i]->setLadderCondition(false);
		checkForCollisons(*m_enemies[i]);


		if (!m_enemies[i]->isOnLadder() && !m_enemies[i]->wasOnBar()) // in the air 
		{
			if (m_enemies[i]->getDirection() != DOWN)
				m_enemies[i]->gravity();

			checkForCollisons(*m_enemies[i]);
		

			m_enemies[i]->setGroundCondition(false);
		}
	}

	isNewEnemy();//from a gift

	setInfoBarValues(); //update 	
}

// --------------------------------------------------------------

int Board::checkForCollisons(MovingObject& movingObject)
{
	int rc = 0;
	movingObject.setBarCondition(false);

	//go over all the static objects vector and check for collisions
	for (int i = 0; i < m_staticObjects.size(); i++)
	{
		if (movingObject.checkCollision(m_staticObjects[i]->getGlobalRectBound()))
		{
			movingObject.handleCollision(*m_staticObjects[i]);

			if (typeid(*m_staticObjects[i]) == typeid(Ladder))
				movingObject.setLadderCondition(true);

			else if (typeid(*m_staticObjects[i]) == typeid(Bar))
				movingObject.setBarCondition(true);

			else if (typeid(*m_staticObjects[i]) == typeid(Wall))
				if (m_staticObjects[i]->shouldBeDrawn())
					rc = WALL_RC; // change return value
		}
	}

	// go over all the moving objects 
	for (int i = 0; i < m_enemies.size(); i++)
		if (movingObject.checkCollision(m_enemies[i]->getGlobalRectBound()))
			movingObject.handleCollision(*m_enemies[i]);
		
	// delete taken objects (gold and gifts)
	std::experimental::erase_if(m_staticObjects, [](auto& object) 
		{
			return object->isDisposed();
		});

	return rc;
}

// --------------------------------------------------------------


void Board::drawAllObjects(sf::RenderWindow& the_window)
{
	printBackground(the_window);

	//print all statics
	for (int i = 0; i < m_staticObjects.size(); i++)
		if (m_staticObjects[i]->shouldBeDrawn()) // player did not dig this object
			m_staticObjects[i]->draw(the_window); 

	//print enemies and player
	for (int i = 0; i < m_enemies.size(); i++)
		m_enemies[i]->draw(the_window);
	m_player.draw(the_window);
	
	//print info bar vals
	for (int i = 0; i < INFO_BAR_ITEMS; i++)
		the_window.draw(m_texts[i]);
}

// --------------------------------------------------------------

void Board::isNewEnemy()
{
	if (m_player.isNewEnemy())
		addNewEnemy(m_player.getOriginalPos());

	if (!m_enemies.empty()) // when picked a gift, make sure enemies vector is not empty
		m_enemies[m_enemies.size() - 1]->setSize(SharedInfo::instance().getObjectsSize());

	m_player.setNewEnemyCon(false);
}

// --------------------------------------------------------------


void Board::manageDigging()
{
	bool shouldDelete = false; //by default
	sf::Vector2f floorToCheck = (m_player.shouldDeleteFloor(shouldDelete));
	// get both location and a boolean

	if (shouldDelete)
		for (int i = 0; i < m_staticObjects.size(); i++)
		{
			if (m_staticObjects[i]->getGlobalRectBound().contains(floorToCheck))
				if (typeid(*m_staticObjects[i]) == typeid(Wall))
				{
					m_staticObjects[i]->hideMe();
					m_player.resetDeleteFloorCon();
				}
		}
			

	for (int i = 0; i < m_staticObjects.size(); i++)
		if (typeid(*m_staticObjects[i]) == typeid(Wall))
			m_staticObjects[i]->checkForUnhide();
	// check if time for being transparent ended
}
// --------------------------------------------------------------
