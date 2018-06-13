//
// Created by Insomnia on 2018/6/11.
//

#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <cstdlib>
#include <string.h>
#include <netinet/in.h>
//#include <unistd.h>
#include <sys/types.h>
#include <zconf.h>

#define ERR_EXIT(m) \
        do \
        {\
            perror(m);\
            exit(EXIT_FAILURE);\
        }while(0)

void doService(int conn) {
    char recvBuf[1024];
    while (1) {
        memset(recvBuf, 0, sizeof(recvBuf));

        int ret = read(conn, recvBuf, sizeof(recvBuf));

        if (ret == 0) {
            printf("client close \n");
            break;
        } else if (ret == -1) {
            ERR_EXIT("read");
        }

        fputs(recvBuf, stdout);
        write(conn, &recvBuf, sizeof(recvBuf));
    }
}

int main() {
    int listenFd = socket(AF_INET, SOCK_STREAM, 0);

    if (listenFd < 0) {
        ERR_EXIT("listenFd");
    }

    struct sockaddr_in servaddr;
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(6666);
    servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");

    int on = 1;
    int option = setsockopt(listenFd, SOL_SOCKET, SO_REUSEADDR, &on, sizeof(on));
    if (option < 0) {
        ERR_EXIT("socket option");
    }

    int bindRes = bind(listenFd, (struct sockaddr *) &servaddr, sizeof(servaddr));

    if (bindRes < 0) {
        ERR_EXIT("bind");
    }
    int listenRes = listen(listenFd, SOMAXCONN);

    struct sockaddr_in peeraddr;
    socklen_t peerlen = sizeof(peeraddr);

    int conn;
    pid_t pid;

    printf("Start serv \n");
    while (1) {
        conn = accept(listenFd, (struct sockaddr *) &peeraddr, &peerlen);
        if (conn < 0) {
            ERR_EXIT("accept");
        }


        printf("ip %s port %d", inet_ntoa(peeraddr.sin_addr), ntohs(peeraddr.sin_port));

        pid = fork();

        if (pid == -1) {
            ERR_EXIT("fork");
        }

        if (pid == 0) {
            close(listenFd);
            doService(listenFd);
        } else {
            close(conn);
        }

    }


    return 0;
}
