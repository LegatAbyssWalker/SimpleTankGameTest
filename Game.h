#ifndef GAME_H
#define GAME_H

#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include "SFML/Window.hpp"
#include "SFML/Network.hpp"
#include "SFML/System.hpp"

#include "MoreInfo.h"
#include "Player.h"
#include "FPSCounter.h"
#include "PlaySound.h"
#include "Bullet.h"
#include "Enemy.h"
#include "Coin.h"
#include "Animation.h"

#include <list>
#include <iostream>


class Game {
	private:
		//SFML Variables
		sf::RenderWindow window;
		sf::Event sfEvent;

		sf::Texture image;
		sf::Sprite background;

		sf::Clock dtClock;
		float timer;


		//Booleans and variables
		const int playerSpeed = 2;
		const int enemySpeed  = 1;
		const int bulletSpeed = 5;

		unsigned int framerateLimit = 120;
		unsigned int bulletCount    = 1;

		bool isMovingLeft   = false;
		bool isMovingRight  = false;
		bool isBulletFiring = false;
		bool isFRPressed    = false; //Framerate pressed


		//Vectors
		std::vector<Bullet*> bulletVector;
		std::vector<Enemy*>  enemyVector;
		

		//Mouse vectors
		sf::Vector2<int> mousePos = sf::Mouse::getPosition(window);

	public:
		//Class objects
		Player player;
		FPSCounter fpsCounter;
		PlaySound playSound;
		Bullet bullet1, bullet2, bullet3, bullet4, bullet5;
		Enemy enemy1, enemy2;

	public:
		//Constructors/Destructors
		Game();
		~Game();


		//Functions
		void handleKeyboardInput(sf::Keyboard::Key key, bool isPressed);
		void handleMouseInput(sf::Mouse::Button mousePressed, bool isMousePressed);
		void updateEvents();
		void update();
		void render();
		void run();
};

#endif