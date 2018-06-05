//
// Created by Haixiao Xu on 2018/5/31.
//

#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define ERR_EXIT(m) \
        do \
        {\
            perror(m);\
            exit(EXIT_FAILURE);\
        }while(0)

int main(void) {
    int sock;
    //第一个族， 第二个 socket 类型, 第三个参数可以填0
    sock= socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (sock< 0) {
        ERR_EXIT("socket");
    }

    struct sockaddr_in servaddr;
    memset(&servaddr, 0, sizeof(servaddr));
    //地址 家族
    servaddr.sin_family = AF_INET;
    //转换成网络字节序 ， s表示两个字节
    servaddr.sin_port = htons(8888);
    //1. 绑定本机任意地址, 转换字节序， 其中INADDR_ANY是0， 无论怎么转换都是0， 所以可以去掉htonl
    /*servaddr.sin_addr.s_addr = htonl(INADDR_ANY); */
//    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    //2. 转换成指定地址
    //链接服务器端地址 不能htonl，因为客户端和服务器端 不是安装在同一台机器上， 应该指定服务器地址
    servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    //3.将点分十进制ip地址
    inet_aton("127.0.0.1", &servaddr.sin_addr);


    if (connect(sock, (struct sockaddr*)&servaddr, sizeof(servaddr)) < 0) {
        ERR_EXIT("connect");
    };

    char sendbuf[1024] = {0};

    char recvbuf[1024] = {0};
    //变为主动套字
    while (fgets(sendbuf, sizeof(sendbuf), stdin) != NULL) {
       write(sock, sendbuf, strlen(sendbuf));
       read(sock, recvbuf, sizeof(recvbuf));
       fputs(recvbuf, stdout);
       //memset是计算机中C/C++语言函数。将s所指向的某一块内存中的后n个 字节的内容全部设置为ch指定的ASCII值， 第一个值为指定的内存地址，块的大小由第三个参数指定，这个函数通常为新申请的内存做初始化工作， 其返回值为s。
       memset(sendbuf,0, sizeof(sendbuf));
       memset(recvbuf, 0, sizeof(recvbuf));
    }

    close(sock);


    return 0;
}