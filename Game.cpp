#include "Game.h"



//Constructors/Destructors
Game::Game() {
	window.create(sf::VideoMode(screenWidth, screenHeight), "SFML Tank Game");
	window.setPosition({ window.getPosition().x, window.getPosition().y - 50 });
	window.setFramerateLimit(framerateLimit);
	image.loadFromFile("res/images/backgroundImage.png");
	background.setTexture(image);
	window.setKeyRepeatEnabled(false);


	//Player information
	player.setPlayerPos(sf::Vector2<float>(screenWidth * 0 + 50, groundHeight));


	//Enemy information
	enemyVector.push_back(&enemy1);
	enemyVector.push_back(&enemy2);

	enemy1.setEnemyPos({ screenWidth - 200, groundHeight });
	enemy2.setEnemyPos({ screenWidth + 200, groundHeight });


	//Bullet information
	bulletVector.push_back(&bullet1);
	bulletVector.push_back(&bullet2);
	bulletVector.push_back(&bullet3);
	bulletVector.push_back(&bullet4);
	bulletVector.push_back(&bullet5);


	//Audio information
	playSound.setMusic("res/audio/gameMusic.wav", 50, true);
}

Game::~Game() {
	window.clear();
	window.close();

	playSound.stopMusic();
	playSound.stopSound();
}



//Functions
void Game::handleKeyboardInput(sf::Keyboard::Key key, bool isPressed) {
	if (key == sf::Keyboard::A)     { isMovingLeft   = isPressed; playSound.setSound("res/audio/tankMovingSoundEffect.wav", 20, true); }
	if (key == sf::Keyboard::D)     { isMovingRight  = isPressed; playSound.setSound("res/audio/tankMovingSoundEffect.wav", 20, true); }
	if (key == sf::Keyboard::Space) { isBulletFiring = isPressed; }

	/*ADMIN ONLY -- RESET PLAYER POSITION*/
	if (key == sf::Keyboard::R) { player.setPlayerPos(sf::Vector2<float>(screenWidth / 2, groundHeight)); }
}

void Game::handleMouseInput(sf::Mouse::Button mousePressed, bool isMousePressed) {
	if (mousePressed == sf::Mouse::Left) { isFRPressed = isMousePressed; }
}

void Game::updateEvents() {
	while (window.pollEvent(sfEvent)) {
		switch (sfEvent.type) {
			//Window closes
			case sf::Event::Closed:
				window.close();
				break;


			//Keyboard events
			case sf::Event::KeyPressed:
				handleKeyboardInput(sfEvent.key.code, true);
				break;

			case sf::Event::KeyReleased:
				handleKeyboardInput(sfEvent.key.code, false);
				break;


			//Mouse events
			case sf::Event::MouseButtonPressed:
				handleMouseInput(sfEvent.mouseButton.button, true);
				break;

			case sf::Event::MouseButtonReleased:
				handleMouseInput(sfEvent.mouseButton.button, false);
				break;

				/*COMMENT OUT IF WANT MOUSE POSITIONS*/
			/*case sf::Event::MouseMoved:
				sf::Vector2<int> mousePos = sf::Mouse::getPosition(window);
				std::cout << "X: " << mousePos.x << ", " << "Y: " << mousePos.y << '\n';
				break;*/
		}
	}
}

void Game::update() {
	//Player movement
	sf::Vector2<float> playerMovement(0.f, 0.f);
	if (isMovingLeft)  { playerMovement.x -= playerSpeed; }
	if (isMovingRight) { playerMovement.x += playerSpeed; }
	player.moveTo(playerMovement);

	//Player position
	//std::cout << "Player X: " << player.getX() << "\nPlayer Y: " << player.getY();


	//Class updates
	player.updateborderBounds();
	fpsCounter.update();


	//Bullet logic
	sf::Vector2<float> bulletMovement(0.f, 0.f);
	if (isBulletFiring) {
		//Player has limit of 3 bullets
		//If player has 3 or less bullets remaining, use this if statement
		if (bulletCount <= 4) {
			playSound.setSound("res/audio/bulletSound.wav", 20, false);
			switch (bulletCount) {
				case 1:
					bullet1.addNewBullet("res/images/bulletImage.png", 1, 1, 0, 0);
					bullet1.setBulletPos(sf::Vector2<float>(player.getX() + 50, player.getY() - 20));
					break;

				case 2:
					bullet2.addNewBullet("res/images/bulletImage.png", 1, 1, 0, 0);
					bullet2.setBulletPos(sf::Vector2<float>(player.getX() + 50, player.getY() - 20));
					break;

				case 3:
					bullet3.addNewBullet("res/images/bulletImage.png", 1, 1, 0, 0);
					bullet3.setBulletPos(sf::Vector2<float>(player.getX() + 50, player.getY() - 20));
					break;

				case 4:
					bullet4.addNewBullet("res/images/bulletImage.png", 1, 1, 0, 0);
					bullet4.setBulletPos(sf::Vector2<float>(player.getX() + 50, player.getY() - 20));
					break;

				case 5:
					bullet5.addNewBullet("res/images/bulletImage.png", 1, 1, 0, 0);
					bullet5.setBulletPos(sf::Vector2<float>(player.getX() + 50, player.getY() - 20));
					break;
			}

			bulletCount += 1;
			isBulletFiring = false;
		}

		//If not, use a timer and then restart with bullet count.
		if (bulletCount >= 5) {
			playSound.setSound("res/audio/tankAmmunitionGoneSoundEffect.wav", 20, false);
			isBulletFiring = false;
			timer = dtClock.getElapsedTime().asSeconds();
			if (timer >= 3.000) {
				bulletCount = 0;
				dtClock.restart();
			}
		}
	}

	for (int x = 0; x < bulletVector.size(); x++) {
		bulletVector[x]->drawTo(window);
		bulletVector[x]->fireBullet(bulletMovement.x += bulletSpeed);
		
	}


	//Enemy logic
	sf::Vector2<float> enemyMovement(0.f, 0.f);
	for (int x = 0; x < enemyVector.size(); x++) {
		//Bullet collides with enemy
		if (bullet1.collisionWithEnemy(enemyVector[x])) { enemyVector[x]->setEnemyPos({ 10000, 10000 }); }
		if (bullet2.collisionWithEnemy(enemyVector[x])) { enemyVector[x]->setEnemyPos({ 10000, 10000 }); }
		if (bullet3.collisionWithEnemy(enemyVector[x])) { enemyVector[x]->setEnemyPos({ 10000, 10000 }); }
		if (bullet4.collisionWithEnemy(enemyVector[x])) { enemyVector[x]->setEnemyPos({ 10000, 10000 }); }
		if (bullet5.collisionWithEnemy(enemyVector[x])) { enemyVector[x]->setEnemyPos({ 10000, 10000 }); }


		//Player collides with enemy
		if (player.collisionWithEnemy(enemyVector[x])) {
			window.close();
		}

		//Enemy movements
		enemyVector[x]->moveTo(enemyMovement.x -= enemySpeed);
	}
}

void Game::render() {
	window.clear();

	//Render items
	//Background image
	window.draw(background);

	//FPS Counter
	if (isFRPressed) { fpsCounter.drawTo(window); }

	//Player
	player.drawTo(window);

	//Bullet
	bullet1.drawTo(window);
	bullet2.drawTo(window);
	bullet3.drawTo(window);
	bullet4.drawTo(window);
	bullet5.drawTo(window);

	//Enemy
	enemy1.drawTo(window);
	enemy2.drawTo(window);


	window.display();
}

void Game::run() {
	while (window.isOpen()) {
		updateEvents();
		update();
		render();
	}
}