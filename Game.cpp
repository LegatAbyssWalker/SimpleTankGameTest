#include "Game.h"



//Constructors/Destructors
Game::Game() {
	window.create(sf::VideoMode(screenWidth, screenHeight), "SFML Tank Game");
	window.setPosition({ window.getPosition().x, window.getPosition().y - 50 });
	window.setFramerateLimit(framerateLimit);
	image.loadFromFile("res/images/backgroundImage.png");
	background.setTexture(image);


	//Player information
	player.setPlayerPos(sf::Vector2<float>(screenWidth * 0 + 50, groundHeight));


	//Enemy information
	enemyVector.push_back(&enemy1);
	enemyVector.push_back(&enemy2);
	enemyVector.push_back(&enemy3);
	enemyVector.push_back(&enemy4);

	enemy1.setEnemyPos({ screenWidth - 200, groundHeight });
	enemy2.setEnemyPos({ screenWidth + 200, groundHeight });
	enemy3.setEnemyPos({ screenWidth + 500, groundHeight });
	enemy4.setEnemyPos({ screenWidth + 800, groundHeight });


	//Bullet information
	bulletVector.push_back(&bullet);
	bullet.setBulletPos({ 100000, 100000 });


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
	if (key == sf::Keyboard::A)     { isMovingLeft   = isPressed; }
	if (key == sf::Keyboard::D)     { isMovingRight  = isPressed; }
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
	//Player logic
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
		playSound.setSound("res/audio/bulletSound.wav", 20, false);
		bullet.setBulletPos(sf::Vector2<float>(player.getX() + 50, player.getY() - 20));
		isBulletFiring = false;
	}

	for (int x = 0; x < bulletVector.size(); x++) {
		bulletVector[x]->drawTo(window);
		bulletVector[x]->fireBullet(bulletMovement.x += bulletSpeed);
	}



	//Enemy logic
	sf::Vector2<float> enemyMovement(0.f, 0.f);
	for (int x = 0; x < enemyVector.size(); x++) {
		if (bullet.collisionWithEnemy(enemyVector[x])) {
			enemyVector[x]->setEnemyPos({ 10000, 10000 });
		}

		if (player.collisionWithEnemy(enemyVector[x])) {
			window.close();
		}

		enemyVector[x]->moveTo(enemyMovement.x -= enemySpeed);
	}
}

void Game::render() {
	window.clear();

	//Render items
	window.draw(background);
	if (isFRPressed) { fpsCounter.drawTo(window); }

	player.drawTo(window);

	bullet.drawTo(window);
	enemy1.drawTo(window);
	enemy2.drawTo(window);
	enemy3.drawTo(window);
	enemy4.drawTo(window);

	window.display();
}

void Game::run() {
	while (window.isOpen()) {
		updateEvents();
		update();
		render();
	}
}