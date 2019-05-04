#include "Enemy.h"



//Constructors/Destructors
Enemy::Enemy() {
	//Enemy texture
	enemyTexture.loadFromFile("res/images/enemyTank.png");
	enemy.setTexture(enemyTexture);

	sf::Vector2<unsigned> individualCharacter = enemyTexture.getSize();
	individualCharacter.x /= 1;
	individualCharacter.y /= 1;

	enemy.setTextureRect(sf::IntRect(individualCharacter.x * 0, individualCharacter.y * 0, individualCharacter.x, individualCharacter.y));
	enemy.setOrigin(individualCharacter.x / 2, individualCharacter.y / 2);
}

Enemy::~Enemy() {
	//
}



//Functions
void Enemy::drawTo(sf::RenderWindow& window) {
	window.draw(enemy);
}

void Enemy::setEnemyPos(sf::Vector2<float> newPos) {
	enemy.setPosition(newPos);
}

void Enemy::moveTo(int enemySpeed) {
	enemy.move(enemySpeed, 0);
}

sf::FloatRect Enemy::getGlobalBounds() {
	return enemy.getGlobalBounds();
}