#include "Controller.h"
using std::cout;
using std::endl;

Controller::Controller()
{
}
// --------------------------------------------------------------

void Controller::run()
{
	/*get stuff ready for the game*/
	sf::RenderWindow the_window =
		sf::RenderWindow(sf::VideoMode(WIDTH, HEIGHT), "Lode Runner - Talia and Matan's Project", sf::Style::Close);

	SharedInfo& singleton = SharedInfo::instance();
	Audio::instance().playBackgroundMusic();

	sf::Clock clock;
	int currHp = 3;
	auto event = sf::Event{};


	/*** this is the main loop ***/

	while (the_window.isOpen())
	{
		sf::Time deltaTime = clock.restart();

		checkIfPlayerStandsInTime(deltaTime);

		for (; the_window.pollEvent(event); /*no itirator*/)
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				the_window.close();
				break;

			case sf::Event::KeyPressed:
				if (event.key.code == sf::Keyboard::Escape)
					the_window.close();
				// else, if pressed space and in menu,
				else if (event.key.code == sf::Keyboard::Space && !singleton.isGame())
					startNewGame(currHp);

				break; // of case key pressed

			}// end of switch
		}// end of poll events loop



		if (singleton.isGame()) // playing is alive, game is running, yay!
		{
			if (singleton.getGoldOnBoard() == 0) // no gold left on board, go to nxt lvl
			{
				setNewLevel();
				singleton.setCurrLevel(LEVEL_PASSED);
				singleton.levelUpReward();
			}
			
			else if (singleton.getHP() == 0) // player died :(
				singleton.setGameStatus(false);
			
			else if (singleton.getHP() < currHp) // player lost 1 hp
			{
				m_board.allocateObjects();// <- restore original pos's of stuff
				m_board.setSizes();

				currHp = singleton.getHP(); //update local life intgr for the nxt loop
			}

			else // nothing changed, move objects regularly
				m_board.moveMovables(deltaTime);

		} // end of if alive if 

		the_window.clear(sf::Color::White);

		if (singleton.isGame()) // alive
			m_board.drawAllObjects(the_window);

		else // not started the game yet or died
			m_menu.showMenu(the_window);

		the_window.display();

	}// end of while window is open loop
}

// --------------------------------------------------------------



void Controller::setNewLevel()
{
	if (!m_board.readSizeAndTime()) // file ended, don't continue. else, set things up
		return;

	m_board.readMapTxtFromFileToStringVector();
	SharedInfo::instance().setObjectsSize(m_board.setBoardOfRectangles()); // get size of objct

	m_board.allocateObjects();
	m_board.setSizes();

	SharedInfo::instance().setGameStatus(true);
	SharedInfo::instance().resetClock();
}

// --------------------------------------------------------------

void Controller::checkIfPlayerStandsInTime(sf::Time deltaTime)
{
	SharedInfo& singleton = SharedInfo::instance(); // for short 

	if (singleton.isGame()) // game is running ==> not in menu
	{
		if (singleton.getTimer() > 0) // still have time left
			singleton.addTimeBy(-deltaTime.asSeconds()); // reduce

		else // time <= 0
		{
			if (singleton.isThereATimeLimit()) // not infinity time ==> time ran out
			{
				singleton.addHPBy(-1);
				singleton.addTimeBy(singleton.getTimeForLevel().asSeconds()); // set timer to original
				m_board.allocateObjects(); 
				m_board.setSizes();

				//restore stage to original state
			}
			//else, there is no time limit, therefore everything is alright :) 
		}
	}
}
// --------------------------------------------------------------

void Controller::startNewGame(int& currHp)
{
	SharedInfo& singleton = SharedInfo::instance(); // used for short

	m_board.openStagesFile();
	setNewLevel();

	if (singleton.getHP() != PLAYER_STARTING_HP) //make sure hp is PLAYER_STARTiNG_HP
	{
		singleton.addHPBy(PLAYER_STARTING_HP);
		currHp = PLAYER_STARTING_HP;
	}

	singleton.setCurrLevel(NEW_GAME);
	singleton.resetScore();
}