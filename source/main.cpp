// Game designed by TJgames of TJHSST
// Head Developer(s): Jeremy Vercillo
// 8/09 - ???

// The rights to Ikaruga and all related images and concepts belong to
// Treasure, Sega, or other companies. This is a fan made game; it is not
// made for profit, just for fun.

#include <PA9.h>
#include "gfx/all_gfx.c"
#include "ship.h"
#include "global.h"

using namespace std;

int X = 112, Y = 352;

int main(int argc, char** argv) {
	PA_Init();
	PA_InitVBL();
	
	defaultExceptionHandler();

	PA_SetScreenSpace(0);

	ship* player = new ship();

	while(true) {
		player->update();
		PA_WaitForVBL();
	}
	
	return 0;
}
