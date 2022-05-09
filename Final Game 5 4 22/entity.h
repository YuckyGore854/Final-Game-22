#pragma once
#include<SFML/Graphics.hpp>
#include<string>
#include"textures.h"
class entity{
public:
	entity() { entRect.setPosition(sf::Vector2f(100, 100)); entRect.setFillColor(sf::Color(0, 0, 0)); entRect.setSize(sf::Vector2f(30, 30)); };//make blank entity offscreen
	entity(std::string file) { entSprite.setPosition(sf::Vector2f(100, 100)); loadTexture(file); }
	virtual void update();
	virtual void update(bool lClick, bool hover, int money, sf::RenderWindow& window, sf::Vector2i mousePos) { };
	virtual bool hover(int mouseX, int mouseY);
	virtual void draw(sf::RenderWindow &window);
	virtual void loadTexture(std::string file);
	virtual std::string getStr() { return entType; }
	virtual int getNum() { return num; }
protected:
	sf::RectangleShape entRect;
	sf::Sprite entSprite;
	std::string entType;
	float velocity[2] = { 0, 0 };
	int num;
};

