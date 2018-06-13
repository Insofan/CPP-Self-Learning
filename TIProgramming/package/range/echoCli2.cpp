//
// Created by Insomnia on 2018/5/31.
//

#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>


#define ERR_EXIT(m) \
        do \
        {\
            perror(m);\
            exit(EXIT_FAILURE);\
        }while(0)

struct packet {
    int len;
    char buf[1024];
};

ssize_t readn(int fd, void *buf, size_t count) {
    size_t nleft = count;
    ssize_t nread;
    char *bufp = (char *) buf;

    while (nleft > 0) {
        if ((nread = read(fd, bufp, nleft)) < 0) {
//            if (errno == EINTR) {
//                continue;
//            } else {
//                return -1;
//            }
            if (errno == EINTR) {
                continue;
            } else {
                return -1;
            }
        } else if (nread == 0) {
            return count - nleft;
        }

        bufp += nread;
        nleft -= nread;
    }
    return count;
}

ssize_t writen(int fd, const void *buf, size_t count) {
    size_t nleft = count;
    ssize_t nwritten;
    char *bufp = (char *) buf;

    while (nleft > 0) {
        if ((nwritten = write(fd, bufp, nleft)) < 0) {
            if (errno == EINTR) {
                continue;
            } else {
                return -1;
            }
        } else if (nwritten == 0) {
            continue;
        }

        bufp += nwritten;
        nleft -= nwritten;
    }
    return count;
}


int main(void) {
    int sock;
    //第一个族， 第二个 socket 类型, 第三个参数可以填0
    sock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (sock < 0) {
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


    if (connect(sock, (struct sockaddr *) &servaddr, sizeof(servaddr)) < 0) {
        ERR_EXIT("connect");
    };

//    char sendbuf[1024] = {0};
//
//    char recvbuf[1024] = {0};

    struct packet sendbuf;
    struct packet recvbuf;
    memset(&sendbuf, 0, sizeof(sendbuf));
    memset(&recvbuf, 0, sizeof(recvbuf));
    //变为主动套字
    int n;
    while (fgets(sendbuf.buf, sizeof(sendbuf.buf), stdin) != NULL) {

        n = strlen(sendbuf.buf);
        sendbuf.len = htonl(n);
        //需要发布头部的四个字节
        writen(sock, &sendbuf.buf, 4+n);
        int ret = readn(sock, &recvbuf.len, 4);
        if (ret == -1) {
            ERR_EXIT("read");
        } else if (ret < 4) {
            printf("client close\n");
            break;
        }

        int n = ntohl(recvbuf.len);
        ret = readn(sock, recvbuf.buf, n);
        if (ret == -1) {
            ERR_EXIT("read");
        } else if (ret < n) {
            printf("client close\n");
            break;
        }
        fputs(recvbuf.buf, stdout);
        writen(sock, &recvbuf.buf, 4+n);
    }

    close(sock);
    return 0;
}