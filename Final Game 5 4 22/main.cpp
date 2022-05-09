#include<iostream>
#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include<vector>
#include"entity.h"
#include"Grid.h"
#include"projectile.h"
#include"slot.h"


using namespace std;

int main() {
	const int WIDTH = 1280;
	const int HEIGHT = 720;
	sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Robots Vs Monsters");
	sf::Event event;
	sf::Clock clock;
	sf::Mouse mouse;
	sf::Cursor cursor;
	
	sf::Vector2i mousePos;

	bool mouseButtons[3] = { false, false, false };
	const float fps = 60.0;
	window.setFramerateLimit(fps);

	int PlayerHealth = 5;
	int PlayerEnergy = 0;
	int BotSlots = 4;
	int money = 50;
	bool PlayerDead = false;
	int holding = 0;

	vector<entity*> entVec;
	vector<entity*>::iterator entIter;
	
	bool running = true;
	entVec.push_back(new entity("heyall.png"));

	
	for (int i = 0; i < BotSlots; i++) {
		entVec.push_back(new slot(i*100 + 50, 20, "heyall.png", i, 3));
	}
	while (running) {
		window.clear(sf::Color(255, 0, 255));
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				running = false;
			mousePos = mouse.getPosition(window); // mousepos and button input
			mouseButtons[0] = mouse.isButtonPressed(mouse.Left);
			mouseButtons[1] = mouse.isButtonPressed(mouse.Middle);
			mouseButtons[2] = mouse.isButtonPressed(mouse.Right);
		}
		
		/*for i in entities in vector //just one iteration through vector and one functino call handles all the individual calls
			entities[i].draw(window)
		*/
		for (entIter = entVec.begin(); entIter != entVec.end(); ++entIter) {
			if ((*entIter)->getStr() == "slot") {

				//if (holding == 0) {
				(*entIter)->update(mouseButtons[0], (*entIter)->hover(mousePos.x, mousePos.y), money, window, mousePos);
					//holding = (*entIter)->getNum();
				//}
				//else
					//holding = 0;
				/*if ((*entIter)->hover(mousePos.x, mousePos.y)) {
					cursor.loadFromSystem(cursor.Hand);
					window.setMouseCursor(cursor);
				}
				else {
					cursor.loadFromSystem(cursor.Arrow);
					window.setMouseCursor(cursor);
				}*/
			}
		}
		
		for (entIter = entVec.begin(); entIter != entVec.end(); ++entIter) {
			(*entIter)->draw(window);
		}
		window.display();
	}
	
}