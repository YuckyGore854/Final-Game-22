#include "robot.h"

robot::robot() {
	health = 100;
	shootTicker = 0;
	type = JUNKBOT;
	if (type == JUNKBOT) {
		entSprite.setTexture(textReferece->junkbot);
	}
	entSprite.setTexture(textReferece->junkbot);
}

void robot::update() {

}

projectile shoot() {
	projectile nProj;
	return nProj;
}