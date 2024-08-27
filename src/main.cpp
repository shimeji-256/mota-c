#include <graphics.h>
#include <cstdio>

#include "tools.h"
#include "global.h"
#include "menu.h"
#include "contr.h"

int main() {
    int x, y, h, lp = 0;
    initgraph(SCREEN_WIDTH, SCREEN_HEIGHT, INIT_RENDERMANUAL);
    setbkcolor(GRAY);
    setfillcolor(GRAY);
    setcaption("mota");
    setfont(24, 0, "consolas");
    setcolor(BLACK);
    setbkmode(TRANSPARENT);
    // setlocat
    initAll();
    while (is_run()) {
        delay_fps(120);
        cleardevice();
        contr.update();
        menu.update();
    }
    
    closegraph();
    return 0;
}