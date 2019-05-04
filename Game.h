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

class Game {
	private:
		sf::RenderWindow window;
		sf::Event sfEvent;

		sf::Texture image;
		sf::Sprite background;

		const int playerSpeed = 2;
		const int bulletSpeed = 5;
		const int enemySpeed  = 1;
		int framerateLimit = 120;

		bool isMovingLeft = false;
		bool isMovingRight = false;
		bool isBulletFiring = false;
		
		bool isFRPressed = false; //Framerate pressed


		//Vectors
		std::vector<Bullet*> bulletVector;
		std::vector<Enemy*> enemyVector;


		//Mouse vectors
		sf::Vector2<int> mousePos = sf::Mouse::getPosition(window);

	public:
		//Class objects
		Player player;
		FPSCounter fpsCounter;
		PlaySound playSound;
		Bullet bullet;
		Enemy enemy1, enemy2, enemy3, enemy4;


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