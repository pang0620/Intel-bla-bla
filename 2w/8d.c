/***********************************************************/
// [15-1] double pointer
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{
    int a = 10;
    int *pi = &a;
    int **ppi = &pi;
    int ***pppi = &ppi;

    printf("%d\n", a);

    printf("%d\n", pi);
    printf("%d\n", *pi);

    printf("%d\n", ppi);
    printf("%d\n", *ppi);
    printf("%d\n", **ppi);

    printf("%d\n", pppi);
    printf("%d\n", *pppi);
    printf("%d\n", **pppi);
    printf("%d\n", **pppi);

	return 0;
}
#endif

/***********************************************************/
// [15-2] string exchange with double pointer
/***********************************************************/

#if 0
#include <stdio.h>

void swap_ptr(char **pa, char **pb);

int main(void)
{
    char *pa = "asdf";
    char *pb = "qwer";

    printf("pa -> %s\n", pa);
    printf("pb -> %s\n", pb);

    swap_ptr(&pa, &pb);

    printf("pa -> %s\n", pa);
    printf("pb -> %s\n", pb);

    return 0;
}

void swap_ptr(char **ppa, char **ppb)
{
    char *temp = ppa;
    *ppa = *ppb;
    *ppb = temp;
}


#endif

/***********************************************************/
// [15-3] pointer array
/***********************************************************/

#if 0
#include <stdio.h>

void print_str(char **ppa, int size);

int main(void)
{
    char *animal = { "dog" };
    printf("%s\n", animal);

    char *animals[4] = { "dog", "rabbit", "cat", "hippo"};
    print_str(animals, 4);

	return 0;
}

void print_str(char **ppa, int size)
{
    for (int i=0; i<size; i++) printf("%s ", ppa[i]); printf("\n");
    printf("%s ", *(ppa+0));
    printf("%s ", *(ppa+1));
    printf("%s ", *(ppa+2));
    printf("%s\n", *(ppa+3));
}
#endif

/***********************************************************/
// [15-4] addr of array
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{
    int array[5];
    printf("%u\n", array);  // returns [0]'s addr
    printf("%u\n", &array); // returns its value: [0]'s addr
    printf("%u\n", array+1);// returns [1]'s addr

	return 0;
}
#endif

/***********************************************************/
// [15-5] 5x5 array with pointer
/***********************************************************/

#if 0
#include <stdio.h>

void print_array(int **ppa);

int main(void)
{
    int arr[5][5];
    int count=1;

    for (int i=0; i<5; i++)
        for (int j=0; j<5; j++)
            arr[i][j] = count++;

    print_array(arr);

	return 0;
}

void print_array(int **ppa)
{
    int (*pa)[5] = ppa;

    // this won't work
    for (int i=0; i<5; i++)
    {
        for (int j=0; j<5; j++)
            printf("%3d ", pa[i]);
        printf("\n");
    }
}

#endif

/***********************************************************/
// [15-7] call function with void pointer(function pointer)
/***********************************************************/

#if 0
#include <stdio.h>

int sum((int a, int b));

int main(void)
{
    int result;
    result = sum(10,20);
    printf("%d\n", result);

    int (*fp)((int a, int b));
    fp = sum;   //function name itself is its address

    int result2 = fp(20, 30);
    printf("%d\n", result2);

    int result3 = (*sum)(30, 40);
    printf("%d\n", result3);

	return 0;
}

int sum(int a, int b) { return a+b; }

#endif

/***********************************************************/
// [15-8] neat calc program
/***********************************************************/

#if 0
#include <stdio.h>

int sum(int a, int b);
int mul(int a, int b);
int max(int a, int b);
int min(int a, int b);
int abs(int a, int b);
int sub(int a, int b);
void func(int (*fp)(int a, int b));

int main(void)
{
    // UI
    // View 단 -> main에 있어도 됨
    printf("1 두 정수의 합\n");
    printf("2 두 정수의 곱\n");
    printf("3 두 정수 중 큰 값\n");
    printf("4 두 정수 중 작은 값\n");
    printf("5 정수의 절댓값\n");
    printf("6 두 정수의 차\n");

    int sel; 
    while (1)
    {
        printf("원하는 연산을 선택: ");
        scanf("%d", &sel);

        void func(int (*fp)(int a, int b));
        switch (sel)
        {
        case 1: func(sum);
            break;
        case 2: func(mul);
            break;
        case 3: func(max);
            break;
        case 4: func(min);
            break;
        case 5: func(abs);
            break;
        case 6: func(sub);
            break;
        default:
            printf("실행 종료.\n");
            return -1;
        }
    }

	return 0;
}

