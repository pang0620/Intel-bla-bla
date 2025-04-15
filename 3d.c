#define _CRT_SECURE_NO_WARNINGS

/***********************************************************/
// [4-13] BIT operator
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{
    int a=10, b=12;

    printf("a&b=%d\n", a&b);
    //a: 00001010
    //b: 00001100
    //r: 00001000
    printf("a|b=%d\n", a|b);
    //a: 00001010
    //b: 00001100
    //r: 00001110
    printf("a^b=%d\n", a^b);
    //a: 00001010
    //b: 00001100
    //r: 00000110
    printf("~a=%d\n", ~a);
    //a: 00001010
    //r: 11110101
    printf("a<<1=%d\n", a<<1);
    //a: 00001010
    //r: 00101000
    printf("b>>1=%d\n", b>>1);
    //b: 00001100
    //r: 00000110
    printf("~a>>1=%d\n", ~a>>1);
    //a: 00001010
    //r: 11110101

	return 0;
}
#endif

/***********************************************************/
// [4-13] operator priority
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{
    printf("10 / 5 * 2 = %d\n", 10 / 5 * 2);    //4
    printf("10 > 5 && 10 != 5 : %d\n", 10 > 5 && 10 != 5);      //1(true)
    printf("10 %% 3 == 0 : %d\n", 10 % 3 == 0);

	return 0;
}
#endif

/***********************************************************/
// [5-1] select-if 
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{
    int age;
    printf("나이 입력 : ");
    scanf("%d", &age);

    if (age>=20) {
        printf("성인입니다.\n");
    }

	return 0;
}
#endif

/***********************************************************/
// [5-2] Common whatwasthatterm
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{
    int a;
    printf("정수 입력: ");
    scanf("%d", &a);

    if (a%5==0 && a%3==0) {
        printf("%s\n", "3과 5의 배수입니다.\n");
    }

	return 0;
}
#endif

/***********************************************************/
// [5-3] 
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{
    int age;
    int price;

    printf("나이 입력 : ");
    scanf("%d", &age);

    if (age>=20) {
        printf("성인입니다.\n");
        price = 50000;
    } else {
        printf("미성년자입니다.\n");
        price = 20000;
    }
    printf("가격: %d\n", price);

	return 0;
}
#endif

/***********************************************************/
// [5-4] odd ends...
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{
    int a;
    printf("짝홀을 판단할 정수 입력: ");
    scanf("%d", &a);

    if (a%2==0) {
        printf("짝수\n");
    } else {
        printf("홀수\n");
    }

	return 0;
}
#endif

/***********************************************************/
// [5-5] Mart Casher
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{
    int a;
    double rate = 0.1;
    printf("개수 입력: ");
    scanf("%d", &a);

    if (a>10) printf("%.0lf원입니다.\n", 10000*(1-rate)*a);
    else printf("%d원입니다.\n", 10000*a);

	return 0;
}
#endif

/***********************************************************/
// [5-6] 학점 게산 프로그램
/***********************************************************/

#if 0
#include <stdio.h>

int main() {
    int score;
    scanf("%d", &score);
    
    if (score<=100 && score>=90) {
        printf("A\n");
    }
    else if (score<90 && score>=80) {
        printf("B\n");
    }
    else if (score<80 && score>=70) {
        printf("C\n");
    }
    else if (score<70 && score>=60) {
        printf("D\n");
    }
    else {
        printf("F\n");
    }
    
    return 0;
}
#endif

/***********************************************************/
// [5-7] mart casher extended
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{
    int price = 10000;
    int amount;
    int member;
    int pay=0;
    double rate = 0.1;

    //input 
    printf("개수 입력: ");
    scanf("%d", &amount);
    printf("회원 여부 (회원:1, 비회원:0): ");
    scanf("%d", &member);

    //calc.
    pay = amount*price;
    if (member) pay = amount*(1-rate)*price;
    if (amount>10) pay = amount*(1-rate)*price;

    printf("%0lf원입니다.\n", pay);

	return 0;
}
#endif

/***********************************************************/
// [5-7-2] switch case?
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{
    int month=6;

    switch (month) {
        case 4:
            printf("spring\n");
            break;
        case 6:
            printf("summer\n");
            break;
        case 9:
            printf("fall\n");
            break;
        case 11:
            printf("winter\n");
            break;
    }

	return 0;
}
#endif

/***********************************************************/
// [5-8] rankgiving 
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{
    int rank;
    int prize;

    printf("등수 입력: ");
    scanf("%d", &rank);

    switch (rank) {
        case 1:
            prize = 300;
            break;
        case 2:
            prize = 200;
            break;
        case 3:
            prize = 100;
            break;
    }
    
    printf("\"%d만원\"\n", prize);

	return 0;
}
#endif

/***********************************************************/
// [5-check] vending machine extended
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{
    int cash;
    printf("금액 입력: ");
    scanf("%d", &cash);

    int menu;
    printf("Menu: ");
    scanf("%d", &menu);

    int price;
    switch (menu) {
        case 1: 
            price = 700;
            break;
        case 2: 
            price = 1000;
            break;
        case 3: 
            price = 500;
            break;
        default: 
            price = 0;
            break;
    }
    int sum = cash - price;

    if (sum<0) printf("not enough money\n");
    else {
        int a, b, c;

        a = sum/1000;
        b = (sum%1000)/500;
        c = (sum%1000)%500;

        printf("잔돈: %d\n", sum);
        printf("1000:%d개, 500:%d개, 100:%d개\n", a, b, c);
    }

	return 0;
}
#endif

