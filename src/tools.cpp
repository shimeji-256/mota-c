#include <graphics.h>
#include <cstdio>

#include "global.h"
#include "menu.h"
#include "tools.h"
#include "structBlock.h"
#include "monster.h"
#include "floor.h"

Floor * tf;

int initImg() {
    GLO_PNG = newimage();
    int p = getimage(GLO_PNG, "PNG", "IMAGE_PNG_GLO");
    BIG_GLO_PNG = newimage((int)(1.5 * getwidth(GLO_PNG)), (int)(1.5 * getheight(GLO_PNG)));
    putimage(BIG_GLO_PNG, 0, 0, (int)(1.5 * getwidth(GLO_PNG)), (int)(1.5 * getheight(GLO_PNG)), GLO_PNG, 0, 0, getwidth(GLO_PNG), getheight(GLO_PNG));
    getComic(&SLIME_PNG, 0, 1, 1);
    getComic(&WALL_PNG, 2, 71, 1);
    getComic(&SPACE_PNG, 0, 0, 1);
    getComic(&PLAYER_PNG, 0, 24, 1);
    sp.getSelfImg(&SPACE_PNG);
    wall.getSelfImg(&WALL_PNG);
    monst.getSelfImg(&SLIME_PNG);
    return 0;
}

void getComic(PIMAGE* DST, int x, int y, int h) {
    *DST = newimage();
    getimage(*DST, BIG_GLO_PNG, x*BIG_GRID, y*BIG_GRID, h*BIG_GRID, h*BIG_GRID);
}

// int initMonster() {
    
// }

int initMap() {
    int testfloor[11][11] = {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                            {0, 0, 0, 1, 0, 0, 0, 0, 3, 0, 0}, 
                            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                            {0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0},
                            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                            {0, 0, 0, 3, 0, 0, 0, 0, 1, 0, 0},
                            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};
    tf = new Floor(1 , 0, 0, testfloor);
    return 0;
}

int initAll() {
    initImg();
    initMap();
    menu.load();
    return 0;
}