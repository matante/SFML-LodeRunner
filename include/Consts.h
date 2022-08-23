#pragma once
/* this file used for all the consts, includes for other libraries and unsing*/

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <cmath>
#include <cstdlib>    // exit prototype
#include <cstring>    // strcpy and strcat prototypes
#include <ctime>
#include <experimental/vector>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <iostream>
#include <thread>
#include <typeinfo>

/*sizes for window*/
const float INFO_BAR = 50.0;
const float HEIGHT = 700.0 + INFO_BAR;
const float WIDTH = 700.0;
const float SPEED = 100.0;

/*return codes*/
const int
LADDER_RC = 1,
BAR_RC = 2,
WALL_RC = 3;


/*indices*/
const int BAR = 0,
ENEMY = 1,
GIFT = 2,
GOLD = 3,
LADDER = 4,
PLAYER = 5,
WALL = 6;

const int INFO_BAR_ITEMS = 6;
const int
GOLD_TITLE = 0,
GOLD_CURRENT = 1,
TIME_TITLE = 2,
TIME_CURRENT = 3,
HP_TITLE = 4,
HP_CURRENT = 5;

const int
MENU_BACKGROUND = 0,
GAME_BACKGROUND = 1;

const int
NEW_GAME = 1,
LEVEL_PASSED = 2;

const int
DIED_AUD = 0,
GOLD_AUD = 1,
GIFT_AUD = 2;

/*directions*/
const sf::Vector2f
DOWN = sf::Vector2f(0, 1),
UP = sf::Vector2f(0, -1),
LEFT = sf::Vector2f(-1, 0),
RIGHT = sf::Vector2f(1, 0);


/*from char to rectangle*/
const char 
PLAYER_CHAR = '@',
ENEMY_CHAR = '%',
WALL_CHAR = '#',
GOLD_CHAR = '*',
LADDER_CHAR = 'H',
GIFT_CHAR = '+',
BAR_CHAR = '-';


/* other stuff*/
const float
SECONDS_UNTIL_RESTORE = 3.0,
RND_ENMY_TIME = 2.0;
/*gold*/
const int
LEVEL_REWARD = 50,
GOLD_VAL = 2,
PLAYER_STARTING_HP = 3;