/***********************************************************/
// [13-1] title
/***********************************************************/

#if 0
#include <stdio.h>

void assign(void);

int main(void)
{
    auto int a = 10;
        printf("A 값: %d\n", a);

	return 0;
}
void assign(void)
{
    auto int a = 20;
        printf("assign-A: %d\n");
}

#endif

/***********************************************************/
// [13-2] local variable in block
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{
    int a = 10;
        printf("01 a: %d\n");
    {
        int a = 20;
        {
            printf("02 a: %d\n");
            int a = 30;
            {
                printf("03 a: %d\n");
                int a = 40;
                {
                    printf("04 a: %d\n");
                    int a = 50;
                    {
                        printf("06 a: %d\n");
                        int a = 60;
                        {
                            printf("07 a: %d\n");
                            int a = 70;
                            {
                                printf("08 a: %d\n");

                            }
                        }
                    }
                }
            }
        }
    }

	return 0;
}
#endif

/***********************************************************/
// [13-3] global variable
/***********************************************************/

#if 0
#include <stdio.h>

int a;
void assign10(void);
void assign20(void);

int main(void)
{
    printf("a: %d\n", a);
    assign10();
    printf("a: %d\n", a);
    assign20();
    printf("a: %d\n", a);

	return 0;
}
void assign10(void)
{
    a = 10;
}
void assign20(void)
{
    auto int a;
    a = 20;
}
#endif

/***********************************************************/
// [13-4] static local variable
/***********************************************************/

#if 0
#include <stdio.h>

void print_star(void);

int main(void)
{
    print_star();
    print_star();
    print_star();
    print_star();
    print_star();
    print_star();

	return 0;
}
void print_star(void)
{
    static int a=1;
    for (int i=0; i<a; i++)
    {
        printf("*");
    }
    printf("\n");
    a++;
}
#endif

/***********************************************************/
// [13-5] register variable
/***********************************************************/

#if 0
#include <stdio.h>
#include <time.h> // clock()

int main(void)
{
    int num = 2000000000;
    long long sum = 0;
    long start = clock();

    for (int i=1; i<=num; i++)
    {
        if (num%i == 0)
        {
            sum += i;
        }
    }

    printf("%d의 약수의 합: %lld\n", num, sum);

    long end = clock();
    double time = (double)(end-start) / CLOCKS_PER_SEC;
    printf("runtime: %lfs\n", time);

	return 0;
}
#endif

/***********************************************************/
// [13-6] call by value
/***********************************************************/

#if 0
#include <stdio.h>

int add_ten(int a);

int main(void)
{
    int a = 10;
    printf("a: %d\n", a);

    // does not affect origin - needs edit
    a = add_ten(a);
    printf("a: %d\n", a);

	return 0;
}
int add_ten(int a)
{
    a = a+10;
    return a;
}
#endif

/***********************************************************/
// [13-7] call by addr
/***********************************************************/

#if 0
#include <stdio.h>

void add_ten(int* pa);

int main(void)
{
    int a=10;
    printf("a: %d\n", a);

    // direct attack!!!!!! - no need to edit
    add_ten(&a);
    printf("a: %d\n", a);

	return 0;
}

void add_ten(int* pa)
{
    *pa += 10;
}
#endif

/***********************************************************/
// [13-8] call by address of local variable??
/***********************************************************/

#if 0
#include <stdio.h>

int *sum(int a, int b);

int main(void)
{
    int a=10, b=20;
    int *resp = sum(a,b);
    printf("두 정수의 합: %d\n", *resp);

	return 0;
}

int *sum(int a, int b)
{
    // keep necessary addresses by static keyword
    static int result;
    result = a+b;
    return &result;
}
#endif

/***********************************************************/
// [13-challenge] global variable swap program
/***********************************************************/

#if 0
#include <stdio.h>

void swap(void);

int a, b;
int main(void)
{
    a = 10;
    b = 20;

    printf("a: %d, b: %d\n", a, b);

    swap();
    printf("a: %d, b: %d\n", a, b);

	return 0;
}

void swap(void)
{
    // since they're global, able to access anywhere
    int temp = a;
    a = b;
    b = temp;
}
#endif

