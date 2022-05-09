#include"projectile.h"
#include <math.h>
#include<iostream>
using namespace std;

projectile::projectile(){
	entRect.setPosition(sf::Vector2f(-100, 100));
	entSprite.setPosition(sf::Vector2f(-100, 100));
}

projectile::~projectile(){}

projectile::projectile(int x, int y, int projType){
	entRect.setPosition(x, y);
	entSprite.setPosition(x, y);

	if (projType == ENERGYBALL) {
		velocity[0] = 5;
		
	}
	if (projType == BOLTS) {
		velocity[0] = 3;
	}
}

bool projectile::offscreen() {
	if (entRect.getPosition().x > 1280) {
		return true;
	}
	else if (entRect.getPosition().x < 0) {
		return true;
	}
	else
		return false;
	
}
void projectile::draw(sf::RenderWindow& window) {
	
}