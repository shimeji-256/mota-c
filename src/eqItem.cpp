#include "eqItem.h"
#include "global.h"

Key::Key(int keyCat) {
    cat = 3;
    this->keyCat = keyCat;
}

int Key::react() {
    keyGroup[keyCat]++;
    return 1;
}

Key keys[4] = { Key(0), Key(1), Key(2), Key(3) };

BloodBottle::BloodBottle(int add) {
    addHealth = add;
}

int BloodBottle::react() {
    Health += addHealth;
    return 1;
}

BloodBottle bloodBottles[2] = { BloodBottle(50), BloodBottle(200) };

AttackJew::AttackJew(){
    cat = 3;
}

int AttackJew::react(){
    Attack++;
    return 1;
}

AttackJew attackJew;

DefenceJew::DefenceJew(){
    cat = 3;
}

int DefenceJew::react(){
    Defence++;
    return 1;
}

DefenceJew defenceJew;