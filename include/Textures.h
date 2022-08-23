#pragma once
#include "Consts.h"
#include"SharedInfo.h"

class Textures
{
public:
	//static class stuff
	~Textures();
	static Textures& instance();


	/*get funcs*/
	sf::Texture& getIconTexture(int);
	sf::Texture& getBackgroundTexture(int);

private://static class stuff
	Textures();
	Textures(const Textures&) = default;
	Textures& operator=(const Textures&) = default;


private: //functions
	void loadTextures();

private: //members

	std::vector<sf::Texture> m_icons;
	std::vector<sf::Texture> m_background;

};