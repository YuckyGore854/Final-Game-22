#include "entity.h"

void entity::draw(sf::RenderWindow& window) {
	
}

void entity::update() {
	entRect.setPosition(sf::Vector2f(entRect.getPosition().x + velocity[0], entRect.getPosition().y + velocity[1]));
	
}