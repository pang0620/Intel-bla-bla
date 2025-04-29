#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/select.h>

#define BUF_SIZE 30

int main(int argc, char *argv[])
{
	fd_set reads, temps;
	int result, str_len;
	char buf[BUF_SIZE];
	struct timeval timeout;

	//init
	FD_ZERO(&reads);
	//I'm watching this
	FD_SET(0, &reads); // 0 is standard input(console), fd comes

	/*
	timeout.tv_sec=5;
	timeout.tv_usec=500000;	//micro-second, 50e-6 = 0.5sec
	*/

	while(1)
	{
		temps=reads;
		timeout.tv_sec=5;
		timeout.tv_usec=0;
		// 1: there's only 1 fd set
		// select() is also blocking function: wakes up by event|trigger
		result=select(1, &temps, 0, 0, &timeout);
		if(result==-1)
		{
			puts("select() error!");
			perror("select()");
			break;
		}
		else if(result==0)
		{
			puts("Time-out!");
		}
		else 
		{
			//is [0] set?
			if(FD_ISSET(0, &temps)) 
			{
				str_len=read(0, buf, BUF_SIZE);
				//includes \0: "hi\n\0"
				buf[str_len]=0;
				printf("message from console: %s", buf);
			}
		}
	}
	return 0;
}
