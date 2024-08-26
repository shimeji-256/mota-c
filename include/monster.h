#ifndef _MONSTER_H_
#define _MONSTER_H_

#include <vector>
#include <string>

#include "space.h"
#include "global.h"

class Monster : public Space{
private:
    std::vector<PIMAGE> *FACE;
    char name[20];
    int time, selected;
    int heart, attack, defence, money;
public:
    Monster(const char* name, int heart, int attack, int defence, int money, std::vector<PIMAGE> *FS);
    int putSelfImg(int x, int y);
    Space* death();
    int react();
};

extern Monster *monsterGroup[monsterNum];

#endif