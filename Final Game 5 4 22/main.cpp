#include<iostream>
#include<SFML/Graphics.hpp>
#include<vector>
#include"entity.h"
#include"Grid.h"
#include"projectile.h"


using namespace std;

int main() {
	const int WIDTH = 800;
	const int HEIGHT = 500;
	int screenSize[2] = { 800, 500 };
	sf::RenderWindow window(sf::VideoMode(screenSize[0], screenSize[1]), "Robots Vs Monsters");
	sf::Event event;
	sf::Clock clock;
	sf::Mouse mouse;
	sf::Vector2i mousePos;
	bool mouseButtons[3] = { false, false, false };
	const float fps = 60.0;
	window.setFramerateLimit(fps);

	int PlayerHealth = 5;
	int PlayerEnergy = 0;
	int BotSlots = 4;
	bool PlayerDead = false;

	vector<entity*> entVec;
	vector<entity*>::iterator entIter;
	
	bool running = true;
	entVec.push_back(new entity("heyall.png"));
	
	
	while (running) {

		while (window.pollEvent(event)) {
			mousePos = mouse.getPosition(window); // mousepos and button input
			mouseButtons[0] = mouse.isButtonPressed(mouse.Left);
			mouseButtons[1] = mouse.isButtonPressed(mouse.Middle);
			mouseButtons[2] = mouse.isButtonPressed(mouse.Right);
		}
		
		/*for i in entities in vector //just one iteration through vector and one functino call handles all the individual calls
			entities[i].draw(window)
		*/

		window.clear(sf::Color(255, 0, 255));
		for (entIter = entVec.begin(); entIter != entVec.end(); ++entIter) {
			(*entIter)->draw(window);
		}
		window.display();
	}
	
}