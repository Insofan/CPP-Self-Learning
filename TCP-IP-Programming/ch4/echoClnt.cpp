// 
// Created by Insomnia on 2018/7/10.
//

#include <stdlib.h>
#include <stdio.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <string.h>
#include <unistd.h>


#define BUF_SIZE 1024

void errorHandling(char *message);

int main() {

    int sock;
    sock = socket(PF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        errorHandling("Sock error");
    }

    struct sockaddr_in servAddr;

    memset(&servAddr, 0, sizeof(servAddr));
    servAddr.sin_family = AF_INET;
    servAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    servAddr.sin_port = htons(atoi("8888"));

    if (connect(sock, (struct sockaddr*) &servAddr, sizeof(servAddr)) < 0) {
        errorHandling("connect error");
    } else {
        puts("connect");
    }

    char message[BUF_SIZE];
    while (1) {
        fputc("input message(Q to quit): ", stdout);
        fgets(message, BUF_SIZE, stdin);

    }

    return 0;
}


void errorHandling(char *message) {
    fputs(message, stderr);
    fputc('\n', stderr);
    exit(1);
}