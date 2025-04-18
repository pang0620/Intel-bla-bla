#include <stdio.h>

void input_data(int *, int *);
double average(int, int);

//declare
extern int c = 100;

//맥은 링크를 실행해주지 않음: clang 01.c 02.c -o main으로 해결
int main(void)
{
    int a,b;
    double avg;

    input_data(&a, &b);
    avg = average(a,b);
    printf("%d, %d's avg: %.1f\n", a, b, avg);

    return 0;
}