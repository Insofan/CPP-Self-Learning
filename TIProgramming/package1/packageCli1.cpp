//
// Created by Insomnia on 2018/6/11.
//

#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <cstdlib>
#include <zconf.h>
#include <string.h>

#define ERR_EXIT(m) \
        do \
        {\
            perror(m);\
            exit(EXIT_FAILURE);\
        }while(0)

int main() {

    int listenFd = socket(AF_INET, SOCK_STREAM, 0);

    if (listenFd < 0) {
        ERR_EXIT("listenFd");
    }

    struct sockaddr_in servaddr;
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    servaddr.sin_port = htons(6666);

    int conn = connect(listenFd, (struct sockaddr *) &servaddr, sizeof(servaddr));

    if (conn < 0) {
        ERR_EXIT("connect");
    }

    char sendbuf[1024] = {0};
    char recvbuf[1024] = {0};

    while (fgets(sendbuf, sizeof(sendbuf), stdin) != NULL) {
        write(listenFd, sendbuf, strlen(sendbuf));
        read(listenFd, recvbuf, strlen(recvbuf));
        fputs(recvbuf, stdout);

        memset(&sendbuf, 0, sizeof(sendbuf));
        memset(&recvbuf, 0, sizeof(recvbuf));
    }


    return 0;
}
