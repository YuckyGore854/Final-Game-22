#pragma once
#include "entity.h"
class slot : public entity {
public:
	slot(int x, int y) { entSprite.setPosition(sf::Vector2f(x, y)); }
	int type = 0;//1 generator, 2 "peashooter", etc
	//
	int cost = 0;
	int cooldown = 0;
	bool snappable = false;
};

//if enoughMoney && clicknhold && cooldown == 0
	//if mousereleased
		//if snappable
			//money -= cost
			//vector append robot
		// if !snappable 
		    //resetposition
//if !clicknhold 
	//resetposition
			