#include<SFML/Graphics.hpp>
#pragma once
class entity{
public:
	entity() { entRect.setPosition(sf::Vector2f(-100, 100)); };//make blank entity offscreen
	virtual void update();
	virtual void draw(sf::RenderWindow &window);
protected:
	sf::RectangleShape entRect;
	sf::Texture entText;
	float velocity[2];
};

