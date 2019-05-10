#ifndef COIN_H
#define COIN_H

#include "SFML/Graphics.hpp"
#include "SFML/System/Vector2.hpp"

#include "MoreInfo.h"

class Coin {
	private:
		sf::Texture texture;
		sf::Sprite coin;


	public:
		//Constructors/Destructors
		Coin();
		~Coin();


		//Functions
		void drawTo(sf::RenderWindow& window);
		void setCoinPos(sf::Vector2<float> newPos);
		sf::FloatRect getGlobalBounds();
};

#endif