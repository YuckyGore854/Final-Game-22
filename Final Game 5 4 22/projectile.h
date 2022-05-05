#pragma once
#include "entity.h"
class projectile : public entity{
public:
	projectile();
	~projectile();
	projectile(int x, int y);
	void move();
	void kill();
	bool offscreen();
	void draw(sf::RenderWindow& window);
private:
	bool exists;
};

