#ifndef _FLOOR_H
#define _FLOOR_H

#include <vector>

#include "space.h"

int doStairs(int i);

enum objectTh {
    SPACE,
    WALL,
    DOWNSTAIR,
    UPSTAIR,
    YELLO_DOOR = 7,
    BLUE_DOOR,
    RED_DOOR,
    GREEN_DOOR,
    YELLO_KEY,
    BLUE_KEY,
    RED_KEY,
    GREEN_KEY,
    BLOOD_BOTTLE_A,
    BLOOD_BOTTLE_B,
    ATTACK_JEW,
    DEFENCE_JEW
};

class Floor {
private:
    int upPosX, upPosY;
    int downPosX, downPosY;
    int level;
    Space* op[11][11];
public:
    Floor(int level, int upX, int upY, int downX, int downY, short floorMsg[11][11]);
    int getLevel();
    int toFloor();
    int printFloor(int x, int y);
    int moveAndRea();
};

extern std::vector<Floor*> floorGroup;
extern Floor* currentFloor;

#endif