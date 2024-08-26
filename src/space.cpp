#include "space.h"
#include "global.h"
#include "tools.h"

Space::Space() {
    cat = 0;
}

int Space::getCat() {
    return cat;
}

int Space::putSelfImg(int x, int y) {
    putimage_withalpha(NULL, *im, x, y);
    return 0;
}

int Space::getSelfImg(PIMAGE* SOURCE) {
    im = SOURCE;
    return 0;
}

Space* Space::death() {
    return &sp;
}

// int Space::getSelfImg(int x, int y, int h) {
//     PIMAGE tmp;
//     getComic(&tmp, x, y, h);
//     im = &tmp;
//     return 0;
// }

int Space::react() {
    printfUnder("");
    return 0;
}

Monster_Death::Monster_Death() {
    im = &BOOM_PNG;
    time = 0;
    cat = 0;
}

int Monster_Death::putSelfImg(int x, int y) {
    if (time < 50) {
        putimage_withalpha(NULL, *im, x, y);
        time++;
        return 0;
    }
    return 1;
}

Door_Death::Door_Death(int wallCat) {
    com = &DOOR_DEATH_PNG[wallCat];
    time = 0;
    select = 0;
    cat = 0;
}

int Door_Death::putSelfImg(int x, int y) {
    if (select < (*com).size()){
        time++;
        putimage_withalpha(NULL, (*com)[select], x, y);
        if (time > 15) {
            select++;
            time = 0;
        }
        return 0;
    }
    return 1;
}

Space sp;