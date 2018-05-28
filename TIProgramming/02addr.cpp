//
// Created by Haixiao Xu on 2018/5/28.
//
#include <stdio.h>
#include <arpa/inet.h>

int main(void) {
    //将点分10进制转换成32位整数， 且为网络字节序,
    unsigned long addr =  inet_addr("192.168.0.100");
    printf("addr = %ud\n", ntohl(addr));

    struct in_addr ipaddr;
    ipaddr.s_addr = addr;
    //将网络字节序，转换为点分十进制
    printf("%s\n", inet_ntoa(ipaddr));
    return 0;
}
