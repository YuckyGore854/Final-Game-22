#include "entity.h"
#include<iostream>
void entity::draw(sf::RenderWindow& window) {
	window.draw(entSprite);
}

void entity::update() {
	entRect.setPosition(sf::Vector2f(entRect.getPosition().x + velocity[0], entRect.getPosition().y + velocity[1]));
	
}

void entity::loadTexture(std::string file) {
	entText.loadFromFile(file);
	entSprite.setTexture(entText);
}