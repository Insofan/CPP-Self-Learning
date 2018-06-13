//
// Created by Insomnia on 2018/6/6.
//

#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <cstdlib>
#include <cstring>
#include <arpa/inet.h>
#include <zconf.h>

#define ERR_EXIT(m) \
        do \
        {\
            perror(m);\
            exit(EXIT_FAILURE);\
        }while(0)

void handler(int sig)
{
    printf("recv a sig=%d\n", sig);
    exit(EXIT_SUCCESS);
}
int main() {
    //协议族， sock 类型， 可选参数（可以填0）
    int listenfd = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (listenfd < 0) {
        ERR_EXIT("socket");
    }

    struct sockaddr_in servaddr;
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(6666);
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);

    int on = 1;
    if (setsockopt(listenfd, SOL_SOCKET, SO_REUSEADDR, &on, sizeof(on)) < 0) {
        ERR_EXIT("setsockopt");
    }
    int bindFlag = bind(listenfd, (struct sockaddr *) &servaddr, sizeof(servaddr));
    if (bindFlag < 0) {
        ERR_EXIT("bind");
    }
    //监听的socket ， 第二个参数是监听的队列数量， 选最大
    if (listen(listenfd, SOMAXCONN) < 0) {
        ERR_EXIT("listen");
    }

    struct sockaddr_in peeraddr;
    socklen_t peerlen = sizeof(peeraddr);

    int conn;
    if ((conn = accept(listenfd, (struct sockaddr *) &peeraddr, &peerlen)) < 0) {
        ERR_EXIT("accept");
    }

    printf("ip = %s port = %d\n", inet_ntoa(peeraddr.sin_addr), ntohs(peeraddr.sin_port));

    pid_t pid;
    pid = fork();
    if (pid == -1) {
        ERR_EXIT("fork");
    }
    //两个进程
    if (pid == 0) {
        signal(SIGUSR1, handler);
        char sendbuf[1024] = {0};
        while (fgets(sendbuf, sizeof(sendbuf), stdin) != NULL) {
            write(conn, sendbuf, strlen(sendbuf));
            memset(sendbuf, 0, sizeof(sendbuf));
        }
        printf("child close\n");
        exit(EXIT_SUCCESS);
    } else {
        //获取数据
        char recvbuf[1024];
        while (1) {
            memset(recvbuf, 0, sizeof(recvbuf));
            int ret = read(conn, recvbuf, sizeof(recvbuf));
            if (ret == -1) {
                ERR_EXIT("read");
            } else if (ret == 0) {
                printf("peer close\n");
                break;
            }
            fputs(recvbuf, stdout);

        }
        exit(EXIT_SUCCESS);
    }

    return 0;
}