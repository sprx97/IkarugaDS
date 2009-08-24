#include "ship.h"
#include "global.h"
#include <PA9.h>

ship::ship(){
	x = 112;
	y = 352;
	isWhite=true;
}
void ship::switchColor(){
	PA_DualStartSpriteAnim(IKARUGA, !CURRENTCOLOR, !CURRENTCOLOR, 1);
	isWhite = !isWhite;
}
void ship::update(){
	if(Pad.Newpress.B) switchColor();

	int dx = 3*(Pad.Held.Right-Pad.Held.Left);
	int dy = 3*(Pad.Held.Down-Pad.Held.Up);

	x += dx;
	y += dy;

	if(x > 224) x = 224;
	if(x < 0) x = 0;
	if(y > 352) y = 352;
	if(y < 0) y = 0;

	PA_DualSetSpriteXY(IKARUGA, x, y);
}