/***********************************************************/
// [14-0] two-dimensional array
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{
    // 국 영 수 과
    int score1[4] = { 10, 20, 30, 40 };
    int score2[4] = { 20, 30, 40, 50 };
    int score3[4] = { 30, 40, 50, 60 };

    int scores[3][4] = {score1, score2, score3};
    //pass

	return 0;
}
#endif

/***********************************************************/
// [14-1] sum and avg: 4 j
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{
    // row: score series
    int scores[3][4] = 
    {
        {10,20,30,40},
        {20,30,40,50},
        {30,40,50,60}
    };

    for (int i=0; i<3; i++)
    {
        int sum=0;
        for (int j=0; j<4; j++)
            sum+=scores[i][j];
        printf("%0d's sum: %d, ", i+1, sum);
        printf("avg: %.1lf\n", (double)sum/4);
    }

	return 0;
}
#endif

/***********************************************************/
// [14-2] init table with scanf
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{
    int scores[3][4];

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 4; j++)
            scanf("%d", &scores[i][j]);

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
            printf("%d ", scores[i][j]);
        printf("\n");
    }

    return 0;
}
#endif

/***********************************************************/
// [14-practice] breaking 2d array
/***********************************************************/

#if 0
#include <stdio.h>

void input_2d_array(int pa[5][5]);
void input_2d_array2(int pa[5][5]);

void print_2d_array(int pa[5][5]);
void print_2d_array2(int pa[5][5]);
void print_2d_array3(int pa[5][5]);
void print_2d_array4(int pa[5][5]);
void print_2d_array5(int pa[5][5]);
void print_2d_array6(int pa[5][5]);
void print_2d_array7(int pa[5][5]);

int main(void)
{
    int array[5][5];
    int count=1;

    input_2d_array(array);
    print_2d_array(array);
    printf("\n");
    input_2d_array2(array);
    print_2d_array2(array);
    printf("\n");
    print_2d_array3(array);
    printf("\n");
    print_2d_array4(array);
    printf("\n");
    print_2d_array5(array);
    printf("\n");
    print_2d_array6(array);
    printf("\n");
    print_2d_array7(array);

    int array2[10][3]

    //from now: every table is 5*5, no parameter for int size
	return 0;
}

void input_2d_array(int pa[5][5])
{
    int count=1;

    for (int i=0; i<5; i++)
    {
        for (int j=0; j<5; j++)
            pa[i][j] = (5*i) + j+1;
    }
}

void input_2d_array2(int pa[5][5])
{
    int count=1;

    for (int i=0; i<5; i++)
    {
        for (int j=0; j<5; j++)
            pa[i][j] = (5*i) + j+21;
    }
}

void print_2d_array(int pa[5][5])
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
            printf("%3d ", pa[i][j]);
        printf("\n");
    }
}

void print_2d_array2(int pa[5][5])
{
    for (int j = 0; j < 5; j++)
    {
        for (int i = 0; i < 5; i++)
            printf("%3d ", pa[i][j]);
        printf("\n");
    }
}

void print_2d_array3(int pa[5][5])
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 5-1; j >= 0; j--)
            printf("%3d ", pa[i][j]);
        printf("\n");
    }
}

void print_2d_array4(int pa[5][5])
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 5-1; j >= 0; j--)
            printf("%3d ", pa[j][i]);
        printf("\n");
    }
}

void print_2d_array5(int pa[5][5])
{
    for (int i = 5-1; i >= 0; i--)
    {
        for (int j = 5-1; j >= 0; j--)
            printf("%3d ", pa[j][i]);
        printf("\n");
    }
}

void print_2d_array6(int pa[5][5])
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
            printf("%3d ", (i%2==0) ? pa[i][j] : pa[i][5-j-1] );
        printf("\n");
    }
}

void print_2d_array7(int pa[5][5])
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
            //printf("%3d ", (i%2==0) ? pa[i][j] : pa[i][5-j-1] );
            printf("%3d ", pa[i][(1 - i % 2) * j + (i % 2) * (4 - j)]);
        printf("\n");
    }
}

#endif

