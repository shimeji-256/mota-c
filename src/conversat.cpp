#include <string.h>
#include "tools.h"
#include "conversat.h"

Conversat::Conversat() {
}

Conversat::Conversat(int xpos, int ypos, const char* textp) {
    dx = xpos;
    dy = ypos;
    strcpy(text, textp);
}

int Conversat::show(int x, int y) {
    bar(x, y, x + dx, y + dy);
    rectprintf(x, y, dx, dy, "%s", text);
    getch();
    curConversat = NULL;
    return 0;
}



Conversat* curConversat = NULL;

int DeathConversat::show(int x, int y) {
    setfillcolor(RED);
    // setcolor(WHITE);
    bar(x, y, x + 432, y + 240);
    rectprintf(x, y, 432, 240, "You are died\n\nPress Any Key To Restart");
    getch();
    initAttribute();
    return 0;
}

DeathConversat::DeathConversat() {};

DeathConversat death;

WinConversat::WinConversat() {};

int WinConversat::show(int x, int y) {
    setfillcolor(GREEN);
    bar(x, y, x + 432, y + 240);
    rectprintf(x, y, 432, 240, "Congratulations\nYou have defeated the Demon Lord and stopped the corruption of the Tower\n\nPress Any Key To Exit The Game");
    getch();
    exit(0);
    return 0;
}

WinConversat winC;
