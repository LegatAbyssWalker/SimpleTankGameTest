#ifndef FPSCOUNTER_H
#define FPSCOUNTER_H

#include "SFML/Graphics.hpp"
#include "SFML/System/Vector2.hpp"
#include "SFML/System/Time.hpp"
#include "SFML/System/Clock.hpp"

#include "MoreInfo.h"

#include <iostream>
#include <sstream>

class FPSCounter {
	private:
		sf::Font gameFont;
		sf::Text framerateCounter;

	public:
		std::ostringstream ssFPS;

		sf::Clock dtClock;
		sf::Time time;

	public:
		//Constructors/Destructors
		FPSCounter();
		~FPSCounter();


		//Functions
		void drawTo(sf::RenderWindow& window);
		void update();
};

#endif