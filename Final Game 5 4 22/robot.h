#pragma once
#include"entity.h"

class robot : public entity {
public:
	robot(int type, textures* texture, float xpos, float ypos);
	void update();
	//projectile shoot();
	robot();
	enum robots {
		NONE = 0, GENERATOR = 1, ELECTRO = 2, JUNKBOT = 3
	};
	void draw(sf::RenderWindow* window);
	
protected:
	int health;
	int shootTicker;
	int robotType;                                                                                                                       
	sf::RectangleShape range;

	
};

