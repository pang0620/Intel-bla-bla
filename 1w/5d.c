/***********************************************************/
// [9-1] checking a variable's memory address
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{
    int a;  //4byte
    double b;   //8byte
    char c; //1byte

    printf("a의 주소: %u\n", &a);
    printf("b의 주소: %u\n", &b);
    printf("c의 주소: %u\n", &c);

	return 0;
}
#endif

/***********************************************************/
// [9-2] declare & initialize pointers
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{
    int a;
    int *pa = &a;   //holds a's address.

    printf("pa의 값: %a\n", pa);    //&a address
    a = 10;
    printf("a의 값: %d%t,\n", a);
    *pa = 20;
    printf("*pa의 값: %d%t,\n", *pa);  //a value 

	return 0;
}
#endif

/***********************************************************/
// [9-3] integer sum & avg via pointers
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{
    int a=10, b=15, sum=0;
    int *pa, *pb, *ps;
    double avg;
    double *pg;

    pa = &a;
    pb = &b;
    ps = &sum;
    pg = &avg;

    printf("a: %d%t,, b: %d%t,\n", *pa, *pb);
    printf("sum: %d%t,\n", *pb = *pa + *pb);
    printf("avg: %.1lf\n", *pg = *pb/2.0);

	return 0;
}
#endif

/***********************************************************/
// [9-4] const pointer
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{
    const int num = 10;
    //이후 num=이나 pnum= 이나 편집 불가능.
    int a=10, b=20;
    const int *pa = &a;

    printf("a: %d%t,\n", *pa);

    pa = &b;
    printf("b: %d%t,\n", *pa);

    pa = &a;
    a = 7;
    printf("a: %d%t,\n", *pa);

    //*pa = 77;
    //printf("a: %d%t,\n", *pa);
    //const pointer는 간접 참조가 불가(대상 변경 불가)

	return 0;
}
#endif

/***********************************************************/
// [9-5] size of address & pointer
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{
    int a;
    double b;
    char c;

    int *pa = &a;
    double *pb = &b;
    char *pc = &c;

    //size of address
    printf("a addr: %d\t, b addr: %d\t, c addr: %d\t(bytes)\n",
        sizeof(&a), sizeof(&b), sizeof(&c));
    //size of pointer
    printf("a pointer: %d\t, b pointer: %d\t, c pointer: %d\t(bytes)\n",
        sizeof(pa), sizeof(pb), sizeof(pc));
    //size of value
    printf("a value: %d\t, b value: %d\t, c value: %d\t(bytes)\n",
        sizeof(*pa), sizeof(*pb), sizeof(*pc));

	return 0;
}
#endif

/***********************************************************/
// [9-6] non-allowed pointer substitution
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{
    int a=10;
    int *pa = &a;
    double *pd;

    pd = pa;

    //double pointer can't hold int type
    printf("%lf\n", *pd);   //value: 10

    //gotta check address range before changing data type
    int *pb;
    pb = pa;
    printf("%d\n", *pa);
    printf("%d\n", *pb);

	return 0;
}
#endif

/***********************************************************/
// [9-7] value swap via pointer
/***********************************************************/

#if 0
#include <stdio.h>

void swap(int *pa, int *pb);

int main(void)
{
    int a = 10, b = 20, temp;
    printf("a: %d, b: %d\n", a, b);


    //swapping
    swap(&a, &b);   // same as swap(pa, pb);
    printf("a: %d, b: %d\n", a, b);

	return 0;
}

void swap(int *pa, int *pb)
{
    int temp = *pa;
    *pa = *pb;
    *pb = temp;
}

#endif

/***********************************************************/
// [9-8] using variable from another function via pointers
/***********************************************************/

#if 0
#include <stdio.h>
void swap(int *pa, int *pb);

int main(void)
{
    int a = 10, b = 20;

    printf("a : %d, b : %d\n", a, b);
    swap(&a, &b);
    printf("a : %d, b : %d\n", a, b);

	return 0;
}

void swap(int *pa, int *pb)
{
    int temp = *pa;
    *pa = *pb;
    *pb = temp;
}
#endif

/***********************************************************/
// [9-challenge] mini align algorithm
/***********************************************************/

#if 0
#include <stdio.h>

void swap(int *pa, int *pb);
void descending_align(int *pa, int *pb, int *pc);

int main(void)
{
    int max, mid, min;
    scanf("%d %d %d", &max, &mid, &min);    //10 20 30

    descending_align(&max, &mid, &min);
    printf("%d %d %d\n", max, mid, min);    //30 20 10

	return 0;
}

void descending_align(int *pa, int *pb, int *pc)
{
    if (*pa<=*pb) swap(pa, pb);
    if (*pb<=*pc) swap(pb, pc);
    if (*pa<=*pb) swap(pa, pb);
}
void swap(int *pa, int *pb)
{
    int temp = *pa;
    *pa = *pb;
    *pb = temp;
}

