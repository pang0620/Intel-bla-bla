#include <stdio.h>

struct time {
	int hour;
	int min;
	int sec;
} gtime = {1,2,3};

char *array[4] = {"one","two","three","four"};

int func(short sw, char *str)
{
	printf("first char = %s\n",str);
	if(sw)
		return 2;
	return 3;
}

int main()
{
	int i;
	for(i=0;i<4;i++) {
		printf("loop %d : ",i);
		gtime.hour += func(i%2,array[i]);
	}
	return 0;
}
	

