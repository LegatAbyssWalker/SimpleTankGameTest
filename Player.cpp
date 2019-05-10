#include "Player.h"



//Constructors/Destructors
Player::Player() {
	texture.loadFromFile("res/images/playerTank.png");
	player.setTexture(texture);

	sf::Vector2<unsigned> individualCharacter = texture.getSize();
	individualCharacter.x /= 1;
	individualCharacter.y /= 1;

	player.setTextureRect(sf::IntRect(individualCharacter.x * 0, individualCharacter.y * 0, individualCharacter.x, individualCharacter.y));
	player.setOrigin(individualCharacter.x / 2, individualCharacter.y / 2);
}

Player::~Player() {
	//
}



//Functions
void Player::drawTo(sf::RenderWindow& window) {
	window.draw(player);
}

void Player::moveTo(sf::Vector2<float> distance) {
	player.move(distance);
}

void Player::setPlayerPos(sf::Vector2<float> newPos) {
	player.setPosition(newPos);
}

int Player::getX() {
	return player.getPosition().x;
}

int Player::getY() {
	return player.getPosition().y;
}

void Player::updateborderBounds() {
	if (getX() <= screenWidth * 0)  { setPlayerPos(sf::Vector2<float>(getX() + playerBorderSpeed, getY())); } //Left
	if (getX() >= screenWidth)      { setPlayerPos(sf::Vector2<float>(getX() - playerBorderSpeed, getY())); } //Right
	if (getY() <= screenHeight * 0) { setPlayerPos(sf::Vector2<float>(getX(), getY() + playerBorderSpeed)); } //Top
	if (getY() >= screenHeight)     { setPlayerPos(sf::Vector2<float>(getX(), getY() - playerBorderSpeed)); } //Bottom

}

sf::FloatRect Player::getGlobalBounds() {
	return player.getGlobalBounds();
}

bool Player::collisionWithEnemy(Enemy* enemy) {
	if (getGlobalBounds().intersects(enemy->getGlobalBounds())) {
		return true;
	}
	return false;
}

bool Player::collisionWithCoin(Coin* coin) {
	if (getGlobalBounds().intersects(coin->getGlobalBounds())) {
		return true;
	}
	return false;
}
