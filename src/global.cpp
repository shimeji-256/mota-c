#include <graphics.h>
#include <string.h>
#include <vector>

#include "global.h"

PIMAGE GLO_PNG = NULL;
PIMAGE BIG_GLO_PNG = NULL;
PIMAGE WALL_PNG = NULL;
PIMAGE SPACE_PNG = NULL;
PIMAGE PLAYER_PNG = NULL;
PIMAGE UPSTAIR_PNG = NULL;
PIMAGE DOWNSTAIR_PNG = NULL;
PIMAGE YELLOW_KEY_PNG = NULL;
PIMAGE BLUE_KEY_PNG = NULL;
PIMAGE RED_KEY_PNG = NULL;
PIMAGE GREEN_KEY_PNG = NULL;
PIMAGE BLOOD_BOTTLE_PNG_A = NULL;
PIMAGE BLOOD_BOTTLE_PNG_B = NULL;
PIMAGE ATTACK_JEW_PNG = NULL;
PIMAGE DEFENCE_JEW_PNG = NULL;
PIMAGE YELLOW_DOOR_PNG = NULL;
PIMAGE BLUE_DOOR_PNG = NULL;
PIMAGE RED_DOOR_PNG = NULL;
PIMAGE GREEN_DOOR_PNG = NULL;
std::vector<std::vector<PIMAGE>> MONSTER_GROUP_PNG;

int Health = 100;
int Attack = 5;
int Defence = 2;
int Money = 0;
int Level = 0;
int keyGroup[4] = {};
char underWord[100] = "reset success";

int X = 0;
int Y = 0;
int Dx = 0;
int Dy = 0;

void printfUnder(const char* src) {
    memcpy(underWord, src, 100);
}