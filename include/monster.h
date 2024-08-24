#ifndef _MONSTER_H_
#define _MONSTER_H_

#include "space.h"

class monster : public Space{
private:
    int heart, attack, defence, money;
public:
    monster();
    int react();
};

extern monster monst;

#endif