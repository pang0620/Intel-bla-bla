#include <stdio.h>

int main(void)
{
    int N;
    scanf("%d", &N);

    char A[100] = {0};
    char *p1 = A;
    scanf("%s", A);

    int B[101];
    int *p2 = B;

    // 48: 0, 57: 9
    //for (int i=0; i<N; i++)
    while (*p2)
    {
        *p1++ = (int)(*p2++);
    }

    int sum=0;
    for (int i=0; i<N; i++)
    {
        sum+=A[i];
        printf("%d ", A[i]);
    }
    printf("\n");

    printf("%d\n", sum);


    return 0;
}