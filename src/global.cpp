#include <graphics.h>
#include <cstdio>
#include <string.h>

PIMAGE GLO_PNG = NULL;
PIMAGE BIG_GLO_PNG = NULL;
PIMAGE SLIME_PNG = NULL;
PIMAGE WALL_PNG = NULL;
PIMAGE SPACE_PNG = NULL;
PIMAGE PLAYER_PNG = NULL;

int Health = 100;
int Attack = 5;
int Defence = 2;
int Money = 0;
int Level = 0;
int keyGroup[4] = {};
char underWord[100] = "111";

int X = 0;
int Y = 0;
int Dx = 0;
int Dy = 0;

void printfUnder(const char *__format, ...){
    sprintf(underWord, __format);
}