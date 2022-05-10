#include "entity.h"

void entity::draw(sf::RenderWindow& window) {
	window.draw(entSprite);
}

void entity::update() {
	sf::Vector2f newPos = { entRect.getPosition().x + velocity[0], entRect.getPosition().y + velocity[1] };
	entRect.setPosition(newPos);
	entSprite.setPosition(newPos);
}

void entity::loadTexture(int type) {
	
	entSprite.setTexture(textReferece->junkbot);
	if (type == JUNKBOT) {
		entSprite.setTexture(textReferece->junkbot);
	}

	entRect.setSize(sf::Vector2f(entSprite.getTexture()->getSize().x * entSprite.getScale().x, entSprite.getTexture()->getSize().y * entSprite.getScale().y));
}

bool entity::hover(int mouseX, int mouseY) {
	//std::cout << entRect.getSize().x <<" "<<entRect.getSize().y << std::endl;
	if (mouseX < entRect.getPosition().x + entRect.getSize().x && mouseX > entRect.getPosition().x && mouseY < entRect.getPosition().y + entRect.getSize().y && mouseY > entRect.getPosition().y) {
		return true;
	}
	return false;
}