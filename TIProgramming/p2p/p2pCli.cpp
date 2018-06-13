//
// Created by Insomnia on 2018/6/6.
//

#include <stdlib.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <cstdio>
#include <cstring>
#include <zconf.h>
#include <signal.h>

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
    int sock;

    sock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);

    if (sock < 0) {
        ERR_EXIT("socket");
    }

    struct sockaddr_in servaddr;
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(6666);
    servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    printf("ip = %s port = %d\n", inet_ntoa(servaddr.sin_addr), ntohs(servaddr.sin_port));


    if (connect(sock, (struct sockaddr *) &servaddr, sizeof(servaddr)) < 0) {
        ERR_EXIT("connect");
    }


    char sendbuf[1024] = {0};
    char recvbuf[1024] = {0};

    pid_t pid;
    pid = fork();
    if (pid == -1) {
        ERR_EXIT("fork");
    }

    if (pid == 0) {
        char recvbuf[1024];
        while (1) {
            memset(recvbuf, 0, sizeof(recvbuf));
            int ret = read(sock, recvbuf, sizeof(recvbuf));
            if (ret == -1) {
                ERR_EXIT("read");
            } else if (ret == 0) {
                printf("peer close\n");
                break;
            }
            fputs(recvbuf, stdout);
        }
        printf("child close\n");
        kill(pid, SIGUSR2);
        exit(EXIT_SUCCESS);
    } else {
        signal(SIGUSR2, handler);
        char sendbuf[1024] = {0};
        while (fgets(sendbuf, sizeof(sendbuf), stdin) != NULL) {
            write(sock, sendbuf, strlen(sendbuf));
            //memset是计算机中C/C++语言函数。将s所指向的某一块内存中的后n个 字节的内容全部设置为ch指定的ASCII值， 第一个值为指定的内存地址，块的大小由第三个参数指定，这个函数通常为新申请的内存做初始化工作， 其返回值为s。
            memset(sendbuf, 0, sizeof(sendbuf));
        }
        printf("parent close\n");
        close(sock);
        exit(EXIT_SUCCESS);
    }


    return 0;
}