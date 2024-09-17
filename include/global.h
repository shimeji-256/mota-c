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
#define REC 11

#define minFloor 0

extern PIMAGE GLO_PNG; //整体图像资源
extern PIMAGE BIG_GLO_PNG;  //整体图像资源放大
extern PIMAGE UPSTAIR_PNG;  //上楼梯图片
extern PIMAGE DOWNSTAIR_PNG;//下楼梯图片
extern PIMAGE WALL_PNG; //墙的图像
extern PIMAGE SPACE_PNG; //空图像
extern PIMAGE YELLOW_KEY_PNG; //黄钥匙图像
extern PIMAGE BLUE_KEY_PNG;  //蓝钥匙图像
extern PIMAGE RED_KEY_PNG; //红钥匙图像
extern PIMAGE GREEN_KEY_PNG; //绿钥匙图像
extern PIMAGE BLOOD_BOTTLE_PNG_A; //小血瓶图像
extern PIMAGE BLOOD_BOTTLE_PNG_B; //大血瓶图像
extern PIMAGE ATTACK_JEW_PNG; //攻击宝石图像
extern PIMAGE DEFENCE_JEW_PNG; //防御宝石图像
extern PIMAGE YELLOW_DOOR_PNG; //黄门图像
extern PIMAGE BLUE_DOOR_PNG; //蓝门图像
extern PIMAGE RED_DOOR_PNG; //红门图像
extern PIMAGE GREEN_DOOR_PNG; //绿门图像
extern PIMAGE BOOM_PNG; //爆炸图像
extern PIMAGE UpAndDownStairer_PNG;
extern std::vector<std::vector<PIMAGE>> MONSTER_GROUP_PNG; //各种怪物图像
extern std::vector<std::vector<PIMAGE>> PLAYER_GROUP_PNG; //玩家各个方向的图像
extern std::vector<std::vector<PIMAGE>> DOOR_DEATH_PNG; //开门图像
extern std::vector<PIMAGE> SWORD_GROUP_PNG; //各种剑的图像
extern std::vector<PIMAGE> SHIELD_GROUP_PNG; //各种盾的图像
extern std::vector<PIMAGE>* CUR_PLAYER_ROW; //当前玩家朝向
extern std::vector<PIMAGE> BOSS_PNG;
extern int CUR_PLAYER_PNG_ID; //当前玩家动作

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
extern bool HaveConveriation;
extern char converation[200];

void printfUnder(const char* src);

#endif