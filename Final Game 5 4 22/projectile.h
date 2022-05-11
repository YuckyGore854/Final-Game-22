#pragma once
#include "entity.h"

class projectile : public entity{
public:
	projectile();
	~projectile();
	projectile(int x, int y, int projType, textures* text);
	
	void kill();
	bool offscreen();
	void draw(sf::RenderWindow& window);

	enum type {
		NONE = 0, ENERGYBALL = 1, BOLTS = 2
	};
protected:
	int type = 0;
};

