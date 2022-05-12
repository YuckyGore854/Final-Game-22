#pragma once
#include "entity.h"
class slot : virtual public entity {
public:
	slot(int x, int y, int type, int numb, textures* text);
	void update();
	virtual void update(bool lClick, bool hover, int money, sf::RenderWindow& window, sf::Vector2i mousePos, int numHeld);
	int click(bool lClick, bool hover, int money, sf::RenderWindow& window, sf::Vector2i mousePos, int numHeld);
	int numReturn();
	bool getHold() { return holding; }
	void draw(sf::RenderWindow window);
	//robot* spawnBot(float xpos, float ypos);
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
			