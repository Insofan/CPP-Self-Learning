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
    int listenfd;
    //第一个族， 第二个 socket 类型, 第三个参数可以填0
    listenfd = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (listenfd < 0) {
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
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    //2. 转换成指定地址
    servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    //3.将点分十进制ip地址
    inet_aton("127.0.0.1", &servaddr.sin_addr);

    //接下来绑定

    //将套接字与地址绑定， 地址长度, 第二个参数用了强制转换
    //重新启动时， 因为要绑定地址， 但是此时地址TIME_WAIT无法绑定， 所以启动不了
    int bindFlag = bind(listenfd, (struct sockaddr *) &servaddr, sizeof(servaddr));
    if (bindFlag < 0) {
        ERR_EXIT("bind");
    }


    //转换成监听状态, 一旦调用这个函数后变为被动套接字， 否则默认为主动套接字， 主动套接字是发起链接 connect， 被动套接字使用接受链接 accpet

    if (listen(listenfd, SOMAXCONN) < 0) {
        ERR_EXIT("listen");
    }

    struct sockaddr_in peeraddr;
    socklen_t peerlen = sizeof(peeraddr);

    int conn = accept(listenfd, (struct sockaddr *) &peeraddr, &peerlen);

    if (conn < 0) {
        ERR_EXIT("accept");
    }
    //网络字节序转换成点分制，
    printf("ip = %s port = %d\n", inet_ntoa(peeraddr.sin_addr), ntohs(peeraddr.sin_port));

    //变为主动套字
    char recvbuf[1024];
    while (1) {
        //memset : 将s所指向的某一块内存中的每个字节的内容全部设置为ch指定的ASCII值,
        memset(recvbuf, 0, sizeof(recvbuf));
        int ret = read(conn, recvbuf, sizeof(recvbuf));
        fputs(recvbuf, stdout);
        write(conn, recvbuf, ret);
    }

    close(conn);
    close(listenfd);

    return 0;
}