#pragma once
#include "Consts.h"
#include "SharedInfo.h"

class Audio
{
public: /*Functions:*/

	static Audio& instance();
	void playBackgroundMusic();
	void playSound(int);

private: /*Functions:*/
	Audio();
	Audio(const Audio&) = default;
	Audio& operator=(const Audio&) = default;
	void loadMusicFiles();

private: /*Members:*/
	std::vector<sf::SoundBuffer> m_soundBuffers;
	std::vector<sf::Sound> m_sounds;
	sf::Music m_backgroundMusic;

};