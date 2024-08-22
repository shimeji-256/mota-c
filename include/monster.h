#include <graphics.h>

#include "obj.h"

class monster : public obj{
private:
    int heart, attack, defence, money;
public:
    monster();
    int react();
};

extern monster monst;