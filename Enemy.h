#ifndef ENEMY_H
#define ENEMY_H

#include "SFML/Graphics.hpp"
#include "SFML/System/Vector2.hpp"

#include "PlaySound.h"

class Enemy {
	private:
		sf::Texture enemyTexture;
		sf::Sprite enemy;

	public:
		//Class objects
		PlaySound playSound;

		//Constructors/Destructors
		Enemy();
		~Enemy();


		//Functions
		void drawTo(sf::RenderWindow& window);
		void setEnemyPos(sf::Vector2<float> newPos);
		void moveTo(int enemySpeed);
		sf::FloatRect getGlobalBounds();
};

#endif