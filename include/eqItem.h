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

class Sword : public Space {
private:
    int swordCat;
    char name[20];
    int attack;
public:
    int react();
    int getAtk();
    char* getName();
    Sword(int swordCat, const char* na, int attack);
    int getSwordCat();
};

extern Sword swordGroup[6];
extern Sword* equipingSword;

class Shield : public Space {
private:
    int shieldCat;
    char name[20];
    int defence;
public:
    int react();
    int getDef();
    char* getName();
    Shield(int shieldCat, const char* na, int defen);
    int getShieldCat();
};

extern Shield shieldGroup[6];
extern Shield* equipingShield;

class UpAndDownStairer : public Space {
private:
    bool inHand;
public:
    int react();
    int abandon();
    int jump(int i);
    UpAndDownStairer();
};

extern UpAndDownStairer Up_And_Down_Stairer;

#endif