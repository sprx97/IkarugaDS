#include "bullet.h"
#include "ship.h"
#include "global.h"
#include <PA9.h>
#include "gfx/all_gfx.h"

bullet::bullet(int xpos, int ypos, int xvel, int yvel, int xacc, int yacc, bool c, bool e) {
	x = xpos;
	y = ypos;
	dx = xvel;
	dy = yvel;
	ax = xacc;
	ay = yacc;
	color = c;
	isenemy = e;
	spritenum = -1;
	for(int n = BULLETS; n < 128; n++) if(PA_GetSpriteX(MAIN_SCREEN, n) == 504) spritenum = n;
	if(spritenum != -1) {
		PA_DualSetSpriteXY(spritenum, x, y);
		PA_DualStartSpriteAnim(spritenum, color, color, 1);
	}
	else while(true) {}
}
bool bullet::update(){
	std::vector<enemy*> enemies = getEnemies();
	ship* player = getPlayer();

	x += dx;
	y += dy;
	dx += ax;
	dy += ay;
	PA_DualSetSpriteXY(spritenum, x, y);
	if(isenemy && color != player->color) {
		// check collision with player
	}
	else {
		for(int n = 0; n < (int)enemies.size(); n++) {
			if(((x > enemies[n]->x && x < enemies[n]->x+32) || (x+8 > enemies[n]->x && x+8 < enemies[n]->x+32)) && ((y > enemies[n]->y && y < enemies[n]->y+32) || (y+8 > enemies[n]->y && y+8 < enemies[n]->y+32))) {
				if(color == enemies[n]->color) enemies[n]->health-=1;
				else enemies[n]->health-=5;
				PA_DualSetSpriteXY(spritenum, -8, -8);
				return false;
			}
		}
	}
	if(x < -8 || y < -8 || x > 256 || y > 384) {
		PA_DualSetSpriteXY(spritenum, -8, -8);
		return false;
	}
	return true;
}
