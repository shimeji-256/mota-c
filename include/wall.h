#include "obj.h"

class Wall : public obj {
public:
    Wall();
    int react();
};

extern Wall wall;