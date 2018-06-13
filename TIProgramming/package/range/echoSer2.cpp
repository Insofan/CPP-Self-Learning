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
#include <cerrno>


#define ERR_EXIT(m) \
        do \
        {\
            perror(m);\
            exit(EXIT_FAILURE);\
        }while(0)


            //发送字节长度， 现接受包头4个单位， 再接收宝体
struct packet {
    int len;
    char buf[1024];
};

//size_t 无符号整数 ssize是有符号整数
ssize_t readn(int fd, void *buf, size_t count) {
    size_t nleft = count;
    ssize_t nread;
    char *bufp = (char *) buf;

    while (nleft > 0) {
        if ((nread = read(fd, bufp, nleft)) < 0) {
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

void do_service(int conn) {
    //变为主动套字
//    char recvbuf[1024];
    struct packet recvbuf;
    while (1) {
        //memset : 将s所指向的某一块内存中的每个字节的内容全部设置为ch指定的ASCII值,
        memset(&recvbuf, 0, sizeof(recvbuf));
        int ret = readn(conn, &recvbuf.len, 4);
        if (ret == -1) {
            ERR_EXIT("read");
        } else if (ret < 4) {
            printf("client close\n");
            break;
        }

        int n = ntohl(recvbuf.len);
        ret = readn(conn, recvbuf.buf, n);
        if (ret == -1) {
            ERR_EXIT("read");
        } else if (ret < n) {
            printf("client close\n");
            break;
        }
        fputs(recvbuf.buf, stdout);
        writen(conn, &recvbuf.buf, 4+n);
    }
}

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

    int on = 1;
    if (setsockopt(listenfd, SOL_SOCKET, SO_REUSEADDR, &on, sizeof(on)) < 0) {
        ERR_EXIT("setsokopt");
    }

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

    int conn;
    pid_t pid;
    while (1) {

        if (conn = accept(listenfd, (struct sockaddr *) &peeraddr, &peerlen) < 0) {
            ERR_EXIT("accept");
        }
        //网络字节序转换成点分制，
        printf("ip = %s port = %d\n", inet_ntoa(peeraddr.sin_addr), ntohs(peeraddr.sin_port));

        pid = fork();
        if (pid == -1) {
            ERR_EXIT("fork");
        }

        if (pid == 0) {
            close(listenfd);
            do_service(conn);
        } else {
            close(conn);
        }
    }


    return 0;
}