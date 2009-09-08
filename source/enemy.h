#ifndef ENEMY_H
#define ENEMY_H

#include "bullet.h"
#include <vector>

class enemy {
	public:
		enemy(int xpos, int ypos);
		int x;
		int y;
		int health;
		bool color;
		int spritenum;
		int reloadtime;
		std::vector<bullet*> bullets;
		
		bool update();
};
#endif
