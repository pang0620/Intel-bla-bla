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
    int n, out;
    int serv_sock;
    int clnt_sock;
    char buf[100];
    struct sockaddr_in serv_addr;
    struct sockaddr_in clnt_addr;
    socklen_t clnt_addr_size;

    if (argc != 3) {
        printf("Usage : %s <port> <file>\n", argv[0]);
        exit(1);
    }

    // open file
    if ((out = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC,
                    S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH)) < 0) {
        perror(argv[2]);
        error_handling("target file open() error", 5);
    }

    serv_sock = socket(PF_INET, SOCK_STREAM, 0);
    if (serv_sock < 0) {
        perror("socket()");
        error_handling("socket() error", 1);
    }
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    serv_addr.sin_port = htons(atoi(argv[1]));

    if (bind(serv_sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("bind()");
        error_handling("bind() error", 2);
    }

    if (listen(serv_sock, 5) < 0) {
        perror("listen()");
        error_handling("listen() error", 3);
    }

    clnt_addr_size = sizeof(clnt_addr);
    clnt_sock =
        accept(serv_sock, (struct sockaddr *)&clnt_addr, &clnt_addr_size);

    if (clnt_sock < 0) {
        perror("accept()");
        error_handling("accept() error", 4);
    }

    do {
        n = read(clnt_sock, buf, sizeof(buf));
        if (n > 0) {
            write(out, buf, n);
            printf("read : %d\n", n);
        } else if (n == 0) {
            printf("Done...\n");
            break;
        } else {
            perror("read()");
            error_handling("read() error", 6);
        }

    } while (1);

    close(out);
    close(clnt_sock);
    close(serv_sock);
    return 0;
}

void error_handling(char *message, int num) {
    fputs(message, stderr);
    fputc('\n', stderr);
    exit(num);
}
