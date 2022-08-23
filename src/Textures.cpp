#include "Textures.h"
using std::cout;
using std::endl;

Textures::Textures()
{
	loadTextures();
};
// --------------------------------------------------------------

Textures::~Textures() {}
// --------------------------------------------------------------

Textures& Textures::instance() {
	static Textures inst;
	return inst;
}
// --------------------------------------------------------------

void Textures::loadTextures()
{	
	sf::Texture myTexture;

	myTexture.loadFromFile("bar.png");
	m_icons.push_back(myTexture);

	myTexture.loadFromFile("enemy.png");
	m_icons.push_back(myTexture);

	myTexture.loadFromFile("gift.png");
	m_icons.push_back(myTexture);

	myTexture.loadFromFile("gold.png");
	m_icons.push_back(myTexture);

	myTexture.loadFromFile("ladder.png");
	m_icons.push_back(myTexture);

	myTexture.loadFromFile("player.png");
	m_icons.push_back(myTexture);
	
	myTexture.loadFromFile("wall.png");
	m_icons.push_back(myTexture);

	myTexture.loadFromFile("menu_background.jpg");
	m_background.push_back(myTexture);

	myTexture.loadFromFile("game_background.jpg");
	m_background.push_back(myTexture);

}
// --------------------------------------------------------------

sf::Texture& Textures::getIconTexture(int index)
{
	return m_icons[index];
}
// --------------------------------------------------------------

sf::Texture& Textures::getBackgroundTexture(int index)
{
	return m_background[index];
}

// --------------------------------------------------------------
