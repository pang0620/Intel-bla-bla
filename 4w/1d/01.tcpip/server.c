#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

void error_handling(char *message);

int main(int argc, char *argv[]) {
    int serv_sock;
    int clnt_sock;
    int str_len;

    struct sockaddr_in serv_addr;
    struct sockaddr_in clnt_addr;
    socklen_t clnt_addr_size;

    char message[] = "Hello World!";
    char msg2[30];

    if (argc != 2) {
        printf("Usage : %s <port>\n", argv[0]);
        exit(1);
    }

    // 01. socket: int, file descriptor(per each clients)
    // PF_INET: ipv4, sockstream: (tcp, connection-based), 0: tcp? udp?
    serv_sock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (serv_sock < 0) {
        perror("socket()");
        error_handling("socket() error");
        exit(1);
    }

    // memory for structs (often used method for init)
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    // host to network addr(long), network uses big-endian
    // htonl() converts itself
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    // host to network port(short), network uses big-endian
    // atoi: "5000" to 5000. kinda eval()
    serv_addr.sin_port = htons(atoi(argv[1]));

    // 02. bind: define a phone call
    if (bind(serv_sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) ==
        -1) {
        perror("bind()");
        error_handling("bind() error");
        exit(2);
    }

    // 03. listen: phone recieve mod on
    if (listen(serv_sock, 5) < 0) // 5 times?
    {
        perror("listen()");
        error_handling("listen() error");
        exit(2);
    }

    clnt_addr_size = sizeof(clnt_addr);
    // 04. accpet: got a phone call
    // process sleeps here at accept()
    do {
        clnt_sock =
            accept(serv_sock, (struct sockaddr *)&clnt_addr, &clnt_addr_size);
        printf("clnt_sock: new client %d connected\n", clnt_sock);

        if (clnt_sock == -1) {
            perror("accept()");
            error_handling("accept() error");
            exit(3);
        }

        do {
            str_len = read(clnt_sock, msg2, sizeof(msg2) - 1);
            msg2[str_len] = '\0';
            if (str_len == -1) {
                perror("read()");
                error_handling("read() error");
            }
            if (str_len == 0)
                break;
            printf("Message from client: %s\n", msg2);
			/*
			if (strcmp(msg2, "quit")==0)
			{
				printf("quiting...\n");
				return 0;
			}
			*/
			write(clnt_sock, msg2, sizeof(msg2)-1);
        } while (1);
        printf("clnt_sock: client %d disconnected\n", clnt_sock);
    } while (1);

    close(clnt_sock);
    close(serv_sock);
    return 0;
}

void error_handling(char *message) {
    fputs(message, stderr);
    fputc('\n', stderr);
}

