//Gfx converted using Mollusk's PAGfx Converter

//This file contains all the .h, for easier inclusion in a project

#ifndef ALL_GFX_H
#define ALL_GFX_H

#ifndef PAGfx_struct
    typedef struct{
    void *Map;
    int MapSize;
    void *Tiles;
    int TileSize;
    void *Palette;
    int *Info;
} PAGfx_struct;
#endif

extern const unsigned char ikaruga_Sprite[2048] __attribute__ ((aligned (4))) ;  // Pal : ikaruga_Pal
extern const unsigned short ikaruga_Pal[24] __attribute__ ((aligned (4))) ;
extern const unsigned char shield_Sprite[8192] __attribute__ ((aligned (4))) ;  // Pal : shield_Pal
extern const unsigned short shield_Pal[73] __attribute__ ((aligned (4))) ;

#endif

