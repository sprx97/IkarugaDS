#include "enemy.h"
#include "bullet.h"
#include "global.h"
#include <PA9.h>
#include "gfx/all_gfx.h"

enemy::enemy(int xpos, int ypos) {
	x = xpos;
	y = ypos;
	health = 1;
	color = PA_RandMinMax(0, 1);
	spritenum = -1;
	for(int n = ENEMIES; n < BULLETS; n++) if(PA_GetSpriteX(MAIN_SCREEN, n) == 480) spritenum = n;
	if(spritenum != -1) {
		PA_DualSetSpriteXY(spritenum, x, y);
		PA_DualStartSpriteAnim(spritenum, color, color, 1);
	}
	else while(true) {}
}
bool enemy::update() {
	if(health <= 0) {
		PA_DualSetSpriteXY(spritenum, -32, -32);
		return false;
	}
	return true;
}
