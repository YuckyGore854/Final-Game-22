#include "slot.h"
#include <iostream>

slot::slot(int x, int y, std::string file, int numb, int type) {
	entSprite.setPosition(sf::Vector2f(x, y));
	entRect.setPosition(sf::Vector2f(x, y)); 
	originalPos.x = x;
	originalPos.y = y;
	loadTexture(file);
	entType = "slot";
	num = numb;
	if (type == GENERATOR)
		cost = 50;
	if (type == ELECTRO)
		cost = 100;
	if (type == JUNKBOT)
		cost = 0;
}



int slot::click(bool lClick, bool hover, int money, sf::RenderWindow& window, sf::Vector2i mousePos) {
	if (lClick && hover && cooldown == 0 && money >= cost) {
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

void slot::update(bool lClick, bool hover, int money, sf::RenderWindow& window, sf::Vector2i mousePos) {
	click(lClick, hover, money, window, mousePos);
}