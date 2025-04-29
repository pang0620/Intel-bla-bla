#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>
#define BUFFSIZE 100

void error_handling(char *message);

int main(int argc, char *argv[]) {
    int sock;
    struct sockaddr_in serv_addr;
    char message[BUFFSIZE];
    char msg2[BUFFSIZE];
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

    // r&w: actual talk
    // sleep at read() til' something comes
    do {
        fputs("Enter Message: ", stdout);
		/*
		 *	client sleeps here (@fgets) even server is down
		 *	since client only notices if server's down at read().
		 *	fix?
		 *
		 *	target: select(); 
		 *	-> find where the error occured(server? nth client?)
		 *	what's an blocking function?
		 *
		 *	fgets() and read() by thread via function form
		 *	parent-child process related I guess
		 *	one process two while()
		 */
        fgets(msg2, sizeof(msg2), stdin);
        str_len = strlen(msg2) - 1;
        msg2[str_len] = '\0';

        str_len = write(sock, msg2, str_len);
		//exceptions
		if (str_len<=0)
            error_handling("write() error");
        if (!strcmp(msg2, "quit")) {
            printf("quiting...\n");
            break;
        }

        str_len = read(sock, message, sizeof(message) - 1);
		//exceptions
		// set priority by frequent command
        if (strlen > 0)
		{
            message[str_len] = '\0';
            printf("Message from server: '%s'\n", message);
        }
		else if (str_len == 0)
            break;
        else
            error_handling("read() error");
    } while (1);
    close(sock);

    return 0;
}

void error_handling(char *message) {
    fputs(message, stderr);
    fputc('\n', stderr);
    exit(1);
}
