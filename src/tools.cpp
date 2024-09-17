#include <graphics.h>
#include <vector>
#include <cstdio>

#include "global.h"
#include "menu.h"
#include "tools.h"
#include "structBlock.h"
#include "monster.h"
#include "floor.h"
#include "eqItem.h"
#include "npc.h"

void getComic(PIMAGE* DST, int x, int y, int h) {
    *DST = newimage();
    getimage(*DST, BIG_GLO_PNG, x * BIG_GRID, y * BIG_GRID, h * BIG_GRID, h * BIG_GRID);
}

int getCo(std::vector<PIMAGE>* K, int x, int y, int h, bool vet, int num) {
    (*K).resize(num);
    if (vet) {
        for (int i = 0; i < num; i++) {
            (*K)[i] = newimage();
            getComic(&(*K)[i], x + i * h, y, h);
        }
    } else {
        for (int i = 0; i < num; i++) {
            (*K)[i] = newimage();
            getComic(&(*K)[i], x, i * h + y, h);
        }
    }
    return 0;
}


/*
    图片素材的加载，并赋值给各个图像指针
*/
int initImg() {
    GLO_PNG = newimage();
    int p = getimage(GLO_PNG, "PNG", "IMAGE_PNG_GLO");
    BIG_GLO_PNG = newimage((int)(1.5 * getwidth(GLO_PNG)), (int)(1.5 * getheight(GLO_PNG)));
    putimage(BIG_GLO_PNG, 0, 0, (int)(1.5 * getwidth(GLO_PNG)), (int)(1.5 * getheight(GLO_PNG)), GLO_PNG, 0, 0, getwidth(GLO_PNG), getheight(GLO_PNG));
    getComic(&WALL_PNG, 0, 65, 1);
    getComic(&SPACE_PNG, 0, 0, 1);
    getComic(&BOOM_PNG, 0, 63, 1);
    getComic(&DOWNSTAIR_PNG, 0, 61, 1);
    getComic(&UPSTAIR_PNG, 1, 61, 1);
    getComic(&YELLOW_KEY_PNG, 0, 38, 1);
    getComic(&BLUE_KEY_PNG, 1, 38, 1);
    getComic(&RED_KEY_PNG, 2, 38, 1);
    getComic(&GREEN_KEY_PNG, 3, 38, 1);
    getComic(&UpAndDownStairer_PNG, 2, 40, 1);
    getComic(&BLOOD_BOTTLE_PNG_A, 0, 37, 1);
    getComic(&BLOOD_BOTTLE_PNG_B, 1, 37, 1);
    getComic(&ATTACK_JEW_PNG, 0, 36, 1);
    getComic(&DEFENCE_JEW_PNG, 1, 36, 1);
    getComic(&YELLOW_DOOR_PNG, 0, 73, 1);
    getComic(&BLUE_DOOR_PNG, 1, 73, 1);
    getComic(&RED_DOOR_PNG, 2, 73, 1);
    getComic(&GREEN_DOOR_PNG, 3, 73, 1);
    getCo(&SWORD_GROUP_PNG, 0, 52, 1, 0, 6);
    getCo(&SHIELD_GROUP_PNG, 1, 52, 1, 0, 6);
    sp.getSelfImg(&SPACE_PNG);
    stair[0].getSelfImg(&DOWNSTAIR_PNG);
    stair[1].getSelfImg(&UPSTAIR_PNG);
    keys[0].getSelfImg(&YELLOW_KEY_PNG);
    keys[1].getSelfImg(&BLUE_KEY_PNG);
    keys[2].getSelfImg(&RED_KEY_PNG);
    keys[3].getSelfImg(&GREEN_KEY_PNG);
    bloodBottles[0].getSelfImg(&BLOOD_BOTTLE_PNG_A);
    bloodBottles[1].getSelfImg(&BLOOD_BOTTLE_PNG_B);
    door[0].getSelfImg(&YELLOW_DOOR_PNG);
    door[1].getSelfImg(&BLUE_DOOR_PNG);
    door[2].getSelfImg(&RED_DOOR_PNG);
    door[3].getSelfImg(&GREEN_DOOR_PNG);
    npc_1.getSelfImg(0, 17, 1, 2);
    swordGroup[0].getSelfImg(&SWORD_GROUP_PNG[0]);
    swordGroup[1].getSelfImg(&SWORD_GROUP_PNG[1]);
    swordGroup[2].getSelfImg(&SWORD_GROUP_PNG[2]);
    swordGroup[3].getSelfImg(&SWORD_GROUP_PNG[3]);
    swordGroup[4].getSelfImg(&SWORD_GROUP_PNG[4]);
    swordGroup[5].getSelfImg(&SWORD_GROUP_PNG[5]);

    shieldGroup[0].getSelfImg(&SHIELD_GROUP_PNG[0]);
    shieldGroup[1].getSelfImg(&SHIELD_GROUP_PNG[1]);
    shieldGroup[2].getSelfImg(&SHIELD_GROUP_PNG[2]);
    shieldGroup[3].getSelfImg(&SHIELD_GROUP_PNG[3]);
    shieldGroup[4].getSelfImg(&SHIELD_GROUP_PNG[4]);
    shieldGroup[5].getSelfImg(&SHIELD_GROUP_PNG[5]);

    PLAYER_GROUP_PNG.resize(playerPngNum);
    getCo(&PLAYER_GROUP_PNG[0], 0, 24, 1, 1, 4);
    getCo(&PLAYER_GROUP_PNG[1], 0, 25, 1, 1, 4);
    getCo(&PLAYER_GROUP_PNG[2], 0, 26, 1, 1, 4);
    getCo(&PLAYER_GROUP_PNG[3], 0, 27, 1, 1, 4);

    DOOR_DEATH_PNG.resize(doorNum);
    getCo(&DOOR_DEATH_PNG[0], 0, 73, 1, 0, 4);
    getCo(&DOOR_DEATH_PNG[1], 1, 73, 1, 0, 4);
    getCo(&DOOR_DEATH_PNG[2], 2, 73, 1, 0, 4);
    getCo(&DOOR_DEATH_PNG[3], 3, 73, 1, 0, 4);

    MONSTER_GROUP_PNG.resize(monsterNum);
    getCo(&MONSTER_GROUP_PNG[0], 0, 1, 1, 1, 2);
    getCo(&MONSTER_GROUP_PNG[1], 2, 1, 1, 1, 2);
    getCo(&MONSTER_GROUP_PNG[2], 4, 1, 1, 1, 2);
    getCo(&MONSTER_GROUP_PNG[3], 6, 1, 1, 1, 2);
    getCo(&MONSTER_GROUP_PNG[4], 0, 2, 1, 1, 2);
    getCo(&MONSTER_GROUP_PNG[5], 2, 2, 1, 1, 2);
    getCo(&MONSTER_GROUP_PNG[6], 4, 2, 1, 1, 2);
    getCo(&MONSTER_GROUP_PNG[7], 0, 3, 1, 1, 2);
    getCo(&MONSTER_GROUP_PNG[8], 2, 3, 1, 1, 2);
    getCo(&MONSTER_GROUP_PNG[9], 4, 3, 1, 1, 2);
    getCo(&MONSTER_GROUP_PNG[10], 0, 4, 1, 1, 2);
    getCo(&MONSTER_GROUP_PNG[11], 2, 4, 1, 1, 2);
    getCo(&MONSTER_GROUP_PNG[12], 0, 5, 1, 1, 2);
    getCo(&MONSTER_GROUP_PNG[13], 2, 5, 1, 1, 2);
    getCo(&MONSTER_GROUP_PNG[14], 0, 6, 1, 1, 2);
    getCo(&MONSTER_GROUP_PNG[15], 2, 6, 1, 1, 2);
    getCo(&MONSTER_GROUP_PNG[16], 0, 7, 1, 1, 2);
    getCo(&MONSTER_GROUP_PNG[17], 2, 7, 1, 1, 2);
    getCo(&MONSTER_GROUP_PNG[18], 4, 7, 1, 1, 2);
    getCo(&MONSTER_GROUP_PNG[19], 0, 8, 1, 1, 2);
    getCo(&MONSTER_GROUP_PNG[20], 2, 8, 1, 1, 2);
    getCo(&MONSTER_GROUP_PNG[21], 0, 9, 1, 1, 2);
    getCo(&MONSTER_GROUP_PNG[22], 2, 9, 1, 1, 2);
    getCo(&MONSTER_GROUP_PNG[23], 4, 9, 1, 1, 2);
    getCo(&MONSTER_GROUP_PNG[24], 0, 10, 1, 1, 2);
    getCo(&MONSTER_GROUP_PNG[25], 2, 10, 1, 1, 2);
    getCo(&MONSTER_GROUP_PNG[26], 4, 10, 1, 1, 2);
    getCo(&MONSTER_GROUP_PNG[27], 0, 11, 1, 1, 2);
    getCo(&MONSTER_GROUP_PNG[28], 2, 11, 1, 1, 2);
    getCo(&MONSTER_GROUP_PNG[29], 4, 11, 1, 1, 2);
    getCo(&MONSTER_GROUP_PNG[30], 0, 12, 1, 1, 2);
    getCo(&MONSTER_GROUP_PNG[31], 2, 12, 1, 1, 2);
    getCo(&MONSTER_GROUP_PNG[32], 4, 12, 1, 1, 2);
    getCo(&MONSTER_GROUP_PNG[33], 0, 13, 1, 1, 2);
    getCo(&MONSTER_GROUP_PNG[34], 2, 13, 1, 1, 2);
    getCo(&MONSTER_GROUP_PNG[35], 4, 13, 1, 1, 2);

    getCo(&BOSS_PNG, 0, 29, 3, 1, 2);
    return 0;
}

