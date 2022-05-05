#include"projectile.h"
#include <math.h>
#include<iostream>
using namespace std;

projectile::projectile(){
	entRect.setPosition(sf::Vector2f(0, 0));

}

projectile::~projectile(){}

projectile::projectile(int x, int y){
	entRect.setPosition(x, y);
	

}


void projectile::kill(){
	exists = false;
}
bool projectile::offscreen() {
	if (entRect.getPosition().x > 800) {
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