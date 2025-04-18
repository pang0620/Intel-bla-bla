// Header file
#include <stdio.h>
#include "student.h"    //struct student Student

//Macro
//#define _CRT_SECURE_NO_WARNINGS
#define PI 3.141592
#define UNIT "cm^2"
#define SUCCESS_PRINT printf("면적 구하기 성공\n")

#define SUM(a, b) (a + b)
#define MUL(a, b) (a * b)

#define NAME_CAT(x, y) (x ## y)

#define VER 7
#define BIT16  //int range


int main(void)
{
#if VER >= 6
    printf("V%d.\n", VER);
#endif

    int max;
#line 2025 "macro.c"

#ifdef BIT16
    max = 32767;
#else
    max = 2147483647;
#endif

    printf("int max range: %d\n", max);

    //ready-made macro
    printf("@%s\n", __FILE__);
    printf("@%s function\n", __FUNCTION__);
    printf("@%d line\n", __LINE__);
    printf("%s\n", __DATE__);
    printf("%s\n", __TIME__);

    int r;
    printf("enter radius: ");
    scanf("%d", &r);

    printf("area: %.2lf%s\n", PI*r*r, UNIT);
    SUCCESS_PRINT;

    printf("SUM(1,2): %d\n", SUM(1,2));
    printf("MUL(2,5): %d\n", MUL(2,5));

    for (int i=1; i<=3; i++)
    {
        int NAME_CAT(score, i);
        NAME_CAT(score, i) = 10 * i;
        printf("%d ", NAME_CAT(score, i));
    }
    printf("\n");

    Student s1;

    s1.num = 315;
    s1.grade = 3.6;

    return 0;
}