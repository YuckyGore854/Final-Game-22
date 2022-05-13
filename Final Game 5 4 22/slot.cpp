#include "slot.h"
#include <iostream>

slot::slot(int x, int y, int type, int numb, textures* text){
	textReferece = text;
	loadTexture(type);
	entSprite.setPosition(sf::Vector2f(x, y));
	entRect.setPosition(sf::Vector2f(x, y)); 
	
	originalPos.x = x;
	originalPos.y = y - 20;
	entType = "slot";
	num = numb;
	if (type == GENERATOR)
		cost = 50;
	if (type == ELECTRO)
		cost = 100;
	if (type == JUNKBOT)
		cost = 0;
	//std::cout << entRect.getSize().x << " " << entRect.getSize().y << std::endl;

	SubRect.width = 100;
	SubRect.height = 80;
	entSprite.setTextureRect(SubRect);
}

int slot::numReturn(){
	return num;
}

int slot::click(bool lClick, bool hover, int money, sf::RenderWindow& window, sf::Vector2i mousePos, int numHeld) {
	if (lClick && hover && cooldown == 0 && money >= cost && num == numHeld) {
		holding = true;
	}
	if (!lClick) {
		holding = false;
	}
	if (holding == true) {
		entRect.setPosition(sf::Vector2f(mousePos.x, mousePos.y));
		entSprite.setPosition(sf::Vector2f(mousePos.x - 50, mousePos.y -  50));
		window.draw(entSprite);
	}
	if (!holding) {
		entRect.setPosition(originalPos);
		entSprite.setPosition(originalPos);
	}
	if (holding == false && numHeld == 1) {

	}

	return 0;
}

void slot::update() {

}

void slot::update(bool lClick, bool hover, int money, sf::RenderWindow& window, sf::Vector2i mousePos, int numHeld) {
	click(lClick, hover, money, window, mousePos, numHeld);
}

void slot::draw(sf::RenderWindow window) {
	SubRect.left = 0;
	
	window.draw(entSprite);
}

//robot* slot::spawnBot(float xpos, float ypos) {
//	return new robot(type, textReferece, xpos, ypos);
//}