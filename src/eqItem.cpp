#include "eqItem.h"
#include "global.h"
#include "floor.h"

Key::Key(int keyCat) {
    transparent = 0;
    this->keyCat = keyCat;
}

int Key::react() {
    keyGroup[keyCat]++;
    printfUnder("get key");
    return 1;
}

Key keys[4] = { Key(0), Key(1), Key(2), Key(3) };

BloodBottle::BloodBottle(int add) {
    addHealth = add;
}

int BloodBottle::react() {
    Health += addHealth;
    sprintf(underWord, "Health add %d", addHealth);
    return 1;
}

BloodBottle bloodBottles[2] = { BloodBottle(50), BloodBottle(200) };

AttackJew::AttackJew() {
    transparent = 0;
    im = &ATTACK_JEW_PNG;
}

int AttackJew::react() {
    Attack++;
    printfUnder("get AttackJew, Attack add 1");
    return 1;
}

AttackJew attackJew;

DefenceJew::DefenceJew() {
    transparent = 0;
    im = &DEFENCE_JEW_PNG;
}

int DefenceJew::react() {
    Defence++;
    printfUnder("get DefenceJew, Defence add 1");
    return 1;
}

DefenceJew defenceJew;

Sword::Sword(int swordCat, const char* na, int attack) {
    transparent = 0;
    strcpy(name, na);
    this->attack = attack;
    this->swordCat = swordCat;
}

int Sword::getSwordCat() {
    return swordCat;
}

int Sword::react() {
    sprintf(underWord, "get %s, Attack %d", name, attack);
    if (equipingSword == NULL) {
        equipingSword = &swordGroup[swordCat];
        Attack += attack;
    } else if (this->swordCat > equipingSword->getSwordCat()) {
        Attack -= equipingSword->getAtk();
        Attack += attack;
        equipingSword = &swordGroup[swordCat];
    }
    return 1;
}

int Sword::getAtk() {
    return attack;
}

char* Sword::getName() {
    return name;
}

Sword swordGroup[6] = { Sword(0, "stone sword", 5), Sword(1, "iorn sword", 10),Sword(2, "silver sword", 20),
                        Sword(3, "warrior sword", 40),Sword(4, "sacred sword", 80),Sword(5, "dragon sword", 160) };
Sword* equipingSword = NULL;

Shield::Shield(int shieldCat, const char* na, int defen) {
    transparent = 0;
    strcpy(name, na);
    this->defence = defen;
    this->shieldCat = shieldCat;
    im = &SHIELD_GROUP_PNG[shieldCat];
}

int Shield::getShieldCat() {
    return shieldCat;
}

int Shield::react() {
    sprintf(underWord, "get %s, Defence %d", name, defence);
    if (equipingShield == NULL) {
        Defence += defence;
        equipingShield = &shieldGroup[shieldCat];
    } else if (this->shieldCat > equipingShield->getShieldCat()) {
        Defence -= equipingShield->getDef();
        Defence += defence;
        equipingShield = &shieldGroup[shieldCat];
    }
    return 1;
}

int Shield::getDef() {
    return defence;
}

char* Shield::getName() {
    return name;
}

Shield shieldGroup[6] = { Shield(0, "stone shield", 5), Shield(1, "iorn shield", 10),Shield(2, "silver shield", 20),
                        Shield(3, "warrior shield", 40),Shield(4, "sacred shield", 80),Shield(5, "dragon shield", 160) };
Shield* equipingShield = NULL;

int UpAndDownStairer::react() {
    inHand = 1;
    return 1;
}

int UpAndDownStairer::abandon() {
    inHand = 0;
    return 0;
}

int UpAndDownStairer::jump(int i) {
    if (inHand) {
        doStairs(i);
        return 0;
    }
    return 0;
}

UpAndDownStairer::UpAndDownStairer() {
    transparent = 0;
    inHand = 0;
    im = &UpAndDownStairer_PNG;
}

UpAndDownStairer Up_And_Down_Stairer;
