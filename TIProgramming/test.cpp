//
// Created by Haixiao Xu on 2018/5/28.
//
#include <stdio.h>

int main(void) {
    unsigned int x = 0x12345678;
    unsigned char *p = (unsigned char *) &x;
    printf("%0x %0x %0x %0x\n", p[0], p[1], p[2], p[3]);
    //输出78 56 34 12， 为小端字节序, 低地址存放78 高地址存放12 小端（内存地址从左往右增大）
    return 0;
}
