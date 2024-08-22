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
    public:
        int load();
        int update();
        Menu();
};

extern Menu menu;