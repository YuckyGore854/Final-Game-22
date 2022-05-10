#pragma once
#include "entity.h"
#include "projectile.h"
class robot : public entity {
public:
	void update();
	projectile shoot();
	robot();
	enum robots {
		NONE = 0, GENERATOR = 1, ELECTRO = 2, JUNKBOT = 3
	};
	
protected:
	int health;
	int shootTicker;
	int type;                                                                                                                       
	sf::RectangleShape range;

	
};

