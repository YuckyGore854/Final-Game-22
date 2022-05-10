#include "slot.h"
#include <iostream>

slot::slot(int x, int y, int type, int numb) {
	entSprite.setPosition(sf::Vector2f(x, y));
	entRect.setPosition(sf::Vector2f(x, y)); 
	originalPos.x = x;
	originalPos.y = y;
	loadTexture(type);
	entType = "slot";
	num = numb;
	if (type == GENERATOR)
		cost = 50;
	if (type == ELECTRO)
		cost = 100;
	if (type == JUNKBOT)
		cost = 0;
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
		entSprite.setPosition(sf::Vector2f(mousePos));
		window.draw(entSprite);
	}
	if (!holding) {
		entRect.setPosition(originalPos);
		entSprite.setPosition(originalPos);
	}

	return 0;
}

void slot::update() {

}

void slot::update(bool lClick, bool hover, int money, sf::RenderWindow& window, sf::Vector2i mousePos, int numHeld) {
	click(lClick, hover, money, window, mousePos, numHeld);
}