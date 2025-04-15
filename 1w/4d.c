/***********************************************************/
// [6-12] when the stars align... 01
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{
    for (int j=0; j<5; j++) {
        for (int i=0; i<j+1; i++) {
            printf("*");
        }
        printf("\n");
    }

	return 0;
}
#endif

/***********************************************************/
// [6-13] when the stars align... 02
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{
    for (int j=0; j<5; j++) {
        for (int i=4; i>j; i--) {
            printf("@");
        }
        for (int i=0; i<j+1; i++) {
            printf("*");
        }
        printf("\n");
    }

	return 0;
}
#endif

/***********************************************************/
// [6-14] when the stars align... 03
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{
    for (int j=0; j<5; j++) {
        for (int i=5; i>j; i--) {
            printf("*");
        }
        printf("\n");
    }

	return 0;
}
#endif

/***********************************************************/
// [6-5] when the stars align... 04
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{
    for (int j=0; j<5; j++) {
        for (int i=0; i<j+1; i++) {
            printf(" ");
        }
        for (int i=5; i>j; i--) {
            printf("*");
        }
        printf("\n");
    }

	return 0;
}
#endif

/***********************************************************/
// [6-final] 
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{
    for (int j=2; j<10; j++)
    {
        for (int i=1; i<10; i++) {
            printf("%d * %d = %d\n", j, i, i*j);
        }
        printf("\n");
    }

	return 0;
}
#endif

/***********************************************************/
// [7-1] function 101
/***********************************************************/

#if 0
#include <stdio.h>

int sum(int a, int b);

int main(void)
{
    printf("%d\n", sum(3, 5));
    printf("%d\n", sum(10, 20));

	return 0;
}

int sum(int a, int b) {
    return a+b;
}

#endif

/***********************************************************/
// [7-3] no return
/***********************************************************/

#if 0
#include <stdio.h>

void print_char(char ch, int cnt);

int main(void)
{
    int size = 10;
    char ch = '*';

    for (int i=1; i<size+1; i++)
    {
        print_char(' ', size-i);
        print_char(ch, i);
        print_char(ch, i-1);
        printf("\n");
    }

    for (int i=1; i<size+1; i++)
    {
        print_char(' ', i);
        print_char(ch, size-i);
        print_char(ch, size-1-i);
        printf("\n");
    }

	return 0;
}

void print_char(char ch, int cnt)
{
    for (int i=0; i<cnt; i++)
    {
        printf("%c", ch);
    }
}
#endif

/***********************************************************/
// [7-check] two double's avg
/***********************************************************/

#if 0
#include <stdio.h>

double average(double a, double b);

int main(void)
{
    printf("%.2lf\n", average(1.5, 3.4));

	return 0;
}

double average(double a, double b)
{
    return (a+b)/2;
}

#endif

/***********************************************************/
// [7-2] wut
/***********************************************************/

#if 0
#include <stdio.h>

int get_num();

int main(void)
{
    int a = get_num();
    int b = get_num();
    printf("%d\n", a+b);

	return 0;
}

// returns int
int get_num()
{
    int result;

    printf("양수  입력: ");
    scanf("%d", &result);
    return result;
}
#endif

/***********************************************************/
// [7-4] no return, no numeter
/***********************************************************/

#if 0
#include <stdio.h>

void print_line(void);

int main(void)
{
    print_line();
    printf("a\tb\tc\td\n");
    print_line();

	return 0;
}

// 50 '='s
void print_line(void) {
    for (int i=0; i<30; i++) printf("-");
    printf("\n");
}
#endif

/***********************************************************/
// [7-5] recursive function
/***********************************************************/

#if 0
#include <stdio.h>

int fibonacci(int a);

int main(void)
{
    for (int i=1; i<=20; i++)
    {
        printf("%d ", fibonacci(i));
    }
    printf("\n");

	return 0;
}

// get fibonacci[num] via recursive function.
// * recursive function's resource usage grows exponentially.
int fibonacci(int num)
{
    if (num <= 2) return 1;
    else
    {
        return fibonacci(num-1) + fibonacci(num-2);
    }

    return 0;
}
#endif

/***********************************************************/
// [7-6] abs
/***********************************************************/

#if 0
#include <stdio.h>

int abs(int num);

int main(void)
{
    int a=10, b=-10;
    printf("%d\n", abs(a));
    printf("%d\n", abs(b));

	return 0;
}

int abs(int num) {
    return num>0 ? num : -num;
}
#endif

/***********************************************************/
// [7-7, 8, 9, 10]  complete number
/***********************************************************/

#if 0
#include <stdio.h>

int is_divisor(int num1, int num2);
void print_divisors(int num1);
int get_sum_of_divisors(int num);
int is_perfect_number(int num);
void print_perfect_number(int num);

int main(void)
{
    printf("perfect numbers: ");
    int i=2;
    while (i<10001) {
        if (is_perfect_number(i)) printf("%d ", i);
        i++;
    }
    printf("\n");

	return 0;
}

