#include <cstdio>
#include <vector>

#include "floor.h"
#include "structBlock.h"
#include "monster.h"
#include "global.h"
#include "eqItem.h"

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
    for (int i = 0; i < 11; i++) {
        for (int j = 0; j < 11; j++) {
            op[i][j]->putSelfImg(x + i * BIG_GRID, y + j * BIG_GRID);
        }
    }
    putimage_withalpha(NULL, PLAYER_PNG, x + X * BIG_GRID, y + Y * BIG_GRID);
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
    int cat = op[tmpX][tmpY]->getCat();
    if (cat != WALL) {
        X = tmpX;
        Y = tmpY;
    }

    if (op[tmpX][tmpY]->react() == 1) {
        op[tmpX][tmpY] = &sp;
    }
    return 0;
}

std::vector<Floor*> floorGroup;
Floor* currentFloor;