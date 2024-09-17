#include <cstdio>
#include <vector>

#include "floor.h"
#include "structBlock.h"
#include "monster.h"
#include "global.h"
#include "eqItem.h"
#include "npc.h"

int doStairs(int i) {
    int tmpFloor = i + currentFloor->getLevel();
    if (tmpFloor < minFloor) {
        printfUnder("No lower floor");
        return 0;
    } else if (tmpFloor > floorGroup.size() - 1) {
        printfUnder("No higher floor");
        return 0;
    }
    currentFloor = floorGroup[tmpFloor];
    return 1;
}

int printfPlayer(int x, int y) {
    putimage_withalpha(NULL, (*CUR_PLAYER_ROW)[CUR_PLAYER_PNG_ID], x + X * BIG_GRID, y + Y * BIG_GRID);
    TIME++;
    if (TIME >= 30) {
        CUR_PLAYER_PNG_ID = (CUR_PLAYER_PNG_ID + 1) % ((*CUR_PLAYER_ROW).size());
        TIME = 0;
    }
    return 0;
}


Floor::Floor(int level, int upX, int upY, int downX, int downY, short floorMsg[11][11]) {
    this->level = level;
    upPosX = upX;
    downPosX = downX;
    upPosY = upY;
    downPosY = downY;
    for (int i = 0; i < 11; i++) {
        for (int j = 0; j < 11; j++) {
            switch (floorMsg[j][i]) {
            case SPACE: op[i][j] = &sp; break;
            case WALL: op[i][j] = &wall; break;
            case DOWNSTAIR: op[i][j] = &stair[0]; break;
            case UPSTAIR: op[i][j] = &stair[1]; break;
            case YELLO_DOOR: op[i][j] = &door[0]; break;
            case BLUE_DOOR: op[i][j] = &door[1]; break;
            case RED_DOOR: op[i][j] = &door[2]; break;
            case GREEN_DOOR: op[i][j] = &door[3]; break;
            case YELLO_KEY: op[i][j] = &keys[0]; break;
            case BLUE_KEY: op[i][j] = &keys[1]; break;
            case RED_KEY: op[i][j] = &keys[2]; break;
            case GREEN_KEY: op[i][j] = &keys[3]; break;
            case BLOOD_BOTTLE_A: op[i][j] = &bloodBottles[0]; break;
            case BLOOD_BOTTLE_B: op[i][j] = &bloodBottles[1]; break;
            case ATTACK_JEW: op[i][j] = &attackJew; break;
            case DEFENCE_JEW: op[i][j] = &defenceJew; break;
            case UP_AND_DOWN_ST: op[i][j] = &Up_And_Down_Stairer; break;
            case STONE_SWORD: op[i][j] = &swordGroup[0]; break;
            case IRON_SWORD: op[i][j] = &swordGroup[1]; break;
            case SIL_SWORD: op[i][j] = &swordGroup[2]; break;
            case WAR_SWORD: op[i][j] = &swordGroup[3]; break;
            case SAC_SWORD: op[i][j] = &swordGroup[4]; break;
            case DRA_SWORD: op[i][j] = &swordGroup[5]; break;
            case STONE_SHIELD: op[i][j] = &shieldGroup[0]; break;
            case IRON_SHIELD: op[i][j] = &shieldGroup[1]; break;
            case SIL_SHIELD: op[i][j] = &shieldGroup[2]; break;
            case WAR_SHIELD: op[i][j] = &shieldGroup[3]; break;
            case SAC_SHIELD: op[i][j] = &shieldGroup[4]; break;
            case DRA_SHIELD: op[i][j] = &shieldGroup[5]; break;
            case NPC_1: op[i][j] = &npc_1; break;
                // case YELLO_DOOR: op[i][j] = &stair[1]; break;
            default: op[i][j] = monsterGroup[floorMsg[j][i] - 100]; break;
            }
        }
    }
}

int Floor::toFloor() {
    if (Level > level) {
        X = downPosX;
        Y = downPosY;
    } else {
        X = upPosX;
        Y = upPosY;
    }
    Dx = 0;
    Dy = 0;
    Level = level;
    return 0;
}

int Floor::getLevel() {
    return level;
}

int Floor::printFloor(int x, int y) {
    printfPlayer(x, y);
    for (int i = 0; i < 11; i++) {
        for (int j = 0; j < 11; j++) {
            if (op[i][j]->putSelfImg(x + i * BIG_GRID, y + j * BIG_GRID)) {
                op[i][j] = &sp;
            }
        }
    }
    return 0;
}

int Floor::moveAndRea() {
    int tmpX = X + Dx, tmpY = Y + Dy;
    Dx = 0;
    Dy = 0;
    if (tmpX < 0 || tmpY < 0 || tmpX > 10 || tmpY > 10) {
        printfUnder("hit the wall");
        return 0;
    }

    if (!op[tmpX][tmpY]->getCat()) {
        X = tmpX;
        Y = tmpY;
    }
    int tmpi = op[tmpX][tmpY]->react();
    if (tmpi == 1) {
        op[tmpX][tmpY] = op[tmpX][tmpY]->death();
    } else if (tmpi < 0) {
        curConversat = &death;
    }
    return 0;
}

std::vector<Floor*> floorGroup;
Floor* currentFloor;

// bossFloor::bossFloor(int level, int upX, int upY, int downX, int downY, short floorMsg[11][11]) {
//     this->level = level;
//     upPosX = 10;
//     downPosX = 10;
//     upPosY = 9;
//     downPosY = 9;
//     op[10][10] = &stair[0];
//     op[4][4] = bossp;
// };

bossFloor::bossFloor(int level, short floorMsg[11][11]) : Floor(level, 10, 9, 10, 9, floorMsg) {
    op[10][10] = &stair[0];
    op[4][4] = bossp;
}

int bossFloor::moveAndRea() {
    int tmpX = X + Dx, tmpY = Y + Dy;
    Dx = 0;
    Dy = 0;
    if (tmpX < 0 || tmpY < 0 || tmpX > 10 || tmpY > 10) {
        printfUnder("hit the wall");
        return 0;
    }
    X = tmpX;
    Y = tmpY;
    if(X > 3 && Y > 3 && X<7 && Y < 7){
        int tmpi = bossp->react();
        if(tmpi > 0){
            op[tmpX][tmpY] = op[tmpX][tmpY]->death();
            curConversat = &winC;
        }else{
            curConversat = &death;
        }
    }
    return 0;
}
