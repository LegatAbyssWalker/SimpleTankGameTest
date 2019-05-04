#include "Bullet.h"



//Constructors/Destructors
Bullet::Bullet() {
	texture.loadFromFile("res/images/bulletImage.png");
	sf::Vector2<unsigned> individualCharacter = texture.getSize();
	individualCharacter.x /= 1;
	individualCharacter.y /= 1;

	bullet.setTexture(texture);
	bullet.setTextureRect(sf::IntRect(individualCharacter.x * 0, individualCharacter.y * 0, individualCharacter.x, individualCharacter.y));
	bullet.setOrigin(individualCharacter.x / 2, individualCharacter.y / 2);
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