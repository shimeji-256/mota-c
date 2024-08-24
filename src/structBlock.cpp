#include "structBlock.h"
#include "global.h"

Wall::Wall() {
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

int Door::react(){
    if(keyGroup[doorCat]){
        keyGroup[doorCat]--;
        return 1;
    }
    return 0;
}

Wall wall;
Door door[4] = {Door(0), Door(1), Door(2), Door(3)};