/***********************************************************/
// [14-3] string table
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{
    char animal[5][20];
    int row = sizeof(animal)/sizeof(animal[0]);   //5

    for (int i=0; i<row; i++)
    {
        scanf("%s", animal[i]);
    }

    for (int i=0; i<row; i++)
    {
        printf("%s ", animal[i]);
    }
    printf("\n");

	return 0;
}
#endif

/***********************************************************/
// [14-4] pointer array with string
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{
    char *p1 = "dog";
    char *p2 = "cat";
    char *p3 = "abc";
    char *p4 = "qwe";
    char *p5 = "egxc";

    char *parr[5] = {p1, p2, p3, p4, p5};

    for (int i=0; i<5; i++)
        printf("%s\n", parr[i]);
        // printf("%s\n", *parr);       //how?

	return 0;
}
#endif

/***********************************************************/
// [14-5] int pointer array
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{
    int arr1[4] = {1, 2, 3, 4};
    int arr2[4] = {2, 3, 4, 5};
    int arr3[4] = {3, 4, 5, 6};

    int *parr[3] = {arr1, arr2, arr3};

    // cannot get int table's column?
    int column = 4;

    for (int i=0; i<column; i++)
        printf("%3d ", (*parr)[i]);
    printf("\n");

    return 0;
}
#endif

/***********************************************************/
// [14-challenge] sum of rows/columns
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{
    int arr[5][6]={0};
    int ROW_SIZE = sizeof(arr)/sizeof(arr[0]);   //5
    int COL_SIZE = sizeof(arr[0])/sizeof(arr[0][0]);

    int count=1;
    for (int i=0; i<ROW_SIZE-1; i++)
    {
        for (int j=0; j<COL_SIZE-1; j++)
            arr[i][j] = count++;
    }


    for (int i=0; i<ROW_SIZE-1; i++)
    {
        for (int j=0; j<COL_SIZE-1; j++)
        {
            int col = j;
            arr[ROW_SIZE-1][col] += arr[i][j];
            arr[ROW_SIZE-1][COL_SIZE-1] += arr[i][j];

            arr[i][COL_SIZE-1] += arr[i][j];
            arr[ROW_SIZE-1][COL_SIZE-1] += arr[i][j];
        }
    }

    for (int i=0; i<5; i++)
    {
        for (int j=0; j<6; j++)
            printf("%3d ", arr[i][j]);
        printf("\n");
    }

	return 0;
}
#endif

/***********************************************************/
// [14-BJ2738] 
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{
    int N, M;
    scanf("%d %d", &N, &M);

    int arr1[N][M];
    int arr2[N][M];

    for (int i=0; i<N; i++)
        for (int j=0; j<M; j++)
            scanf("%d", &arr1[i][j]);

    for (int i=0; i<N; i++)
        for (int j=0; j<M; j++)
            scanf("%d", &arr2[i][j]);


    for (int i=0; i<N; i++)
    {
        for (int j=0; j<M; j++)
            printf("%d ", arr1[i][j]+arr2[i][j]);
        printf("\n");
    }


	return 0;
}
#endif

/***********************************************************/
// [14-BJ2566] 
/***********************************************************/

#if 1
#include <stdio.h>

int find_max(int *pa, int size);

int main(void)
{
    int arr[9][9];
    int max1[9];
    int max;
    int max2;

    for (int i=0; i<9; i++)
        for (int j=0; j<9; j++)
            scanf("%d", &arr[i][j]);

    max2 = arr[0][0];
    for (int i=0; i<9; i++)
    {
        max1[i] = arr[i][find_max(arr[i], 9)];
        if (max2<max1[i]) max2 = i;
    }

    max = find_max(max1, 9);
    printf("%d\n", max1[max]);
    printf("%d %d\n", max, max2);

	return 0;
}

int find_max(int *pa, int size)
{
    int max_index=0;
    for (int i=0; i<size; i++) max_index = pa[i]>pa[max_index] ? i : max_index;

    return max_index;
}


#endif

/***********************************************************/
// [10-0] title
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{

	return 0;
}
#endif

/***********************************************************/
// [10-0] title
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{

	return 0;
}
#endif