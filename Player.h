#ifndef PLAYER_H
#define PLAYER_H

#include "SFML/Graphics.hpp"
#include "SFML/System/Vector2.hpp"

#include "MoreInfo.h"
#include "Enemy.h"

class Player {
	private:
		sf::Texture texture;
		sf::Sprite player;

	public:
		//Class objects
		Enemy enemy;
		PlaySound playSound;

		//Constructors/Destructors
		Player();
		~Player();


		//Functions
		void drawTo(sf::RenderWindow& window);
		void moveTo(sf::Vector2<float> distance);
		void setPlayerPos(sf::Vector2<float> newPos);
		int getX();
		int getY();
		void updateborderBounds();
		sf::FloatRect getGlobalBounds();

		bool collisionWithEnemy(Enemy* enemy);
};

#endif