#ifndef PLAYSOUND_H
#define PLAYSOUND_H

#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"

class PlaySound {
	private:
		sf::SoundBuffer soundBuffer;
		sf::Sound sound;

		sf::Music music;

	public:
		//Constructors/Destructors
		PlaySound();
		~PlaySound();


		//Functions
		void setSound(std::string soundName, unsigned int volume, bool loopSound);
		void setMusic(std::string musicName, unsigned int volume, bool loopMusic);
		void stopSound();
		void stopMusic();
};

#endif