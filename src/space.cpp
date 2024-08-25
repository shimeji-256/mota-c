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

Space sp;