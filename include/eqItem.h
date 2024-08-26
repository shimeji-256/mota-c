#ifndef _EQITEM_H_
#define _EQITEM_H_

#include "space.h"

enum keyDef {
    yellowKey,
    blueKey,
    redKey,
    greenKey
};

class Key :public Space {
private:
    int keyCat;
public:
    int react();
    Key(int keyCat);
};

extern Key keys[4];

class BloodBottle : public Space {
private:
    int addHealth;
public:
    int react();
    BloodBottle(int add);
};

extern BloodBottle bloodBottles[2];

class AttackJew : public Space {
public:
    int react();
    AttackJew();
};

extern AttackJew attackJew;

class DefenceJew : public Space {
public:
    int react();
    DefenceJew();
};

extern DefenceJew defenceJew;

class Sword: public Space{
    private:
    char name[20];
    int defence;
    public:
    int react();
    Sword(int defen);
};

#endif