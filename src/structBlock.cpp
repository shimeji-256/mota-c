#include "structBlock.h"
#include "global.h"
#include "floor.h"

Wall::Wall() {
    im = &WALL_PNG;
    transparent = 1;
}

int Wall::react() {
    printfUnder("hit the wall");
    return 0;
}

Door::Door(int doorCat) {
    transparent = 1;
    this->doorCat = doorCat;
}

int Door::react() {
    if (keyGroup[doorCat]) {
        keyGroup[doorCat]--;
        printfUnder("Used key, the door open");
        return 1;
    }
    printfUnder("don't have the key");
    return 0;
}

Space* Door::death(){
    return new Door_Death(doorCat);
}

Stair::Stair(int stairCat) {
    transparent = 1;
    this->stairCat = stairCat;
}

int Stair::react() {
    if(doStairs(stairCat)){
        if(stairCat > 0){
            printfUnder("go upstair");
        }else{
            printfUnder("go downstair");
        }
    }
    return 0;
}

Wall wall;
Door door[4] = { Door(0), Door(1), Door(2), Door(3) };
Stair stair[2] = { Stair(-1), Stair(1) };