//step 1. 
//returns true when p2 is p1's divisor.
int is_divisor(int num1, int num2) { return num1%num2==0; }
//step 2.
//prints every divisor of given number.
void print_divisors(int num)
{
    printf("%d의 약수: 1 ", num);

    int i=2;
    while (i<=num/2)
    {
        if (is_divisor(num, i)) printf("%d ", i);
        i++;
    }

    printf("%d\n", num);
}
//step 3.
//returns sum of given number's every divisors.
int get_sum_of_divisors(int num)
{
    int i=2, sum=1+num;
    while (i<=num/2)
    {
        if (is_divisor(num, i)) sum+=i;
        i++;
    }

    return sum;
}
//step 4.
//but does it djent?
int is_perfect_number(int num)
{
    return get_sum_of_divisors(num)/2==num ? 1 : 0;
}
//step 5.
//print if given number's a perfect number.
void print_perfect_number(int num)
{
    printf("%d \tis %sa perfect number.\n",
       num, is_perfect_number(num) ? "" : "not ");
}



#endif



/***********************************************************/
// [7-11] title
/***********************************************************/

#if 0
#include <stdio.h>
#include <stdlib.h> // rand(), srand()
#include <time.h> // time()

int main(void)
{
    srand(time(NULL));  //initialize seed by time
    // integer between 1 and 100.
    int random_number = rand()%100+1;

    int guess;
    while (1) 
    {
        printf("guess number: ");
        scanf("%d", &guess);
        if (guess>random_number) printf("big\n");
        else if (random_number==guess) break;
        else printf("small\n");
    }

    printf("done.\n");

	return 0;
}
#endif

/***********************************************************/
// [8-1] declare array and its usage
/***********************************************************/

#if 0
#include <stdio.h>
#define AMOUNT 5

int main(void)
{
    int grades[AMOUNT];

    for (int i=0; i<AMOUNT; i++) {
        scanf("%d", &grades[i]);
    }

    for (int i=0; i<AMOUNT; i++) {
        printf("%d ", grades[i]);
    }
    printf("\n");

	return 0;
}
#endif

/***********************************************************/
// [8-2] declaration and usage of array
/***********************************************************/

#if 0
#include <stdio.h>
    
int main(void)
{
    int array[5] = {8, 4, 99, 6, 7};

    printf("array에 들어 있는 홀수는 ");
    for (int i=0; i<5; i++) {
        if (array[i]%2==1) printf("%d ", array[i]);
    }
    printf("이다.\n");

	return 0;
}
#endif

/***********************************************************/
// [8-3] array with sizeof()
/***********************************************************/

#if 0
#include <stdio.h>
#define ARRAY_SIZE 5

int main(void)
{
    int scores[ARRAY_SIZE];

    int sum=0;
    for (int i=0; i<ARRAY_SIZE; i++) {
        printf("%d과목 성적을 입력하세요: ", i+1);
        scanf("%d", &scores[i]);
        sum += scores[i];
    }

    printf("총점: %d점, 평균: %d점\n", sum, sum/ARRAY_SIZE);

	return 0;
}
#endif

/***********************************************************/
// [8-4] declare * init of a char array
/***********************************************************/

#if 0
#include <stdio.h>
#define ARR_SIZE 5

int main(void)
{
    int array[ARR_SIZE] = {1,2,3,4,5};
    char fruit[ARR_SIZE+1] = {'a', 'p', 'p', 'l', 'e'};
    char fruit2[ARR_SIZE+1] = "apple";
    //[5] includes no \0(null character).

    printf("%s\n", fruit);
    printf("%s\n", fruit2);

    char name[10];
    name[0] = 'k';
    name[1] = 'j';
    name[2] = 'y';
    name[3] = '\0';
    
    printf("%s\n", name);

	return 0;
}
#endif

/***********************************************************/
// [8-5] strcpy
/***********************************************************/

#if 0
#include <stdio.h>
#include <string.h>
#define ARR_SIZE 100

int main(void)
{
    char cat_name[ARR_SIZE] = "no name yet";
    char input[ARR_SIZE];

    printf("name: %s\n", cat_name);

    scanf("%s", input);
    strcpy(cat_name, input);
    printf("name: %s\n", cat_name);

	return 0;
}
#endif

/***********************************************************/
// [8-6] gets & puts
/***********************************************************/

#if 0
#include <stdio.h>
#define ARR_SIZE 100

int main(void)
{
    char inputs[ARR_SIZE];
    printf("next lunch: ");
    gets(inputs);
    puts(inputs);

	return 0;
}
#endif

/***********************************************************/
// [8-7] lowercase
/***********************************************************/

#if 0
#include <stdio.h>
#define ARR_SIZE 100

int main(void)
{
    char input[ARR_SIZE];
    printf("문장 입력: ");
    gets(input);

    for (int i=0; i<ARR_SIZE; i++) {
        //"%c"로 뽑았더니 null을 못잡는당.
        if (input[i]=="\0") break;
        input[i] = input[i]>=65 && input[i]<97 ? input[i]-'A'+'a' : input[i];
    }

    puts(input);

	return 0;
}
#endif

/***********************************************************/
// [8-sort] basic sort
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{
    int arr[6] = {5,4,3,2,1,0};
    int length = sizeof(arr)/sizeof(int);

    // sequential search: search for every values
    // ascending / descending 

    //bubble sort
    for (int i=0; i<length; i++) {
        for (int j=0; j<length; j++) {

        }

    }
    
    for (int i=0; i<length; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

	return 0;
}
#endif