#include<iostream>
#include<SFML/Graphics.hpp>

using namespace std;

int main() {
	int screenSize[2] = { 800, 500 };
	sf::RenderWindow window(sf::VideoMode(screenSize[0], screenSize[1]), "Robots Vs Monsters");
	sf::Event event;
	sf::Clock clock;
	sf::Mouse mouse;
	sf::Vector2i mousePos;
	bool mouseButtons[3] = { false, false, false };
	const float fps = 60.0;
	window.setFramerateLimit(fps);
	
	bool running = true;

	while (running) {

		while (window.pollEvent(event)) {
			mousePos = mouse.getPosition(window);
			mouseButtons[0] = mouse.isButtonPressed(mouse.Left);
			mouseButtons[1] = mouse.isButtonPressed(mouse.Middle);
			mouseButtons[2] = mouse.isButtonPressed(mouse.Right);
		}
		/*for i in entities in vector //just one iteration through vector and one functino call handles all the individual calls
			entities[i].draw(window)
		*/
	}

}