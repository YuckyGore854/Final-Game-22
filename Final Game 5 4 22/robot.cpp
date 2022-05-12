#include "robot.h"
#include<iostream>
robot::robot() {
	health = 100;
	shootTicker = 0;
	robotType = JUNKBOT;
	if (robotType == JUNKBOT) {
		entSprite.setTexture(textReferece->junkbot);
	}
	entSprite.setTexture(textReferece->junkbot);
	frameTick = 0;
	frameNum = 0;
	frameWidth = entSprite.getTextureRect().width / 100;//dividing spritesheet into 100 pixel wide pieces, we will always assume sprites are 100*100 in size
	frameheight = entSprite.getTextureRect().height;
	SubRect.width = frameWidth;
	SubRect.height = frameheight;
}

robot::robot(int types, textures* texture, float xpos, float ypos) {
	robotType = types;
	health = 100;
	shootTicker = 0;
	textReferece = texture;
	loadTexture(robotType);
	entSprite.setPosition(sf::Vector2f(xpos, ypos));
	entRect.setPosition(sf::Vector2f(xpos, ypos));
	if (robotType == JUNKBOT) {
		entSprite.setTexture(textReferece->junkbot);
	}
	entSprite.setTexture(textReferece->junkbot);
	entRect.setSize(sf::Vector2f(entSprite.getTexture()->getSize().x * entSprite.getScale().x, entSprite.getTexture()->getSize().y * entSprite.getScale().y));
	frameTick = 0;
	frameNum = 0;
	frameCount = entSprite.getTextureRect().width / 100;
	frameWidth = 100;//dividing spritesheet into 100 pixel wide pieces, we will always assume sprites are 100*100 in size
	frameheight = entSprite.getTextureRect().height;
	SubRect.width = frameWidth;
	SubRect.height = frameheight;
	
}

void robot::update() {

}

void robot::draw(sf::RenderWindow* window) {
	frameTick++;
	if (frameTick == 15) {
		frameNum += 1;
		frameTick = 0;
	}
	if (frameNum > 6)
		frameNum = 0;

	SubRect.left = frameNum * SubRect.width;
	entSprite.setTextureRect(SubRect);
	window->draw(entSprite); //draw player
}

//projectile shoot() {
//	projectile nProj;
//	return nProj;
//}