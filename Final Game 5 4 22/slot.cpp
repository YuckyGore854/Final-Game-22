#include "slot.h"
#include <iostream>

slot::slot(int x, int y, std::string file) {
	entSprite.setPosition(sf::Vector2f(x, y));
	entRect.setPosition(sf::Vector2f(x, y)); 
	originalPos.x = x;
	originalPos.y = y;
	loadTexture(file);
	entType = "slot";
}

bool slot::hover(int mouseX, int mouseY) {
	//std::cout << entRect.getSize().x <<" "<<entRect.getSize().y << std::endl;
	if (mouseX < entRect.getPosition().x + entRect.getSize().x && mouseX > entRect.getPosition().x && mouseY < entRect.getPosition().y + entRect.getSize().y && mouseY > entRect.getPosition().y) {
		return true;
	}
	return false;
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