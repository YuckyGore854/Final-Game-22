#include<SFML/Graphics.hpp>
#include<string>
#pragma once
class entity{
public:
	entity() { entRect.setPosition(sf::Vector2f(100, 100)); entRect.setFillColor(sf::Color(0, 0, 0)); entRect.setSize(sf::Vector2f(30, 30)); };//make blank entity offscreen
	entity(std::string file) { entSprite.setPosition(sf::Vector2f(100, 100)); loadTexture(file); }
	virtual void update();
	virtual void draw(sf::RenderWindow &window);
	virtual void loadTexture(std::string file);
	virtual std::string getStr() { return entType; }
protected:
	sf::RectangleShape entRect;
	sf::Texture entText;
	sf::Sprite entSprite;
	std::string entType;
	float velocity[2] = { 0, 0 };
};

