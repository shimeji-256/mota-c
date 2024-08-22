#include "monster.h"
#include "global.h"

monster::monster() {
    cat = 4;
    heart = 35;
    attack = 18;
    defence = 1;
    money = 1;
}

int monster::react() {
    int enemyHert = ((attack - Defence) > 0 ? (attack - Defence): 0);
    int myHert = ((Attack - defence) > 0 ? (Attack - defence): 0);
    while (heart > 0 && Health > 0) {
        heart -= enemyHert;
        Health -= myHert;   
    }
    return 0;
}

monster monst;