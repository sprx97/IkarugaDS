#ifndef GLOBAL_H //header guard
#define GLOBAL_H
#define COLOR256 1
#define SHIP 0
#define SHIELD 1
#define ENEMIES 2
#define BULLETS 15
#define LIGHT 0
#define DARK 1
#define MAIN_SCREEN 1
#define SUB_SCREEN 0

#include <vector>
#include "ship.h"
#include "enemy.h"

ship* getPlayer();
std::vector<enemy*> getEnemies();

#endif //GLOBAL_H header guard
