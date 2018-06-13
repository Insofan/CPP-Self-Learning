//
// Created by Insomnia on 2018/6/12.
//

#include <errno.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <cstdlib>
#include <cstdio>
#include <arpa/inet.h>
#include <zconf.h>
#include <cstring>

#define ERR_EXIT(m) \
        do\
        {\
            perror(m);\
            exit(EXIT_FAILURE);\
        }while(0)\

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

//可以接收， 但接收后并不移除
ssize_t recv_peek(int sockfd, void *buf, size_t len) {
    //接到数据返回， 无数据阻塞
    while (1) {
        int ret = recv(sockfd, buf, len, MSG_PEEK);
        if (ret == -1 && errno == EINTR) {
            continue;
        } else {
            return ret;
        }
    }
}

//只能用于套接口
ssize_t readline(int sockfd, void *buf, size_t maxline) {
    int ret;
    int nread;
    char *bufp = buf;
    int nleft = maxline;

    while (1) {
        ret = recv_peek(sockfd, bufp, nleft);
        if (ret < 0) {
            return ret;
        } else if (ret == 0) {
            //0时对方关闭套接口
            return ret;
        }
        nread = ret;

        int i;
        for (i = 0; i < nread; i++) {
           if (bufp[i] == '\n') {
               //有换行时， 我们将读取的从缓存区移除
               ret = readn(sockfd, bufp, i + 1);
               if (ret != i+1) {
                   exit(EXIT_FAILURE);
               } else {
                   return ret;
               }
           }
        }

        if (nread > nleft) {
            exit(EXIT_FAILURE);
        }
        nleft -= nread;
        ret = readn(sockfd, bufp, nread);
    }


}

void doService(int conn) {
    struct packet recvbuf;
    int n;
    while (1) {
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
        writen(conn, &recvbuf.buf, 4 + n);
    }
}

int main(int argc, char *argv[]) {
    int listenFd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

    if (listenFd < 0) {
        ERR_EXIT("socket");
    }

    struct sockaddr_in servaddr;
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(6666);
    servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");

    int on = 1;
    int op = setsockopt(listenFd, SOL_SOCKET, SO_REUSEADDR, &on, sizeof(on));
    if (op < 0) {
        ERR_EXIT("sock option");
    }

    int bindFlag = bind(listenFd, (struct sockaddr *) &servaddr, sizeof(servaddr));
    if (bindFlag < 0) {
        ERR_EXIT("bind");
    }
    if (listen(listenFd, SOMAXCONN) < 0) {
        ERR_EXIT("listen");
    }

    struct sockaddr_in peeraddr;
    socklen_t peerlen = sizeof(peeraddr);

    int conn;
    pid_t pid;
    while (1) {
        conn = accept(listenFd, (struct sockaddr *) &peeraddr, &peerlen);

        if (conn < 0) {
            ERR_EXIT("accept");
        }

        printf("ip = %s port = %d\n", inet_ntoa(peeraddr.sin_addr), ntohs(peeraddr.sin_port));

        pid = fork();

        if (pid == -1) {
            ERR_EXIT("fork");
        }

        if (pid == 0) {
            close(conn);
            doService(conn);
        } else {
            close(conn);
        }
    }


    return 0;
}