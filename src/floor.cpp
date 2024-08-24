#include <cstdio>

#include "floor.h"
#include "wall.h"
#include "monster.h"
#include "global.h"

Floor::Floor(int level, int x, int y, int p[11][11]) {
    this->level = level;
    posX = x;
    inposX = x;
    posY = y;
    inposY = y;
    for (int i = 0; i < 11; i++) {
        for (int j = 0; j < 11; j++) {
            switch (p[j][i]) {
            case SPACE: op[i][j] = &sp; break;
            case WALL: op[i][j] = &wall; break;
            case MONSTER: op[i][j] = &monst; break;
            default:
                break;
            }
        }
    }
}

int Floor::toFloor() {
    X = posX;
    Y = posY;
    inposX = posX;
    inposY = posY;
    Dx = 0;
    Dy = 0;
    Level = level;
    return 0;
}

int Floor::getLevel(){
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

int Floor::moveAndRea(){
    int tmpX = X + Dx, tmpY = Y + Dy;
    Dx = 0;
    Dy = 0;
    if(tmpX < 0 || tmpY < 0 || tmpX > 10 || tmpY > 10){
        return 1;
        // printf("wall/n");
    }
    int cat = op[tmpX][tmpY]->getCat();
    if(cat == WALL){
        // printf("wall/n");
        return 1;
    }else{
        X = tmpX;
        Y = tmpY;
        if(op[X][Y]->react() == 1){
            op[X][Y] = &sp;
        }
    }

    return 0;
}