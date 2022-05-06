#include "entity.h"
#include<iostream>
void entity::draw(sf::RenderWindow& window) {
	window.draw(entSprite);
}

void entity::update() {
	sf::Vector2f newPos = { entRect.getPosition().x + velocity[0], entRect.getPosition().y + velocity[1] };
	entRect.setPosition(newPos);
	entSprite.setPosition(newPos);
}

void entity::loadTexture(std::string file) {
	entText.loadFromFile(file);
	entSprite.setTexture(entText);
	entRect.setSize(sf::Vector2f(entSprite.getTexture()->getSize().x * entSprite.getScale().x, entSprite.getTexture()->getSize().y * entSprite.getScale().y));
	std::cout<< entRect.getSize().x<<" "<<entRect.getSize().y;

}