#pragma once
#include "entity.h"
#include "projectile.h"
class robot : public entity {
public:
	void update();
	projectile shoot();
	
protected:
	int health;
	int shootTicker;
	int type;                                                                                                                       
	sf::RectangleShape range;

	enum robots {
		NONE = 0, GENERATOR = 1, ELECTRO = 2, JUNKBOT = 3
	};
};

