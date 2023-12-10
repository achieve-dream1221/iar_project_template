#include <ioCC2530.h>
#include "iar_8051_compiler_defines.h"
#define uint unsigned int

//定义控制灯的端口
#define LED1 P1_0 //定义 LED1 为 P10 口控制
#define LED2 P1_1 //定义 LED2 为 P11 口控制
#define LED3 P0_4 //定义 LED3 为 P04 口控制


void DelayMs(uint ms) {
    // 50000 => 1000 ms
    ms = ms * 50;
    uint i;
    for (i = 0; i < ms; i++);
    for (i = 0; i < ms; i++);
    for (i = 0; i < ms; i++);
    for (i = 0; i < ms; i++);
    for (i = 0; i < ms; i++);
}


void InitIO(void) {
    P1DIR |= 0x03; //P10、P11 定义为输出, 0000 0011
    P0DIR |= 0x10; //P04 定义为输出 0001 0000
    LED1 = 1;
    LED2 = 1;
    LED3 = 1; //LED 灯初始化为关
}

int main(void) {
    InitIO(); //初始化 LED 灯控制 IO 口
    while (1) //死循环
    {
        LED1 = !LED1; // LED1 灯闪一次
        DelayMs(1000);
        LED2 = !LED2; // LED2 灯闪一次
        DelayMs(1000);
        LED3 = !LED3; // LED3 灯闪一次
        DelayMs(1000);
    }
}