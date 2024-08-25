#include <graphics.h>

#include "global.h"
#include "menu.h"
#include "floor.h"
#include "tools.h"

Menu::Menu() {
    menuImg = newimage();
    wallImg = newimage();
    floorImg = newimage();
    heartImg = newimage();
    attackImg = newimage();
    defenceImg = newimage();
    monegBagImg = newimage();
    yelloKeyImg = newimage();
    blueKeyImg = newimage();
    redKeyImg = newimage();
    greenKeyImg = newimage();
};

int Menu::load() {
    getimage(menuImg, BIG_GLO_PNG, 5 * BIG_GRID, 71 * BIG_GRID, BIG_GRID, BIG_GRID);
    getimage(wallImg, BIG_GLO_PNG, 2 * BIG_GRID, 71 * BIG_GRID, BIG_GRID, BIG_GRID);
    getimage(floorImg, BIG_GLO_PNG, 4 * BIG_GRID, 71 * BIG_GRID, BIG_GRID, BIG_GRID);

    getimage(heartImg, GLO_PNG, 0, 59 * GRID, GRID, GRID);
    getimage(attackImg, GLO_PNG, GRID, 59 * GRID, GRID, GRID);
    getimage(defenceImg, GLO_PNG, 2 * GRID, 59 * GRID, GRID, GRID);
    getimage(monegBagImg, GLO_PNG, 3 * GRID, 59 * GRID, GRID, GRID);
    getimage(yelloKeyImg, GLO_PNG, 0, 38 * GRID, GRID, GRID);
    getimage(blueKeyImg, GLO_PNG, GRID, 38 * GRID, GRID, GRID);
    getimage(redKeyImg, GLO_PNG, 2 * GRID, 38 * GRID, GRID, GRID);
    getimage(greenKeyImg, GLO_PNG, 3 * GRID, 38 * GRID, GRID, GRID);
    return 0;
}

int Menu::update() {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 13; j++) {
            putimage(i * BIG_GRID, j * BIG_GRID, menuImg);
        }
    }
    for (int i = 4; i < 17; i++) {
        for (int j = 0; j < 13; j++) {
            putimage(i * BIG_GRID, j * BIG_GRID, wallImg);
        }
    }
    for (int i = 5; i < 16; i++) {
        for (int j = 1; j < 12; j++) {
            putimage(i * BIG_GRID, j * BIG_GRID, floorImg);
        }
    }
    for (int i = 17; i < 21; i++) {
        for (int j = 0; j < 13; j++) {
            putimage(i * BIG_GRID, j * BIG_GRID, menuImg);
        }
    }

    putimage_withalpha(NULL, heartImg, RrightBord, 72 + BIG_GRID);
    putimage_withalpha(NULL, attackImg, RrightBord, 72 + 2 * BIG_GRID);
    putimage_withalpha(NULL, defenceImg, RrightBord, 72 + 3 * BIG_GRID);
    putimage_withalpha(NULL, monegBagImg, RrightBord, 72 + 4 * BIG_GRID);

    putimage_withalpha(NULL, yelloKeyImg, SCREEN_WIDTH - RrightBord - Rwidth, 60 + BIG_GRID);
    putimage_withalpha(NULL, blueKeyImg, SCREEN_WIDTH - RrightBord - Rwidth, 60 + 2 * BIG_GRID);
    putimage_withalpha(NULL, redKeyImg, SCREEN_WIDTH - RrightBord - Rwidth, 60 + 3 * BIG_GRID);
    putimage_withalpha(NULL, greenKeyImg, SCREEN_WIDTH - RrightBord - Rwidth, 60 + 4 * BIG_GRID);

    fillroundrect(RrightBord, 72, RrightBord + Rwidth, 100, 5, 5);
    fillroundrect(RrightBord + BIG_GRID, 72 + BIG_GRID + 5, RrightBord + Rwidth, 72 + BIG_GRID + 5 + Rheight, 5, 5);
    fillroundrect(RrightBord + BIG_GRID, 72 + 2 * BIG_GRID + 5, RrightBord + Rwidth, 72 + 2 * BIG_GRID + 5 + Rheight, 5, 5);
    fillroundrect(RrightBord + BIG_GRID, 72 + 3 * BIG_GRID + 5, RrightBord + Rwidth, 72 + 3 * BIG_GRID + 5 + Rheight, 5, 5);
    fillroundrect(RrightBord + BIG_GRID, 72 + 4 * BIG_GRID + 5, RrightBord + Rwidth, 72 + 4 * BIG_GRID + 5 + Rheight, 5, 5);
    fillroundrect(RrightBord, 72 + 5 * BIG_GRID + 10, RrightBord + Rwidth, 72 + 5 * BIG_GRID + 10 + 5 * BIG_GRID, 5, 5);

    fillroundrect(SCREEN_WIDTH - RrightBord - Rwidth + BIG_GRID, 60 + BIG_GRID + 5, SCREEN_WIDTH - RrightBord, 60 + BIG_GRID + 5 + Rheight, 5, 5);
    fillroundrect(SCREEN_WIDTH - RrightBord - Rwidth + BIG_GRID, 60 + 2 * BIG_GRID + 5, SCREEN_WIDTH - RrightBord, 60 + 2 * BIG_GRID + 5 + Rheight, 5, 5);
    fillroundrect(SCREEN_WIDTH - RrightBord - Rwidth + BIG_GRID, 60 + 3 * BIG_GRID + 5, SCREEN_WIDTH - RrightBord, 60 + 3 * BIG_GRID + 5 + Rheight, 5, 5);
    fillroundrect(SCREEN_WIDTH - RrightBord - Rwidth + BIG_GRID, 60 + 4 * BIG_GRID + 5, SCREEN_WIDTH - RrightBord, 60 + 4 * BIG_GRID + 5 + Rheight, 5, 5);

    xyprintf(RrightBord + 5, 73, "floor: %5d", Level);
    xyprintf(RrightBord + 5, 72 + BIG_GRID + 6, "%12d", Health);
    xyprintf(RrightBord + 5, 72 + 2 * BIG_GRID + 6, "%12d", Attack);
    xyprintf(RrightBord + 5, 72 + 3 * BIG_GRID + 6, "%12d", Defence);
    xyprintf(RrightBord + 5, 72 + 4 * BIG_GRID + 6, "%12d", Money);

    xyprintf(SCREEN_WIDTH - RrightBord - Rwidth + 5, 60 + BIG_GRID + 6, "%12d", keyGroup[0]);
    xyprintf(SCREEN_WIDTH - RrightBord - Rwidth + 5, 60 + 2 * BIG_GRID + 6, "%12d", keyGroup[1]);
    xyprintf(SCREEN_WIDTH - RrightBord - Rwidth + 5, 60 + 3 * BIG_GRID + 6, "%12d", keyGroup[2]);
    xyprintf(SCREEN_WIDTH - RrightBord - Rwidth + 5, 60 + 4 * BIG_GRID + 6, "%12d", keyGroup[3]);

    xyprintf(0, 13 * BIG_GRID, "%s", underWord);

    currentFloor->printFloor(5 * BIG_GRID, BIG_GRID);
    return 0;
}

Menu menu;
