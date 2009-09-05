#include "bullet.h"
#include "ship.h"
#include "global.h"
#include <PA9.h>
#include "gfx/all_gfx.h"

bullet::bullet(int xpos, int ypos, int xvel, int yvel, int xacc, int yacc, bool c) {
	x = xpos;
	y = ypos;
	dx = xvel;
	dy = yvel;
	ax = xacc;
	ay = yacc;
	color = c;
	spritenum = -1;
	for(int n = BULLETS; n < 128; n++) if(PA_GetSpriteX(MAIN_SCREEN, n) == 504) spritenum = n;
	if(spritenum != -1) {
		PA_DualSetSpriteXY(spritenum, x, y);
		PA_DualStartSpriteAnim(spritenum, CURRENTCOLOR, CURRENTCOLOR, 1);
	}
	else while(true) {}
}
bool bullet::update(){
	x += dx;
	y += dy;
	dx += ax;
	dy += ay;
	PA_DualSetSpriteXY(spritenum, x, y);
	// check hits
	if(x < -8 || y < -8 || x > 256 || y > 384) {
		PA_DualSetSpriteXY(spritenum, -8, -8);
		return false;
	}
	return true;
}
