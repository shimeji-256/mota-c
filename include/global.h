#ifndef _GLOBAL_H_
#define _GLOBAL_H_

#include <graphics.h>
#include <vector>

#define GRID 32
#define BIG_GRID 48

#define fps 60
#define SCREEN_WIDTH 1008
#define SCREEN_HEIGHT 650
#define RrightBord 24
#define Rwidth 144
#define Rheight 28
#define monsterNum 40
#define playerPngNum 4
#define doorNum 4

#define minFloor 0

extern PIMAGE GLO_PNG;
extern PIMAGE BIG_GLO_PNG;
extern PIMAGE UPSTAIR_PNG;
extern PIMAGE DOWNSTAIR_PNG;
extern PIMAGE WALL_PNG;
extern PIMAGE SPACE_PNG;
extern PIMAGE YELLOW_KEY_PNG;
extern PIMAGE BLUE_KEY_PNG;
extern PIMAGE RED_KEY_PNG;
extern PIMAGE GREEN_KEY_PNG;
extern PIMAGE BLOOD_BOTTLE_PNG_A;
extern PIMAGE BLOOD_BOTTLE_PNG_B;
extern PIMAGE ATTACK_JEW_PNG;
extern PIMAGE DEFENCE_JEW_PNG;
extern PIMAGE YELLOW_DOOR_PNG;
extern PIMAGE BLUE_DOOR_PNG;
extern PIMAGE RED_DOOR_PNG;
extern PIMAGE GREEN_DOOR_PNG;
extern PIMAGE BOOM_PNG;
extern std::vector<std::vector<PIMAGE>> MONSTER_GROUP_PNG;
extern std::vector<std::vector<PIMAGE>> PLAYER_GROUP_PNG;
extern std::vector<std::vector<PIMAGE>> DOOR_DEATH_PNG;
extern std::vector<PIMAGE> *CUR_PLAYER_ROW;
extern int CUR_PLAYER_PNG_ID;

extern int Health;
extern int Attack;
extern int Defence;
extern int Money;
extern int Level;
extern int keyGroup[4];
extern int X;
extern int Y;
extern int Dx;
extern int Dy;
extern int TIME;
extern char underWord[100];

void printfUnder(const char *src);

#endif