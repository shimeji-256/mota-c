#ifndef _OBJ_H_
#define _OBJ_H_

#include <graphics.h>

class obj {
public:
    int cat;
    PIMAGE* im;
    // int posX, posY;
    int getCat();
    int getSelfImg(PIMAGE * SOURCE);
    int putSelfImg(int x, int y);
    virtual int react() = 0;
};

class space : public obj {
public:
    int react();
    int putSelfImg(int x, int y);
    space();
};

extern space sp;

#endif