int sum(int a, int b) { return a+b; }
int mul(int a, int b) { return a*b; }
int max(int a, int b) { return a>b ? a : b; }
int min(int a, int b) { return a<b ? a : b; }
int abs(int a, int b) { return a>0 ? a : -a; }
int sub(int a, int b) { return a-b; }
void func(int (*fp)(int a, int b))
{
    int a, b;
    printf("두 정수의 값을 입력: ");
    scanf("%d %d", &a, &b);

    int result;
    result = fp(a,b);

    printf("결과: %d\n", result);
}

#endif

/***********************************************************/
// [15-9] void pointer print 
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{
    int a = 10;
    double b = 3.14;

    void *vp;
    vp = &a;
    printf("%d\n", *((int *)vp));

    vp = &b;
    printf("%.2lf\n", *((double *)vp));

    return 0;
}
#endif

/***********************************************************/
// [16-1] create array via  dynamic allocation
/***********************************************************/

#if 0
#include <stdio.h>
#include <stdlib.h> //malloc(), free(), exit()

int main(void)
{
    int N;
    printf("Enter size: ");
    scanf("%d", &N);

    // void *vp = malloc(~);
    int *array = (int *)malloc(N * sizeof(int));
    if (array == NULL)
    {
        printf("not enough memory\n");
        exit(1);
    }

    for (int i = 0; i < N; i++) array[i] = i+1;
    for (int i = 0; i < N; i++) printf("%3d", array[i]);
    printf("\n");

    free(array);
    return 0;
}
#endif

/***********************************************************/
// [16-2] calloc and realloc
/***********************************************************/

#if 0
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int N;
    printf("Enter arr size: ");
    scanf("%d", &N);

    int *arr = (int *)calloc(N, sizeof(int));
    if (arr == NULL) exit(1);

    for (int i=0; i<N; i++) arr[i]=i+1;
    for (int i=0; i<N; i++) printf("%d ", arr[i]); printf("\n");

    int M;
    printf("Enter arr size again: ");
    scanf("%d", &M);

    arr = (int *)realloc(arr, M * sizeof(int));
    if (arr == NULL) exit(1);

    for (int i = 0; i < M; i++) arr[N + i] = i + 1;
    for (int i=0; i<M; i++) printf("%d ", arr[i]); printf("\n");

    free(arr);
	return 0;
}
#endif

/***********************************************************/
// [16-4] dynamic allocation for 3 strings
/***********************************************************/

#if 0
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
    char *str[3];
    char temp[46] = {'\n', };

    for (int i=0; i<3; i++)
    {
        gets(temp);
        str[i] = (char *)malloc(strlen(temp) + 1); // +1 for '\0'
        if (str[i]==NULL)
        {
            printf("not enough memory\n");
            exit(1);
        }
        strcpy(str[i], temp);
    }

    for (int i = 0; i < 3; i++)
        printf("%s ", str[i]);
    printf("\n");

    for (int i = 0; i < 3; i++)
        free(str[i]);
    return 0;
}
#endif

/***********************************************************/
// [16-5] input string but dunno when it ends
/***********************************************************/

#if 0
#include <stdio.h>
#include <stdlib.h> //malloc(), free()
#include <string.h> //strlen(), strcpy()

void print_array(char **ppa);

int main(void)
{
    char *str[21] = {NULL};  //+1 for '\0'
    char temp[46];

    for (int i=0; i<20; i++)
    {
        printf("Enter string: ");
        //gets(temp);
        scanf("%s", temp);
        if (strcmp(temp, "end") == 0) break;
        str[i] = (char *)malloc(strlen(temp)+1);    //+1 for '\0'
        if (str[i] == NULL) exit(1);
        strcpy(str[i], temp);
    }

    print_array(str);

    for (int i = 0; i < 20; i++)
        if (str[i] != NULL) free(str[i]);
    return 0;
}

void print_array(char **ppa)
{
    while (*ppa) printf("%s ", *ppa++);
    printf("\n");
}
#endif

/***********************************************************/
// [16-6] printing command prompt argument
/***********************************************************/

#if 0
#include <stdio.h>
#include <stdlib.h>

// argument count/vector
int main(int argc, char **argv)
{
    int size = atoi(argv[1]);

    for (int i=0; i<size; i++)
    {
        for (int j=0; j<i+1; j++)
            printf("*");
        printf("\n");
    }

    /*
    printf("Hello World!\n");
    for (int i=0; i<argc; i++)
    {
        printf("%s ", argv[i]);
    }
    */

    printf("\n");
	return 0;
}
#endif

/***********************************************************/
// [17-1] struct
/***********************************************************/

