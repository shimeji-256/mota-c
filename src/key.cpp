#include "key.h"
#include "global.h"

Key::Key(){
    cat = 3;
}

int Key::react(){
    keyGroup[keyCat]++;
    return 1;
}