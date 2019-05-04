#include "FPSCounter.h"



//Constructors/Destructors
FPSCounter::FPSCounter() {
	gameFont.loadFromFile("res/fonts/Arial.ttf");
	framerateCounter.setFont(gameFont);
	framerateCounter.setFillColor(sf::Color(255, 255, 0));
	framerateCounter.setCharacterSize(30);
	framerateCounter.setPosition(screenWidth * 0, screenHeight * 0);
}

FPSCounter::~FPSCounter() {
	//
}



//Functions
void FPSCounter::drawTo(sf::RenderWindow& window) {
	window.draw(framerateCounter);
}

void FPSCounter::update() {
	time = dtClock.getElapsedTime();

	ssFPS.str("");
	ssFPS << "FPS: " << 1.0f / time.asSeconds();
	framerateCounter.setString(ssFPS.str());

	dtClock.restart().asSeconds();
}