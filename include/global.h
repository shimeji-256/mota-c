#ifndef _GLOBAL_H_
#define _GLOBAL_H_

#include <graphics.h>

// #define SPACE 0
// #define WALL 1
// #define DOOR 2
// #define UPSTARE 3
// #define DOWNSTARE 4
// #define CARACTER 5
// #define WEAPHON 6
// #define MONSTER 7

#define GRID 32
#define BIG_GRID 48

#define fps 60
#define RrightBord 24
#define Rwidth 144
#define Rheight 28

extern PIMAGE GLO_PNG;
extern PIMAGE BIG_GLO_PNG;
extern PIMAGE SLIME_PNG;
extern PIMAGE WALL_PNG;
extern PIMAGE SPACE_PNG;
extern PIMAGE PLAYER_PNG;

extern int Health;
extern int Attack;
extern int Defence;
extern int Money;
extern int level;
extern int redKey;
extern int yelloKey;
extern int blueKey;
extern int greenKey;
extern char underWord[100];

#endif