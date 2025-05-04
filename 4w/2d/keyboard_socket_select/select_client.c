#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#include <sys/select.h>
#include <sys/time.h>
#define BUFFSIZE 100

/*
   struct timeval
   {
   long tv_set;
   long tv-usec;
   }
   */

void error_handling(char *message, int num);

int main(int argc, char* argv[])
{
	int sock;
	int str_len, result;
	int fd_stdin = fileno(stdin);
	char message[BUFFSIZE];
	struct sockaddr_in serv_addr;
	struct timeval timeout;

	fd_set reads, temps;

	printf("stdin_fd : %d\n", fd_stdin);
	if(argc!=3) {
		printf("Usage : %s <IP> <port>\n", argv[0]);
		exit(1);
	}

	sock=socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
	if(sock < 0)
		error_handling("socket() error",1);
	memset(&serv_addr, 0, sizeof(serv_addr));
	serv_addr.sin_family=AF_INET;
	serv_addr.sin_addr.s_addr=inet_addr(argv[1]);
	serv_addr.sin_port=htons(atoi(argv[2]));

	FD_ZERO(&reads);
	FD_SET(fd_stdin, &reads);
	FD_SET(sock, &reads);
	timeout.tv_sec=5;
	timeout.tv_usec=5000;

	if(connect(sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) 
		error_handling("connect() error!",2);

	for(int i=0; i<2; i++)
	{
		temps=reads;
		timeout.tv_sec=5;
		timeout.tv_usec=0;

		if(FD_ISSET(i, &temps))
		{
			if(i==fd_stdin)
			{
				if (result = select(2,&temps,0,0,&timeout)==0)
				{
					puts("timeout");
					break;
				}
				else if (result == -1)
				{
					perror("select()");
					error_handling("select() error!", 10);
				}
				else
				{
					if(FD_ISSET(fd_stdin, &temps))
					{
						//  select fd: fd_stdin
						fputs("문자열을 입력하세요(quit:종료) : ",stdout);
						fgets(message, sizeof(message), stdin);
						str_len = strlen(message)-1;
						message[str_len] = '\0';	//'\n'제거
						if(!strcmp(message, "quit"))
							break;
						str_len=write(sock,message,str_len);
						if(str_len <= 0)
							error_handling("write() error",3);
					}
				}
			}
			else if(i==sock)
			{
				// select fd: sock
				if (result = select(2,&temps,0,0,&timeout)==0)
				{
					//this works????? I can't observe
					puts("timeout");
					break;
				}
				else if (result == -1)
				{
				perror("select()");
				error_handling("select() error!", 10);
				}
				else
				{
					str_len=read(sock, message, sizeof(message)-1);
					if(str_len > 0)
					{
						message[str_len] = '\0';
						printf("Message from server: %s \n", message);  
					}
					else if(str_len == 0) //서버 소켓 종료시
						break;
					else 
						error_handling("read() error!",4);
				}
			}
		}
	}
	close(sock);
	return 0;
}

void error_handling(char *message, int num)
{
//	perror("error_handling()");
	fputs(message, stderr);
	fputc('\n', stderr);
	exit(num);
}
