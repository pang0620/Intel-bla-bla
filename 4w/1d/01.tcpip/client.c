#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

void error_handling(char *message);

int main(int argc, char *argv[]) {
    int sock;
    struct sockaddr_in serv_addr;
    char message[30];
    char msg2[30];
    int str_len;

    if (argc != 3) {
        printf("Usage: %s <IP> <port>\n", argv[0]);
        exit(1);
    }

    sock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (sock < 0) {
        perror("socket()");
        error_handling("socket() error");
        exit(2);
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    // inet_addr() splits, remove '.'s, convert into big-endian
    serv_addr.sin_addr.s_addr = inet_addr(argv[1]);
    serv_addr.sin_port = htons(atoi(argv[2]));

    // dial server's addr by connect()
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) == -1)
        error_handling("connect() error");

    do {
        // r&w: actual talk
        // sleep at read() til' something comes

        do {
			printf("Enter Message: ");
			scanf("%s", msg2);
			//fgets("%s", 30, msg2);
			write(sock, msg2, strlen(msg2));

            str_len = read(sock, message, sizeof(message) - 1);
            message[str_len] = '\0';
            if (str_len == -1)
                error_handling("read() error");
            if (str_len == 0)
				break;
			printf("Message from server: %s\n", message);

        } while (1);

    } while (1);

    close(sock);
    return 0;
}

void error_handling(char *message) {
    fputs(message, stderr);
    fputc('\n', stderr);
    exit(1);
}
