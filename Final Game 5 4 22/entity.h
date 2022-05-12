#pragma once
#include<SFML/Graphics.hpp>
#include<string>
#include"textures.h"

class entity{
public:
	entity() { entRect.setPosition(sf::Vector2f(100, 100)); entRect.setFillColor(sf::Color(0, 0, 0)); entRect.setSize(sf::Vector2f(30, 30)); textReferece = nullptr; };//make blank entity offscreen
	entity(int type, textures* texture);
	virtual void update();
	virtual void update(bool lClick, bool hover, int money, sf::RenderWindow& window, sf::Vector2i mousePos, int numHeld) { };
	virtual bool hover(int mouseX, int mouseY);
	virtual void draw(sf::RenderWindow &window);
	virtual void loadTexture(int type);
	virtual bool getHold() { return false; }
	virtual std::string getStr() { return entType; }
	virtual int getNum() { return num; }
	//virtual robot* spawnBot(float xpos, float ypos) { return nullptr; }
	enum robots {
		NONE = 0, GENERATOR = 1, ELECTRO = 2, JUNKBOT = 3
	};
protected:
	textures* textReferece;
	sf::RectangleShape entRect;
	sf::Sprite entSprite;
	std::string entType;
	float velocity[2] = { 0, 0 };
	int num;
	int frameTick;
	int frameNum;
	int frameCount;
	int frameWidth, frameheight;
	sf::IntRect SubRect;//used for drawing individual frames from a spritesheet
};

