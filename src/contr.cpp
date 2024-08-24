#include <graphics.h>
#include <cstdio>

#include "contr.h"
#include "tools.h"
#include "global.h"
// #include "keymsg.h"

void positionOffset(int key);

bool keyIsPressed[256] = { false };

int Contr::update() {
    if (Level != tf->getLevel()) {
        tf->toFloor();
    } else {
        while (kbmsg()) {
            key_msg msg = getkey();
            if (msg.msg == key_msg_down) {
                // 按键按下
                if (!keyIsPressed[msg.key]) {
                    positionOffset(msg.key);
                }

                //按键按下，记录按键已变为按下状态
                keyIsPressed[msg.key] = true;

            } else if (msg.msg == key_msg_up) {
                // 按键抬起，记录按键已变为松开状态
                keyIsPressed[msg.key] = false;
            }
        }
    }
    return 0;
}

void positionOffset(int key) {
    Dx = Dy = 0;
    switch (key) {
    case 'A': case key_left:	Dx = -1;	break;	//左移
    case 'W': case key_up:		Dy = -1;	break;	//上移
    case 'D': case key_right:	Dx = 1;	break;	//右移
    case 'S': case key_down:	Dy = 1;	break;	//下移
    default:  break;	//其他键不移动
    }
    tf->moveAndRea();
}

Contr contr;