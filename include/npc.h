#ifndef _NPC_H_
#define _NPC_H_

#include "space.h"
#include "conversat.h"

class NPC : public Space{
private:
    Conversat *selfconv;
    PIMAGE FACE[2];
    int selected, time;
public:
    NPC(const char * selfWords);
    int react();
    int putSelfImg(int x, int y);
    int getSelfImg(int x, int y, int h, int num);
};

extern NPC npc_1;

#endif
