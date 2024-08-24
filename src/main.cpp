#include <graphics.h>
#include <cstdio>

#include "tools.h"
#include "global.h"
#include "menu.h"
// #include "keymsg.h"
#include "contr.h"

int main() {
    int x, y, h, lp = 0;
    initgraph(1008, 650, INIT_RENDERMANUAL);
    setbkcolor(GRAY);
    setfillcolor(GRAY);
    setcaption("mota");
    setfont(24, 0, "consolas");
    setcolor(BLACK);
    setbkmode(TRANSPARENT);
    initAll();
    while (is_run()) {
        delay_fps(120);
        cleardevice();
        // keymsg.update();
        contr.update();
        menu.update();
    }
    
    getch();
    closegraph();
    return 0;
}