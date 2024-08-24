#ifndef _KEY_H_
#define _KEY_H_

#include "space.h"

enum keyDef {
    yellowKey,
    blueKey,
    redKey,
    greenKey
};

class Key :public Space {
private:
    int keyCat;
public:
    int react();
    Key();
};

#endif