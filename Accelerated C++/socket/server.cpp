//
// Created by Insofan on 2018/5/2.
// MIT License
// 写一个最简单的socket服务器

#include <iostream>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <unistd.h>

using namespace std;

int main() {
    int client, server;
    int portNum = 1500;
    bool isExit = false;
    int bufsize = 1024;
    char buffer[bufsize];

    struct  sockaddr_in server_addr;
    socklen_t size;
    //init socket.
    client = socket(AF_INET, SOCK_STREAM, 0);

    if (client < 0) {
        cout << "客户端连接错误" << endl;
        exit(1);
    }

    cout << "Server Socket connection created..." << endl;

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htons(INADDER_ANY);
    server_addr.sin_port = htons(portNum);

    //binding socket;
    if (bind(client, (struct sockaddr*)&server_addr, sizeof(server_addr)))
}




