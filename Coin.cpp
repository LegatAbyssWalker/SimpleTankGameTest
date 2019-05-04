#include "Coin.h"



//Constructors/Destructors
Coin::Coin() {
	texture.loadFromFile("res/images/coinImage.png");
	coin.setTexture(texture);

	sf::Vector2<unsigned> individualCharacter = texture.getSize();
	individualCharacter.x /= 1;
	individualCharacter.y /= 1;

	coin.setTextureRect(sf::IntRect(individualCharacter.x * 0, individualCharacter.y * 0, individualCharacter.x, individualCharacter.y));
	coin.setOrigin(individualCharacter.x / 2, individualCharacter.y / 2);
}

Coin::~Coin() {
	//
}



//Function
void Coin::drawTo(sf::RenderWindow& window) {
	window.draw(coin);
}

void Coin::setCoinPos(sf::Vector2<float> newPos) {
	coin.setPosition(newPos);
}

sf::FloatRect Coin::getGlobalBounds() {
	return coin.getGlobalBounds();
}