#endif

/***********************************************************/
// [10-1] integer operation to array name
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{
    int ary[3]; // 4+4+4=12bytes

    //ary == &ary[0]

    printf("%d\n", ary + 0);
    printf("%d\n", &ary[0]);
    printf("%d\n", &ary[1]);
    printf("%d\n", &ary[2]);

    ary[0] = 10;
    *(ary + 1) = 20;
    *(ary + 2) = 30;

    for (int i=0; i<3; i++) {
        printf("%d ", ary[i]);
    }
    printf("\n");

	return 0;
}
#endif

/***********************************************************/
// [10-2] array name-like pointer
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{
    int array[3];
    int *pa = array;    //index 0's address

    *pa = 10;
    *(++pa) = 20;   //why not 4 but 1?
    *(++pa) = 30;

    printf("addr: %d\n", array);
    for (int i=0; i<3; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    printf("배열 전체의 길이: %d\n", sizeof(array));
    printf("포인터의 길이: %d\n", sizeof(sizeof(pa)));

	return 0;
}
#endif

/***********************************************************/
// [10-3] printing values via pointer
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{
    int array[3] = { 1, 2, 3 };
    int *pa = array;

    printf("%d\n", &array[0]);
    printf("%d\n", &array[1]);

    printf("%d\n", pa);
    printf("%d\n", pa+1);
    // not sizeof(int), just 1
    // by compilor I guess?

    for (int i=0; i<3; i++)
    {
        printf("%d ", *(pa++));
        //don't use prefix operators...
        //postfix: check if it's out of addr range
    }
    pa = array;
    printf("\n");

	return 0;
}
#endif

/***********************************************************/
// [10-4] subtraction and relation operation of pointers
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{
    int array[5] = {10, 20, 30, 40, 50};
    int *pa = array;
    int *pb = array + 3;

    pa++;
    printf("pb - pa : %u\n", pb-pa);    // : 2(index)

    //print front one
    printf("%d\n", pa<pb ? *pa : *pb);

    /*
    for (int *i = array; i<i+5; i++) {
        printf("%d ", *i);
    }
    printf("\n");
    */

	return 0;
}
#endif

/***********************************************************/
// [10-5] function dealing with array
/***********************************************************/

#if 0
#include <stdio.h>

void print_array(int *param);

int main(void)
{
    int ary[5] = { 10, 20, 30, 40, 50 };
    print_array(ary);

	return 0;
}

void print_array(int *pa)
{
    for (int i=0; i<5; i++)
    {
        printf("%d ", pa[i]);
    }
    printf("\n");
}


#endif

/***********************************************************/
// [10-6] array function but the size is differed
/***********************************************************/

#if 0
#include <stdio.h>

void print_array(int *pa, int size);

int main(void)
{
    int ary1[5] = {1, 2, 3, 4, 5};
    int ary2[7] = {123, 2356, 457, 4537, 2, 3452, 345};

    print_array(ary1, 5);
    print_array(ary2, 7);

	return 0;
}

void print_array(int *pa, int size)
{
    for (int i=0; i<size; i++)
    {
        printf("%d ", pa[i]);
    }
    printf("\n");
}

#endif

/***********************************************************/
// [10-7] insert value into array
/***********************************************************/

#if 0
#include <stdio.h>

void input_array(int *pa, int size);
void print_array(int *pa, int size);

int main(void)
{
    int ARR_SIZE = 5;
    int A[ARR_SIZE];

    input_array(A, ARR_SIZE);
    print_array(A, ARR_SIZE);

	return 0;
}

void input_array(int *pa, int size)
{
    for (int i=0; i<size; i++) scanf("%d", pa+i);
}

void print_array(int *pa, int size)
{
    for (int i=0; i<size; i++) printf("%d ", pa[i]); printf("\n");
}

#endif

/***********************************************************/
// [10-8] find max
/***********************************************************/

#if 0
#include <stdio.h>
#define ARR_SIZE 5

void input_array(int *pa, int size);
void print_array(int *pa, int size);
int find_max(int *pa, int size);

int main(void)
{
    int ary[ARR_SIZE];
    input_array(ary, ARR_SIZE);
    print_array(ary, ARR_SIZE);

    printf("max: %d\n", find_max(ary, ARR_SIZE));

	return 0;
}

int find_max(int *pa, int size)
{
    int max = -99999999;

    for (int i=0; i<size; i++) max = *(pa+i) > max ? *(pa+i) : max;

    return max;
}

void input_array(int *pa, int size)
{
    for (int i=0; i<size; i++) scanf("%d", &pa[i]);
    //                                      pa+i
}

void print_array(int *pa, int size)
{
    for (int i=0; i<size; i++) printf("%d ", pa[i]); printf("\n");
    //                                      *pa+i
}

#endif

/***********************************************************/
// [10-challenge] lottery 
/***********************************************************/

#if 0
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ARR_SIZE 6

void input_lotto(int *pa, int size);
void print_lotto(int *pa, int size);
void rand_lotto(int *pa, int size);

int main(void)
{
    int arr[ARR_SIZE];

    //input_lotto(arr, ARR_SIZE);
    rand_lotto(arr, ARR_SIZE);
    print_lotto(arr, ARR_SIZE);

	return 0;
}

void rand_lotto(int *pa, int size)
{
    // auto input with digits randomizing logic
    srand(time(NULL));
    for (int i=0; i<size; i++) {
        pa[i] = rand()%99+1;
        for (int j=0; j<i; j++) {
            if (pa[i] == pa[j]) {
                printf("digit already exists: randomizing digits again...\n");
                i=0;
                break;
            }
        }
    }

    // ascending sort part
    for (int i=size-1; i>0; i--)
    {
        for (int j=0; j<i; j++)
        {
            if (pa[j]>pa[j+1])
            {
                int temp = pa[j];
                pa[j] = pa[j+1];
                pa[j+1] = temp;

            }
        }
    }
}

void input_lotto(int *pa, int size)
{
    // manual input with seperate digit check logic
    for (int i=0; i<size; i++)
    {
        printf("Enter value 0%d: ", i+1);
        scanf("%d", &pa[i]);
        for (int j=0; j<i; j++) {
            if (pa[i] == pa[j]) {
                printf("digit already exists: please enter again.\n");
                i--;
                break;
            }
        }
    }
}
void print_lotto(int *pa, int size)
{
    for (int i=0; i<size; i++) 
    {
        printf("%d ", pa[i]);
    }
    printf("\n");

}

#endif

/***********************************************************/
// [10-sort] sort algorithm
/***********************************************************/

#if 1
#include <stdio.h>
#define ARR_SIZE 10

void swap(int *pa, int *pb);
void print_array(int *pa, int size);
void bubble_sort(int *pa, int size);
int find_max(int *pa, int size);
void selection_sort(int *pa, int size);
void binary_search (int *pa, int size, int target);

int main(void)
{
    int arr[ARR_SIZE] = {1, 32, 19, 27, 23, 18, 54, 40, 11, 30};

    printf("origin:\t\t\t");
    print_array(arr, sizeof(arr)/sizeof(int));

    /*
    bubble_sort(arr, sizeof(arr)/sizeof(int));
    printf("bubble sorted:\t\t");
    print_array(arr, sizeof(arr)/sizeof(int));
    */

    selection_sort(arr, sizeof(arr)/sizeof(int));
    printf("selection sorted:\t");
    print_array(arr, sizeof(arr)/sizeof(int));

    binary_search(arr, sizeof(arr)/sizeof(int), 19);

	return 0;
}

void swap(int *pa, int *pb) {
    int temp = *pa;
    *pa = *pb;
    *pb = temp;
}

void print_array(int *pa, int size)
{
    for (int i=0; i<size; i++) printf("%d ", pa[i]); printf("\n");
}

int find_max(int *pa, int size)
{
    int max = pa[0];
    int max_index = 0;

    for (int i=0; i<size; i++)
    {
        if (max < pa[i])
        {
            max = pa[i];
            max_index = i;
        }
    }

    return max_index;
}

void bubble_sort(int *pa, int size)
{
    for (int i=size-1; i>0; i--)
    {
        for (int j=0; j<i; j++)
            if (pa[j]>pa[j+1]) swap(&pa[j], &pa[j+1]);
    }
}

void selection_sort(int *pa, int size)
{
    int max, max_index;

    for (int j=0; j<size-1; j++)
    {
        max = pa[0];
        max_index = 0;
        for (int i=0; i<size-j; i++)
        {
            if (pa[i]>max)
            {
                max = pa[i];
                max_index = i;
            }
        }
        swap(&pa[max_index], &pa[size-(j+1)]);
    }
}

// requires to be sorted already... but who's buying?
void binary_search (int *pa, int size, int target)
{
    int low_index = 0;
    int high_index = size-1;
    int mid_index = (low_index + high_index)/2;

    // while goes 10000 times -> break;
    int count=0;

    // if there's no target:
    // possibility of low>high

    while (low_index <= high_index)
    {
        if (pa[mid_index] > target)
        {
            high_index = mid_index-1;
            mid_index = (low_index + high_index)/2;
        }
        else if (pa[mid_index] < target)
        {
            low_index = mid_index+1;
            mid_index = (low_index + high_index)/2;
        }
        else
        {
            break;
        }
    }
}

#endif