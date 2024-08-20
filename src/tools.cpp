#include <graphics.h>
#include <cstdio>

#include "global.h"
#include "menu.h"
#include "tools.h"

int initImg() {
    GLO_PNG = newimage();
    int p = getimage(GLO_PNG, "PNG", "IMAGE_PNG_GLO");
    BIG_GLO_PNG = newimage((int)(1.5 * getwidth(GLO_PNG)), (int)(1.5 * getheight(GLO_PNG)));
    putimage(BIG_GLO_PNG, 0, 0, (int)(1.5 * getwidth(GLO_PNG)), (int)(1.5 * getheight(GLO_PNG)), GLO_PNG, 0, 0, getwidth(GLO_PNG), getheight(GLO_PNG));
    return 0;
}

// PIMAGE* getComic(int x, int y, int h, int num) {

// }

// int initMonster() {

// }

// int initMap() {

// }

int initAll() {
    initImg();
    menu.load();
    return 0;
}