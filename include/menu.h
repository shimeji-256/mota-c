#pragma once
#include <graphics.h>

class Menu {
    private:
        PIMAGE menuImg;
        PIMAGE wallImg;
        PIMAGE floorImg;
        PIMAGE heartImg;
        PIMAGE attackImg;
        PIMAGE defenceImg;
        PIMAGE monegBagImg;
        PIMAGE yelloKeyImg;
        PIMAGE blueKeyImg;
        PIMAGE redKeyImg;
        PIMAGE greenKeyImg;
    public:
        int load();
        int update();
        Menu();
};

extern Menu menu;