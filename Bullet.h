#ifndef BULLET_H
#define BULLET_H

#include "SFML/Graphics.hpp"
#include "SFML/System/Vector2.hpp"

#include "Enemy.h"
#include "PlaySound.h"

class Bullet {
	private:
		sf::Texture texture;
		sf::Sprite bullet;

	public:
		//Class objects
		PlaySound playSound;
		Enemy enemy;


		//Constructors/Destructors
		Bullet();
		~Bullet();


		
		//Functions
		void drawTo(sf::RenderWindow& window);
		void fireBullet(int speed);
		void setBulletPos(sf::Vector2<float> newPos);
		void addNewBullet(std::string bulletFile, int xDivide, int yDivide, int parameter1, int parameter2);
		sf::FloatRect getGlobalBounds();

		bool collisionWithEnemy(Enemy* enemy);
};

#endif