#if 0
#include <stdio.h>

//declare struct
struct contact
{
    //define member
    char* name;
    int age;
    char* mbti;
};

struct student
{
    char ch1;
    short num;
    char ch2;
    int score;
    char ch3;
    double grade;
};

struct exam
{
    char c1;
    int num;
};

int main(void)
{
    //intiallize instance
    struct contact p1;
    struct contact p2;
    struct contact p3;

    struct student s1;
    struct exam e1;

    p1.name = "kim";
    p1.age = 43;
    p1.mbti = "AAAA";

    p2.name = "lee";
    p2.age = 24;
    p2.mbti = "BBBB";

    p3.name = "park";
    p3.age = 38;
    p3.mbti = "CCCC";

    printf("이: %4s, 나: %3d, 연: %4s\n", p1.name, p1.age, p1.mbti);
    printf("이: %4s, 나: %3d, 연: %4s\n", p2.name, p2.age, p2.mbti);
    printf("이: %4s, 나: %3d, 연: %4s\n", p3.name, p3.age, p3.mbti);

    printf("size of s1: %lu\n", sizeof(s1));
    printf("size of e1: %lu\n", sizeof(e1));

	return 0;
}
#endif

/***********************************************************/
// [17-2] member's data type
/***********************************************************/

#if 0
#include <stdio.h>
#include <string.h> // strcpy
#include <stdlib.h> // malloc

struct student
{
    int id;
    double grade;
};

struct profile
{
    char *name[20];
    int age;
    double height;
    char *info;
    struct student st;
};

int main(void)
{
    struct profile p1;
    char temp[80];

    strcpy(p1.name, "asdf");
    p1.age = 12;
    p1.height = 1.1;
    gets(temp);
    p1.info = (char *)malloc(strlen(temp)+1);
    strcpy(p1.info, temp);
    p1.st.id = 12425234;
    p1.st.grade = 22.2;

    printf("name: %s\n", p1.name);
    printf("age: %d\n", p1.age);
    printf("height: %.1lf\n", p1.height);
    printf("name: %s\n", p1.info);
    printf("id: %d\n", p1.st.id);
    printf("grade: %.1lf\n", p1.st.grade);

	return 0;
}
#endif

/***********************************************************/
// [17-3] max grade print
/***********************************************************/

#if 0
#include <stdio.h>

struct student
{
    int id;
    char name[20];
    double grade;
};

int main(void)
{
    int *temp;
    struct student  s1 = {315, "asdf", 2.4},
                    s2 = {314, "egr", 3.7},
                    s3 = {322, "sdagc", 4.5};

    /*
    int max = s1.grade;
    max = s3.grade>max ? 2 : (s1.grade>s2.grade ? 0 : 1);

    switch (max)
    {
        case 0:
            printf("id: %d, name: %s, grade: %.1lf\n",
                s1.id, s1.name, s1.grade);
        case 1:
            printf("id: %d, name: %s, grade: %.1lf\n",
                s2.id, s2.name, s2.grade);
        case 2:
            printf("id: %d, name: %s, grade: %.1lf\n",
                s3.id, s3.name, s3.grade);
    }
    */
   
    // struct is an data type too
    struct student max = s1;
    if (s2.grade > max.grade) max = s2;
    if (s3.grade > max.grade) max = s3;

    printf("id: %d, name: %s, grade: %.1lf\n",
        max.id, max.name, max.grade);


	return 0;
}
#endif

/***********************************************************/
// [17-6] struct pointer & non-direct member approach operator
/***********************************************************/

#if 0
#include <stdio.h>

struct score
{
    int kor;
    int eng;
    int math;
};

int main(void)
{
    struct score s1 = {70, 80, 90};
    struct score *ps = &s1;


    printf("kor: %d\n", s1.kor);
    printf("eng: %d\n", (*ps).eng);
    printf("math: %d\n", ps->math); // 간접 멤버 접근 연산자

    return 0;
}
#endif

/***********************************************************/
// [17-7] title
/***********************************************************/

#if 0
#include <stdio.h>
struct student
{
    int id;
    char name[20];
    double grade;
};

void print_list(struct student *lp, int size);

int main(void)
{
    struct student students[3] =
    {
        {315, "asdf", 2.4},
        {314, "egr", 3.7},
        {322, "sdagc", 4.5}
    };

    print_list(students, 3);

    return 0;
}

void print_list(struct student *lp, int size)
{
    for (int i=0; i<3; i++)
        printf("id: %d, name: %5s, grade: %.1lf\n",
            // add i to "address" value
               lp[i].id, (*(lp+i)).name, (lp+i)->grade);
}

#endif