#include "obj.h"
#include "tools.h"

int obj::getCat(){
    return cat;
}

int obj::putSelfImg(int x, int y){
    putimage_withalpha(NULL, *im, x, y);
    return 0;
}

int obj::getSelfImg(PIMAGE * SOURCE){
    im = SOURCE;
    return 0;
}

space::space(){
    cat = 0;
}

int space::react(){
    return 0;
}

// int space::putSelfImg(int x, int y){
//     return 0;
// }

space sp;