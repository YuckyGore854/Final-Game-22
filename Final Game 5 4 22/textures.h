#pragma once
#include<SFML/Graphics.hpp>
#include<vector>

class textures {
public:
	textures();

	sf::Texture junkbot;
	sf::Texture electrobot;
	sf::Texture defaultImg;
	//sf::Texture generator;
	enum robots {
		NONE = 0, GENERATOR = 1, ELECTRO = 2, JUNKBOT = 3
	};
};