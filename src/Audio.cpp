#include "Audio.h"
using std::cout;
using std::endl;

Audio::Audio()
{
	loadMusicFiles();
};
// --------------------------------------------------------------

Audio& Audio::instance() {
	static Audio inst;
	return inst;
}
// --------------------------------------------------------------

void Audio::playBackgroundMusic()
{
	m_backgroundMusic.play();
}
// --------------------------------------------------------------

void Audio::playSound(int index)
{
	m_sounds[index].play();
}
// --------------------------------------------------------------

void Audio::loadMusicFiles()
{
	sf::SoundBuffer mySoundBuffer;

	mySoundBuffer.loadFromFile("died.wav");
	m_soundBuffers.push_back(mySoundBuffer);

	mySoundBuffer.loadFromFile("goldTaken.wav");
	m_soundBuffers.push_back(mySoundBuffer);

	mySoundBuffer.loadFromFile("giftTaken.wav");
	m_soundBuffers.push_back(mySoundBuffer);

	for (int i = 0; i < m_soundBuffers.size(); i++)
	{
		sf::Sound mySound(m_soundBuffers[i]);
		m_sounds.push_back(mySound);
		m_sounds[i].setVolume(2.0f);
	}

	m_backgroundMusic.openFromFile("backgroundMusic.wav");
	m_backgroundMusic.setVolume(1.0f);
	m_backgroundMusic.setLoop(true);

}

