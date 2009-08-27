#include "ship.h"
#include "global.h"
#include <PA9.h>
#include "gfx/all_gfx.h"

ship::ship(){
	x = 112;
	y = 336;
	isWhite=true;
	
	PA_DualLoadSpritePal(IKARUGA, (void*)ikaruga_Pal);
	PA_DualCreateSprite(IKARUGA, (void*)ikaruga_Sprite, OBJ_SIZE_32X32, COLOR256, IKARUGA, x, y);
	PA_DualStartSpriteAnim(IKARUGA, LIGHT, LIGHT, 1);
	
	PA_DualLoadSpritePal(SHIELD, (void*)shield_Pal);
	PA_DualCreateSprite(SHIELD, (void*)shield_Sprite, OBJ_SIZE_64X64, COLOR256, SHIELD, x-16, y-16);
	PA_DualStartSpriteAnim(SHIELD, LIGHT, LIGHT, 1);
}
void ship::switchColor(){
	PA_DualStartSpriteAnim(IKARUGA, !CURRENTCOLOR, !CURRENTCOLOR, 1);
	PA_DualStartSpriteAnim(SHIELD, CURRENTCOLOR, CURRENTCOLOR, 1);
	isWhite = !isWhite;
}
void ship::update(){
	if(Pad.Newpress.B) switchColor();

	int dx = 3*(Pad.Held.Right-Pad.Held.Left);
	int dy = 3*(Pad.Held.Down-Pad.Held.Up);

	x += dx;
	y += dy;

	if(x > 208) x = 208;
	if(x < 16) x = 16;
	if(y > 336) y = 336;
	if(y < 16) y = 16;

	PA_DualSetSpriteXY(IKARUGA, x, y);
	PA_DualSetSpriteXY(SHIELD, x-16, y-16);
}