/*
    怪物名字以及各属性的初始化
*/
int initMonster() {
    monsterGroup[0] = new Monster("Green Slime", 35, 18, 1, 1, &MONSTER_GROUP_PNG[0]);
    monsterGroup[1] = new Monster("Red Slime", 45, 20, 2, 1, &MONSTER_GROUP_PNG[1]);
    monsterGroup[2] = new Monster("Big Slime", 130, 60, 3, 8, &MONSTER_GROUP_PNG[2]);
    monsterGroup[3] = new Monster("Slime Man", 320, 140, 20, 30, &MONSTER_GROUP_PNG[3]);
    monsterGroup[4] = new Monster("Bat", 35, 38, 3, 3, &MONSTER_GROUP_PNG[4]);
    monsterGroup[5] = new Monster("Big Bat", 60, 100, 8, 12, &MONSTER_GROUP_PNG[5]);
    monsterGroup[6] = new Monster("Vampire Bat", 200, 390, 90, 50, &MONSTER_GROUP_PNG[6]);
    monsterGroup[7] = new Monster("Skeleton C", 50, 42, 6, 6, &MONSTER_GROUP_PNG[7]);
    monsterGroup[8] = new Monster("Skeleton B", 55, 52, 12, 8, &MONSTER_GROUP_PNG[8]);
    monsterGroup[9] = new Monster("Skeleton A", 100, 65, 15, 30, &MONSTER_GROUP_PNG[9]);
    monsterGroup[10] = new Monster("Priest", 60, 32, 8, 5, &MONSTER_GROUP_PNG[10]);
    monsterGroup[11] = new Monster("Superion Priest", 100, 95, 32, 22, &MONSTER_GROUP_PNG[11]);
    monsterGroup[12] = new Monster("Zombie", 260, 85, 5, 18, &MONSTER_GROUP_PNG[12]);
    monsterGroup[13] = new Monster("Zombie Knight", 320, 120, 15, 30, &MONSTER_GROUP_PNG[13]);
    monsterGroup[14] = new Monster("Magician B", 220, 370, 110, 80, &MONSTER_GROUP_PNG[14]);
    monsterGroup[15] = new Monster("Magician A", 200, 380, 130, 90, &MONSTER_GROUP_PNG[15]);
    monsterGroup[16] = new Monster("Gate-Keeper C", 50, 48, 22, 12, &MONSTER_GROUP_PNG[16]);
    monsterGroup[17] = new Monster("Gate-Keeper B", 100, 180, 110, 100, &MONSTER_GROUP_PNG[17]);
    monsterGroup[18] = new Monster("Gate-Keeper A", 180, 460, 360, 200, &MONSTER_GROUP_PNG[18]);
    monsterGroup[19] = new Monster("Rock", 20, 100, 68, 28, &MONSTER_GROUP_PNG[19]);
    monsterGroup[20] = new Monster("Swordsman", 100, 680, 50, 55, &MONSTER_GROUP_PNG[20]);
    monsterGroup[21] = new Monster("Solder", 210, 200, 65, 45, &MONSTER_GROUP_PNG[21]);
    monsterGroup[22] = new Monster("Knight", 160, 230, 105, 65, &MONSTER_GROUP_PNG[22]);
    monsterGroup[23] = new Monster("Ghost Solder", 220, 180, 30, 35, &MONSTER_GROUP_PNG[23]);
    monsterGroup[24] = new Monster("Green Slime", 35, 18, 1, 1, &MONSTER_GROUP_PNG[24]);
    monsterGroup[25] = new Monster("Green Slime", 35, 18, 1, 1, &MONSTER_GROUP_PNG[25]);
    monsterGroup[26] = new Monster("Green Slime", 35, 18, 1, 1, &MONSTER_GROUP_PNG[26]);
    monsterGroup[27] = new Monster("Green Slime", 35, 18, 1, 1, &MONSTER_GROUP_PNG[27]);
    monsterGroup[28] = new Monster("Green Slime", 35, 18, 1, 1, &MONSTER_GROUP_PNG[28]);
    monsterGroup[29] = new Monster("Green Slime", 35, 18, 1, 1, &MONSTER_GROUP_PNG[29]);
    monsterGroup[30] = new Monster("Green Slime", 35, 18, 1, 1, &MONSTER_GROUP_PNG[30]);
    // monsterGroup[0] = new Monster("Green Slime", 35, 18, 1, 1, &MONSTER_GROUP_PNG[0]);
    // monsterGroup[0] = new Monster("Green Slime", 35, 18, 1, 1, &MONSTER_GROUP_PNG[0]);
    bossp = new Boss("BOSS", 100, 100, 1, 1, &BOSS_PNG);
    return 0;
}
/*
    地图编辑
    其中：
    0：空地
    1：墙
    2：下楼梯
    3：上楼梯
    4：紫商店
    5：老人商店
    6：黄商店
    7-10：黄、蓝、红、绿门
    11-14：黄、蓝、红、绿钥匙
    15：小血药
    16：大血药
    17：攻击宝石
    18：防御宝石
    19：上楼器
    20：下楼器
    21：楼层跳转器
    22：稿子
    23：冰冻光线
    24-29:各种宝剑
    30-35：各种盾牌
    ...
    100+：怪物
*/
int initMap() {
    floorGroup.clear();
    floorGroup.shrink_to_fit();
    short floor_0[11][11] = { {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                            {0, 0, 0, 0, 0, 3, 0, 0, 0, 0, 0},
                            {0, 0, 0, 0, 16, 0, 16, 0, 0, 0, 0},
                            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                            {0, 0, 0, 29, 0, 0, 0, 35, 0, 0, 0},
                            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                            {0, 0, 0, 0, 16, 0, 16, 0, 0, 0, 0},
                            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0} };
    floorGroup.push_back(new Floor(0, 5, 5, 5, 5, floor_0));

    short floor_1[11][11] = { {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                            {0, 0, 0, 0, 0, 11, 0, 0, 0, 0, 0},
                            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                            {0, 0, 0, 30, 0, 0, 0, 24, 0, 0, 0},
                            {0, 0, 0, 0, 0, 70, 0, 0, 0, 0, 0},
                            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                            {0, 0, 0, 0, 0, 3, 0, 0, 0, 0, 0},
                            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0} };
    floorGroup.push_back(new Floor(1, 5, 6, 5, 6, floor_1));

    

    short floor_2[11][11] = {   {11, 11, 1, 0, 0, 0, 0, 0, 0, 0, 0},
                                {11, 11, 1, 0, 0, 0, 0, 0, 0, 0, 0},
                                {1, 7, 1, 0, 0, 0, 0, 0, 0, 0, 0},
                                {0, 100, 105, 0, 0, 0, 0, 0, 0, 0, 0},
                                {1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0},
                                {11, 17, 110, 7, 0, 0, 0, 0, 3, 0, 0},
                                {0, 18, 0, 1, 0, 0, 0, 0, 0, 0, 0},
                                {15, 0, 16, 1, 0, 0, 0, 0, 0, 0, 0},
                                {1, 1, 1, 1, 0, 2, 0, 0, 0, 0, 0},
                                {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                {0, 0, 0, 28, 0, 0, 34, 0, 0, 0, 0} };
    floorGroup.push_back(new Floor(2, 5, 9, 0, 0, floor_2));
    short floor_3[11][11] = { {3, 0, 100, 101, 100, 0 ,0, 0, 0, 0, 0},
                            {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0},
                            {15, 0, 0, 7, 0, 1, 17, 11, 0, 1, 0},
                            {0, 105, 0, 1, 0, 1, 18, 15, 0, 1, 0},
                            {1, 7, 1, 1, 0, 1, 1, 1, 7, 1, 0},
                            {11, 0, 0, 1, 0, 7, 104, 109, 104, 1, 0},
                            {0, 109, 0, 1, 0, 1, 1, 1, 1, 1, 0},
                            {1, 7, 1, 1, 0, 0, 0, 0, 0, 0, 0},
                            {0, 0, 0, 1, 1, 7, 1, 1, 1, 7, 1},
                            {15, 0, 11, 1, 11, 0, 0, 0, 0, 104, 0},
                            {15, 21, 11, 1, 0, 0, 0, 0, 100, 16, 100} };
    floorGroup.push_back(new Floor(3, 5, 10, 1, 0, floor_3));

    
    short floor_4[11][11] = { {2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                {100,102,103,104,105,106,107,108,109,110},
                            {111,112,113,114,115,116,117,118,119,120,121},
                            {122,123,124,125,126,127,128,129, 0, 0, 3} };
    floorGroup.push_back(new Floor(4, 1, 0, 0, 0, floor_4));

    short floor_boss[11][11] = {};
    floorGroup.push_back(new bossFloor(5, floor_boss));
    return 0;
}

int initAttribute() {
    setbkcolor(GRAY);
    setfillcolor(GRAY);
    Health = 100;
    Attack = 30;
    Defence = 2;
    Money = 0;
    Level = 1;
    CUR_PLAYER_ROW = &PLAYER_GROUP_PNG[0];
    CUR_PLAYER_PNG_ID = 0;
    TIME = 0;
    printfUnder("finish init");
    curConversat = NULL;

    X = 5;
    Y = 6;
    Dx = 0;
    Dy = 0;

    initMap();
    currentFloor = floorGroup[Level];
    return 0;
}

int initAll() {
    initImg();
    initMonster();
    initAttribute();
    menu.load();
    return 0;
}

int initAgain() {
    initMonster();
    initAttribute();
    return 0;
}