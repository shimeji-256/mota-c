#include "npc.h"
#include "tools.h"
#include "global.h"

NPC::NPC(const char* selfWords) {
    selected = 0;
    time = 0;
    transparent = 1;
    selfconv = new Conversat(9 * BIG_GRID, 5 * BIG_GRID, selfWords);
}

int NPC::react() {
    curConversat = selfconv;
    return 0;
}

int NPC::putSelfImg(int x, int y) {
    putimage_withalpha(NULL, FACE[selected], x, y);
    time++;
    if (time > 30) {
        selected = (selected + 1) % 2;
        time = 0;
    }
    return 0;
}

int NPC::getSelfImg(int x, int y, int h, int num) {
    for (int i = 0; i < num; i++) {
        FACE[i] = newimage();
        getComic(&FACE[i], x + i * h, y, h);
    }
    return 0;
}

NPC npc_1 = NPC("The tower has been corrupted by the Demon King, and you have to save the tower");
