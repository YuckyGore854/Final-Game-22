#include "entity.h"
#include<iostream>

entity::entity(int type, textures* texture) {
	entSprite.setPosition(sf::Vector2f(100, 100));
	textReferece = texture;
	loadTexture(type); 
	frameTick = 0;
	frameNum = 0;
	frameWidth = entSprite.getTextureRect().width;
	frameheight = entSprite.getTextureRect().height;
	SubRect.width = frameWidth;
	SubRect.height = frameheight;
	entSprite.setTextureRect(SubRect);
}

void entity::draw(sf::RenderWindow& window) {
	window.draw(entSprite);
}

void entity::update() {
	sf::Vector2f newPos = { entRect.getPosition().x + velocity[0], entRect.getPosition().y + velocity[1] };
	entRect.setPosition(newPos);
	entSprite.setPosition(newPos);
}

void entity::loadTexture(int type) {
	
	entSprite.setTexture(textReferece->junkbot);//default texture, unless desired sprite is junkbot, you know something went wrong somewhere
	if (type == JUNKBOT) {
		entSprite.setTexture(textReferece->junkbot);
	}
	else if (type == ELECTRO) {
		entSprite.setTexture(textReferece->electrobot);
	}
	else if (type == 0) {
		entSprite.setTexture(textReferece->defaultImg);
	}
	
	entRect.setSize(sf::Vector2f(entSprite.getTexture()->getSize().x * entSprite.getScale().x, entSprite.getTexture()->getSize().y * entSprite.getScale().y));
}

bool entity::hover(int mouseX, int mouseY) {
	//std::cout << entRect.getSize().x <<" "<<entRect.getSize().y << std::endl;
	if (mouseX < entRect.getPosition().x + entRect.getSize().x && mouseX > entRect.getPosition().x && mouseY < entRect.getPosition().y + SubRect.height && mouseY > entRect.getPosition().y) {
		return true;
	}
	return false;
}

//robot* entity::spawnBot(float xpos, float ypos) { return nullptr; }