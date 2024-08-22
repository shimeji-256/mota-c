#ifndef _FLOOR_H
#define _FLOOR_H

// enum objectTh{
//     SPACE,
//     WALL,
//     EQUIP,
//     MONSTER
// };

// enum wallTh{
//     WALL,
//     SHOP_B,
//     SHOP_P,
//     SHOP_O,
//     DOOR
// };

// enum equipTh{
//     SOWDER,
// };
#include "obj.h"

enum objectTh{
    SPACE,
    WALL,
    KEY,
    MONSTER,
    UPSTAIR,
    DOWNSTAIR
};

class Floor {
private:
    int posX, posY;
    int inposX, inposY;
    obj* op[11][11];
public:
    Floor(int x, int y, int p[11][11]);
    int printFloor(int x, int y);
};

// extern Floor floor;

#endif