#include "structBlock.h"
#include "global.h"
#include "floor.h"

Wall::Wall() {
    im = &WALL_PNG;
    cat = 1;
}

int Wall::react() {
    printfUnder("hit the wall");
    return 0;
}

Door::Door(int doorCat) {
    cat = 1;
    this->doorCat = doorCat;
}

int Door::react() {
    if (keyGroup[doorCat]) {
        keyGroup[doorCat]--;
        return 1;
    }
    return 0;
}

Space* Door::death(){
    return new Door_Death(doorCat);
}

Stair::Stair(int stairCat) {
    cat = 1;
    this->stairCat = stairCat;
}

int Stair::react() {
    doStairs(stairCat);
    return 0;
}

Wall wall;
Door door[4] = { Door(0), Door(1), Door(2), Door(3) };
Stair stair[2] = { Stair(-1), Stair(1) };