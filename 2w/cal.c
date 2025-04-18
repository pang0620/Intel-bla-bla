#include <stdio.h>

//receiving
extern int c;
void input_data(int *pa, int *pb)
{
    printf("Enter two integer: ");
    scanf("%d", pa);
    scanf("%d", pb);
    printf("c: %d\n", c);
}
double average(int a, int b)
{
    return a+b/2.0;
}