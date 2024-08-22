#include "floor.h"
#include "wall.h"
#include "monster.h"
#include "global.h"

Floor::Floor(int x, int y, int p[11][11]) {
    posX = x;
    inposX = x;
    posY = y;
    inposY = y;
    for (int i = 0; i < 11; i++) {
        for (int j = 0; j < 11; j++) {
            switch (p[i][j]) {
            case SPACE: op[i][j] = &sp; break;
            case WALL: op[i][j] = &wall; break;
            case MONSTER: op[i][j] = &monst; break;
            default:
                break;
            }
        }
    }
}

int Floor::printFloor(int x, int y) {
    for(int i = 0; i < 11; i++){
        for(int j = 0; j < 11; j ++){
            op[i][j]->putSelfImg(x+j*BIG_GRID, y+i*BIG_GRID);
        }
    }
    putimage_withalpha(NULL, PLAYER_PNG,x+inposX*BIG_GRID, y + inposY*BIG_GRID);
    return 0;
}