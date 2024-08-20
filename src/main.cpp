#include <graphics.h>
#include <cstdio>

#include "tools.h"
#include "global.h"
#include "menu.h"

int main() {
    int x, y, h, lp = 0;
    initgraph(1008, 672, INIT_RENDERMANUAL);
    setbkcolor(GRAY);
    setfillcolor(GRAY);
    setcaption("mota");
    setfont(24, 0, "consolas");
    setcolor(BLACK);
    setbkmode(TRANSPARENT);
    initAll();
    while (is_run()) {
        delay_fps(120);
        menu.update();
    }
    
    getch();
    closegraph();
    return 0;
}