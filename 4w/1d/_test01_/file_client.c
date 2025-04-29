#include <arpa/inet.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

void error_handling(char *message, int num);
int main(int argc, char *argv[]) {
    int n, fd;
    int sock;
    char buf[100];
    struct sockaddr_in serv_addr;

    if (argc != 4) {
        printf("Usage : %s <IP> <port> <file>\n", argv[0]);
        exit(1);
    }

    // open file
    if ((fd = open(argv[3], O_RDONLY)) < 0) {
        perror("open()");
        error_handling("open() error", 10);
    }

    sock = socket(PF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket()");
        error_handling("socket() error", 2);
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(argv[1]);
    serv_addr.sin_port = htons(atoi(argv[2]));

    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("connect()");
        error_handling("connect() error!", 3);
    }

    // SENDING FILE

    // write
    do {
        n = read(fd, buf, sizeof(buf));
        if (n > 0)
            write(sock, buf, n);
        else if (n == 0) {
            fputs("Done...", stdout);
            fputc('\n', stdout);
            break;
        } else {
            perror("write()");
            error_handling("write() error", 11);
        }
    } while (1);

    close(fd);
    close(sock);
    return 0;
}
void error_handling(char *message, int num) {
    fputs(message, stderr);
    fputc('\n', stderr);
    exit(num);
}
