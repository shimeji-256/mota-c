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

class Stair : public Space {
private:
    int stairCat;
public:
    int react();
    Stair(int stairCat);
};

extern Wall wall;
extern Door door[4];
extern Stair stair[2];

#endif