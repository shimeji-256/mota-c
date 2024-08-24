#ifndef _STRUCTBLOCK_H_
#define _STRUCTBLOCK_H_

#include "space.h"

class Wall : public Space {
public:
    Wall();
    int react();
};

class Door : public Space {
private:
    int doorCat;
public:
    int react();
    Door(int doorCat);
};

extern Wall wall;
extern Door door[4];

#endif