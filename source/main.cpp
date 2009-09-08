// Game designed by TJgames of TJHSST
// Head Developer(s): Jeremy Vercillo
// 8/09 - ???

// The rights to Ikaruga and all related images and concepts belong to
// Treasure, Sega, or other companies. This is a fan made game; it is not
// made for profit, just for fun.

#include <vector>

#include <PA9.h>
#include "gfx/all_gfx.c"
#include "ship.h"
#include "enemy.h"
#include "global.h"

std::vector<enemy*> enemies;
ship* player;

ship* getPlayer() { return player; }
std::vector<enemy*> getEnemies() { return enemies; }

int main(int argc, char** argv) {
	PA_Init();
	PA_InitVBL();
	
	defaultExceptionHandler();

	PA_SetScreenSpace(0);

	player = new ship();

	PA_DualLoadSpritePal(ENEMIES, (void*)ikaruga_Pal);
	for(int n = ENEMIES; n < BULLETS; n++) {
		PA_DualCreateSprite(n, (void*)ikaruga_Sprite, OBJ_SIZE_32X32, COLOR256, ENEMIES, -32, -32);
		PA_DualSetSpriteVflip(n, true);
	}
	PA_DualLoadSpritePal(BULLETS, (void*)bullets_Pal);
	for(int n = BULLETS; n < 128; n++) PA_DualCreateSprite(n, (void*)bullets_Sprite, OBJ_SIZE_8X8, COLOR256, BULLETS, -8, -8);

	for(int x = 32; x < 224; x+=32)
		for(int y = 0; y < 32; y+=32)
			enemies.push_back(new enemy(x, y));

	while(true) {
		player->update();
		std::vector<enemy*> temp;
		for(int n = 0; n < (int)enemies.size(); n++) if(enemies[n]->update()) temp.push_back(enemies[n]);
		enemies = temp;
				
		PA_WaitForVBL();
	}
	
	return 0;
}
