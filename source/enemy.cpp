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
	reloadtime = 0;
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
		for(int n = 0; n < (int)bullets.size(); n++) PA_DualSetSpriteXY(bullets[n] -> spritenum, -8, -8);
		return false;
	}
	if(reloadtime < 0) {
		bullets.push_back(new bullet(x+12, y+32, 0, 5, 0, 0, color, true));
		reloadtime = 5;
	}
	reloadtime--;
		
	std::vector<bullet*> temp;
	for(int n = 0; n < (int)bullets.size(); n++) if(bullets[n] -> update()) temp.push_back(bullets[n]);
	bullets = temp;
	
	PA_DualSetSpriteXY(spritenum, x, y);
	
	return true;
}
