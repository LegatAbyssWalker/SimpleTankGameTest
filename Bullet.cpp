#include "Bullet.h"



//Constructors/Destructors
Bullet::Bullet() {
}

Bullet::~Bullet() {
	playSound.stopSound();
}



//Functions
void Bullet::drawTo(sf::RenderWindow& window) {
	window.draw(bullet);
}

void Bullet::fireBullet(int speed) {
	bullet.move(speed, 0);
}

void Bullet::setBulletPos(sf::Vector2<float> newPos) {
	bullet.setPosition(newPos);
}

void Bullet::addNewBullet(std::string bulletFile, int xDivide, int yDivide, int parameter1, int parameter2) {
	texture.loadFromFile(bulletFile);
	sf::Vector2<unsigned> individualCharacter = texture.getSize();
	individualCharacter.x /= xDivide;
	individualCharacter.y /= yDivide;

	bullet.setTexture(texture);
	bullet.setTextureRect(sf::IntRect(individualCharacter.x * parameter1, individualCharacter.y * parameter2, individualCharacter.x, individualCharacter.y));
	bullet.setOrigin(individualCharacter.x / 2, individualCharacter.y / 2);
}

sf::FloatRect Bullet::getGlobalBounds() {
	return bullet.getGlobalBounds();
}

bool Bullet::collisionWithEnemy(Enemy* enemy) {
	if (getGlobalBounds().intersects(enemy->getGlobalBounds())) {
		playSound.setSound("res/audio/explosionSound.wav", 30, false);
		setBulletPos(sf::Vector2<float>(100000, 100000));
		return true;
	}
	return false;
}