#ifndef _SPACE_H_
#define _SPACE_H_

#include <graphics.h>
#include <vector>
#include <cstdio>

/*
空白类，所有图上实体的父类
*/
class Space {
public:
    bool transparent;
    PIMAGE* im;
    int getCat();
    virtual int getSelfImg(PIMAGE* SOURCE);
    virtual int putSelfImg(int x, int y);
    virtual int react();
    virtual Space* death();
    Space();
};

class Monster_Death : public Space {
private:
    int time;
public:
    int putSelfImg(int x, int y);
    Monster_Death();
};

class Door_Death : public Space {
private:
    int wallCat;
    int time;
    short select;
    std::vector<PIMAGE>* com;
public:
    int putSelfImg(int x, int y);
    Door_Death(int wallCat);
};

extern Space sp;
extern std::vector<Space*> inBag;
extern Monster_Death monster_death;
extern Door_Death wall_death[4];

#endif