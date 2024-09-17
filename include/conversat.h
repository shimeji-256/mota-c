#ifndef _CONVERSAT_H_
#define _CONVERSAT_H_

#include <graphics.h>

class Conversat {
private:
    int dx, dy;
    char text[200];
public:
    Conversat();
    Conversat(int xpos, int ypos, const char* textp);
    virtual int show(int x, int y);
};

class DeathConversat : public Conversat {
public:
    int show(int x, int y);
    DeathConversat();
};

class WinConversat : public Conversat {
public:
    int show(int x, int y);
    WinConversat();
};

extern DeathConversat death;

extern Conversat* curConversat;

extern WinConversat winC;

#endif