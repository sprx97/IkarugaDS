#include "bullet.h"
#include "ship.h"
#include "global.h"
#include <PA9.h>
#include "gfx/all_gfx.h"

bullet::bullet(int xpos, int ypos, int xvel, int yvel, bool c) {
	x = xpos;
	y = ypos;
	dx = xvel;
	dy = yvel;
	color = c;

	// select sprite to use
}
void bullet::remove() {

}
void bullet::update(){
	// move sprite
	// check hits
	// check off screen
}
