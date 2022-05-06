#pragma once
#include "entity.h"
class slot : public entity {
public:
	slot(int x, int y, std::string file);
	void update();
	void update(bool lClick, bool hover, int money, sf::RenderWindow& window, sf::Vector2i mousePos);
	bool hover(int mouseX, int mouseY);
	int click(bool lClick, bool hover, int money, sf::RenderWindow& window, sf::Vector2i mousePos);
	//void draw(sf::RenderWindow& window);
protected:
	sf::Vector2f originalPos;
	int type = 0;//1 generator, 2 "peashooter", etc
	bool holding = false;
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
			