/***********************************************************/
// [5-check2] 
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{
    int A,B;
    char exp;

    scanf("%d%c%d", &A, &exp, &B);
    switch (exp) {
        case '+':
            printf("%d+%d=%d\n", A, B, A+B);
            break;
        case '-':
            printf("%d-%d=%d\n", A, B, A-B);
            break;
        case '*':
            printf("%d*%d=%d\n", A, B, A*B);
            break;
        case '/':
            printf("%d/%d=%d\n", A, B, A/B);
            break;
    }

	return 0;
}
#endif

/***********************************************************/
// [6-1] calculating number of digits
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{
    int num;
    printf("정수 입력: ");
    scanf("%d", &num);

    int digits = 0;
    while (num != 0)    // non-clear iteration
    {
        digits++;
        num /= 10;    
    }

    printf("%d자릿수\n", digits);

	return 0;
}
#endif

/***********************************************************/
// [6-2] value<10 program
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{
    int a=0;

    while (a<10) {
        printf("정수 입력: ");
        scanf("%d", &a);
    }
    printf("종료되었습니다.\n");

	return 0;
}
#endif

/***********************************************************/
// [6-3] sum
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{
    int a;
    int sum=0;

    while (1) {
        printf("정수 입력: ");
        scanf("%d", &a);
        if (a==-1) break;
        sum += a;
    }
    printf("sum: %d\n", sum);

	return 0;
}
#endif

/***********************************************************/
// [6-4] for practice
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{
    printf("\n");

    for (int i=1; i<=10; i++) {
        printf("%d ", i);
    }
    printf("\n\n");

    for (int i=21; i<=57; i++) {
        printf("%d ", i);
    }
    printf("\n\n");

    for (int i=96; i>=53; i--) {
        printf("%d ", i);
    }
    printf("\n\n");

    for (int i=1; i<=100; i++) {
        if(i%3==0 && i%5==0) printf("%d ", i);
    }
    printf("\n\n");

	return 0;
}
#endif

/***********************************************************/
// [6-5] 
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{
    int a;
    scanf("%d", &a);

    for (int i=1; i<=10; i++) {
        printf("%d ", a*i);
    }
    printf("\n");

	return 0;
}
#endif

/***********************************************************/
// [6-5] 
/***********************************************************/

#if 0
#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);

    for (int i=1; i<10; i++) {
        printf("%d * %d = %d\n", N, i, N*i);
    }

    return 0;
}
#endif

/***********************************************************/
// [6-7] 약수
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{
    int a;
    scanf("%d", &a);

    for (int i=1; i<=num/2; i++) {
        if (a%i==0) printf("%d ", i);
    }
    printf("\n");

	return 0;
}
#endif

/***********************************************************/
// [6-?] 
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{
    for (int i=7; i<=16; i++) {
        printf("%d ", i-6);
    }

	return 0;
}
#endif

/***********************************************************/
// [6-?] sum with do-while
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{
    int sum=0;
    int num;

    do
    {
        printf("정수 입력: ");
        scanf("%d", &num);
        sum += num;
        printf("sum: %d\n", sum);
    } while (num!=-1);
    

	return 0;
}
#endif

/***********************************************************/
// [6-frequent] 
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{
    int num, sum=0;

    while (1) {

        printf("정수 입력: ");
        scanf("%d", &num);
        sum+=num;
        printf("%d\n", sum);

        if (num==-1) {
            break;
        }
    }

	return 0;
}
#endif

/***********************************************************/
// [6-8] 
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{
    int W, target;
    scanf("%d %d", &W, &target);

    if (W<=target) {
        printf("몸무게 입력 오류\n");
        return -1;
    } else {
        int temp, i=1;

        while (W>target) {
            printf("%d주차 감량:", i);
            scanf("%d", &temp);
            W-=temp;
            i++;
        }

        printf("%dkg 달성 ㅊㅋ\n", W);

        return 0;
    }
}
#endif

/***********************************************************/
// [6-9] login program 
/***********************************************************/

#if 0
#include <stdio.h>
#include <string.h>

int main(void)
{
    char fruit[20] = "banana";
    char fruit2[20] = "banana";
    printf("%d\n", strcmp(fruit, fruit2));  //0: true

    char input_id[20], input_pw[20];
    char login_id[20] = "nayeho";
    char login_pw[20] = "1234";

    while (1) {
        printf("ID: ");
        scanf("%s", input_id);
        printf("PW: ");
        scanf("%s", input_pw);
        if (!(strcmp(login_id, input_id) && (strcmp(login_pw, input_pw)))) {
            printf("login success\n");
            break;
        } else { 
            printf("fail\n");
        }
    }

	return 0;
}
#endif

/***********************************************************/
// [6-11] star basic
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{
    for (int i=0; i<5; i++) {
        for (int j=0; j<5; j++) printf("*");
        printf("\n");
    }

	return 0;
}
#endif

/***********************************************************/
// [6-13] star 01 
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{
    for (int i=0; i<5; i++) {
        for (int j=0; j<i+1; j++) printf("*");
        printf("\n");
    }

	return 0;
}
#endif

/***********************************************************/
// [6-check2] 
/***********************************************************/

#if 1
#include <stdio.h>

int main(void)
{
    int N;
    scanf("%d", &N);

    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            if (i==j || i+j==N-1) printf("*"); else printf(" ");
        }
        printf("\n");
    }

	return 0;
}
#endif