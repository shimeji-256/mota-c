#include <cstdio>

#include "monster.h"
#include "global.h"

monster::monster() {
    cat = 3;
    heart = 35;
    attack = 18;
    defence = 1;
    money = 1;
}

int monster::react() {
    int enemyHurt = ((attack - Defence) > 0 ? (attack - Defence): 0);
    int myHurt = ((Attack - defence) > 0 ? (Attack - defence): 0);
    int tmpMonsterHeart = heart;
    while (tmpMonsterHeart > 0 && Health > 0) {
        tmpMonsterHeart -= enemyHurt;
        Health -= myHurt;   
    }
    
    if(tmpMonsterHeart > 0)
        return -1;
    
    Money += money;
    sprintf(underWord, "get %d coin", money);
    return 1;
}

monster monst;