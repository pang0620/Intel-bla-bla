/***********************************************************/
// [11-1] lowercase
/***********************************************************/

#if 0
#include <stdio.h>

char lowercase(char ch);

int main(void)
{
    printf("%c\n", lowercase('H'));

	return 0;
}

char lowercase(char ch) { return (65<=ch && ch<=90) ? (ch+32) : ch; }
#endif

/***********************************************************/
// [11-2] blank or control symbols
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{
    //string input function ( no split by space )
    while (1)
    {
        char ch;
        // scanf: takes char, string, integer, float
        // there's the char-only function called "getchar", "putchar"
        scanf("%c", &ch);
        if (ch==10) break;
        printf("%c", ch);
    }
    printf("\n");

	return 0;
}
#endif

/***********************************************************/
// [11-3] getchar & putchar
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{
    while (1)
    {
        //same result to 11-2 but efficient
        int ch;
        ch = getchar();
        if (ch == 10) break;
        putchar(ch);
    }
    putchar(10);

	return 0;
}
#endif

/***********************************************************/
// [11-3] scanf with blank?
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{
    int i=0;
    while (i<5)
    {
        char ch;
        scanf(" %c", &ch);
        printf("%c", ch);

        i++;
    }

	return 0;
}
#endif

/***********************************************************/
// [11-4] char input via buffer
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{
    while (1)
    {
        char ch;
        scanf("%c", &ch);   // apple(enter)
        if (ch== '\n') break;
        printf("%c", ch);   //buffer: <apple"\n">, print front 3
    }
    

	return 0;
}
#endif

/***********************************************************/
// [11-5] translate char into ascii code
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{
    int result;
    char ch;

    while (1)
    {
        if (scanf("%c", &ch) == EOF) // == -1
        {
            //win: ^Z, mac: ^D
            printf("\n\nBREAK!!!!!!!!!!\n\n");
            break;
        }
        printf("%d ", ch);
    }


	return 0;
}
#endif

/***********************************************************/
// [11-6] string input with getchar()
/***********************************************************/

#if 0
#include <stdio.h>

void my_getchar(char *str, int size);

int main(void)
{
    char str[7];
    my_getchar(str, 7);
    printf("입력한 문자열: %s\n", str);

	return 0;
}

// takes string
void my_getchar(char *str, int size)
{
    int i;
    for (i=0; i<size-1; i++)
    {
        str[i] = getchar();
        if(str[i] == '\n') 
        {
            break;
            i++;    // ?
        }
    }
    str[i]='\0';
}

#endif

/***********************************************************/
// [11-7] init buffer
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{
    //scanf and getchar shares same buffer
    int num;

    printf("학번 입력: ");
    scanf("%d", &num);

    printf("학점 입력: ");

    //input buffer: initialize it if orak-karak
    //data in buffer ends with \n always
    getchar();

    int grade = getchar();  //better recieve getchar by int


    printf("학번: %d, 학점: %c\n", num, grade);

	return 0;
}
#endif

/***********************************************************/
// [11-challenge] find the longest word
/***********************************************************/

#if 0
#include <stdio.h>

int find_max(int *pa, int size)
{
    int max_index=0;
    for (int i=0; i<size; i++) max_index = pa[i]>pa[max_index] ? i : max_index;

    return max_index;
}

int main(void)
{
    char *str[101];
    int length[10] = {0};
    int count=0;
    int i=0;

    while (1)
    {
        char ch = getchar();
        if (ch =='\n')
        {
            length[i] = count;
            i++;
            count = 0;
            continue;
        }
        else if (ch == EOF) 
        {
            length[i] = count;
            break;
        }
        count++;
    }

    //for (int i=0; i<10; i++) printf("%d ", length[i]); printf("\n");

    printf("%d\n", length[find_max(length, 10)]);

	return 0;
}
#endif

/***********************************************************/
// [12-1] pointer with string
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{
    int array[5] = {1,2,3,4,5};
    int *pa = array;
    //printf("%p\n", array);
    //printf("%p\n", pa);
    //returns same addr

    char fruit[6] = {'a', 'p', 'p', 'l', 'e', '\0'};
    char fruit2[6] = "apple";

    char *pf = fruit;
    char *pf2 = fruit2;

    printf("%p\n", pf);
    printf("%p\n", pf2);
    //returns different addr

	return 0;
}
#endif

/***********************************************************/
// [12-2] using string with pointer
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{
    char drink[80] = "sol's eye";
    char *pd = drink;

    // if *pd!=null: 1, it is null: 0(false)
    while(*pd) printf("%c", *pd++); printf("\n");

	return 0;
}
#endif

/***********************************************************/
// [12-pause] same string const?
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{
    char fruit[6] = { 'a', 'p', 'p', 'l', 'e', '\0'};
    char fruit2[6] = "apple";
    char fruit3[6] = "apple";

    printf("%p\n", fruit);
    printf("%p\n", fruit2);
    printf("%p\n", fruit3);
 
    char *pf = fruit;
    char *pf2 = fruit2;
    char *pf3 = fruit3;

    printf("%p\n", pf);
    printf("%p\n", pf2);
    printf("%p\n", pf3);
    
    /*
        compiler might have chance to
        give exact same memory address for
        two different strings contains same members
    */
 
	return 0;
}
#endif

/***********************************************************/
// [12-3] input string with scanf
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{
    char str[80];
    printf("enter string: ");
    scanf("%s", str);
    printf("%s\n", str);

    printf("enter string: ");
    scanf("%s", str);
    printf("%s\n", str);

	return 0;

    /*
        seems like buffer's something wrong

        enter string: hello world
        hello
        enter string: world
    */
}
#endif

/***********************************************************/
// [12-4] single line string input with gets
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{
    char str[80];
    printf("문자열 입력: ");
    gets(str);

    printf("문자열 출력: ");
    printf("%s\n", str);

	return 0;
}
#endif

/***********************************************************/
// [12-5] safer gets(): fgets()
/***********************************************************/

#if 0
#include <stdio.h>
#include <string.h>

int main(void)
{
    char str[10];
    printf("input : ");
    // prevents memory overflow
    fgets(str, sizeof(str), stdin);

    printf("length: ");
    // substitute 1 when str is written with fgets()
    printf("%d\n", strlen(str)-1);

    printf("length: ");
    printf("%d\n", sizeof(str)/sizeof(char));

	return 0;
}
#endif

/***********************************************************/
// [12-6] breaking gets() with \n
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{
    int age;
    char name[20];

    printf("age? ");
    scanf("%d", &age);

    // resetting buffer: 3 methods
    // book p.358

    //getchar();
    //scanf("%*c"); // 주소 생략 후 char 읽기
    //fgetc(stdin);

    printf("name? ");
    //gets(name);
    fgets(name, sizeof(name), stdin);

    printf("age: %d, name: %s\n", age, name);
    //ends when first input is done

	return 0;
}
#endif

/***********************************************************/
// [12-7] puts fputs
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{
    char str[80] = "apple juice";
    char *ps = "banana";

    // auto \n
    puts(str);
    puts(ps);

    // no \n
    fputs(str, stdout);     // standard output via display via a.out
    fputs(ps, stdout);     

	return 0;
}
#endif

/***********************************************************/
// [12-DIY] implementing gets()
/***********************************************************/

#if 0
#include <stdio.h>

char *mygets(char *ps);

int main(void)
{
    char *str[20];  // insert "apple"

    mygets(str);
    printf("%s\n", str);

	return 0;
}

char *mygets(char *ps)
{
    //int ch;
    while (1) 
    {
        *ps = getchar();
        if (*ps=='\n') break;
        ps++;

        /*
        변수에 저장해서 쓸 수 있으면 서순을 유연하게 가져갈 수 있다?

        ch = getchar();
        *ps++ = ch;
        if (ch == '\n') break;
        */
    }
    *ps = '\0';
}

#endif

/***********************************************************/
// [12-8] strcpy()
/***********************************************************/

#if 0
#include <stdio.h>
#include <string.h>

int main(void)
{
    char arr[20] = "apple";
    printf("%s\n", arr);

    strcpy(arr, "banana");
    printf("%s\n", arr);    //not replace, it changes pointer

    char *ps = arr;
    ps = "kiwi";
    printf("%s\n", ps);
    printf("%s\n", arr);    //so this doesn't work

	return 0;
}
#endif

/***********************************************************/
// [12-9] strncpy
/***********************************************************/

#if 0
#include <stdio.h>
#include <string.h>

int main(void)
{
    char str[80] = "strawberry";   
    strncpy(str, "mango", 5);

    char *ps = "chocolate";
    strncpy(str, ps, 5);

    char str2[80] = "melon_top_100";
    strncpy(&str[5], str2, 5);  //cuts from [0] I guess

    printf("%s\n", str);

	return 0;
}
#endif

/***********************************************************/
// [12-8-DIY] strcpy()
/***********************************************************/

#if 0
#include <stdio.h>

char *my_strcpy(char *pd, char *ps);
char *my_strncpy(char *pd, char *ps, int cut);

int main(void)
{
    char str[80] = "strawberry";

    printf("old :\t%s\n", str);
    printf("new :\t%s\n", my_strcpy(str, "mango"));
    printf("NEW :\t%s\n", my_strncpy(str, "chocolate", 3));

	return 0;
}

char* my_strcpy(char *pd, char *ps)
{
    //reminder: this is cpy but actually makes new string (po)
    char *po = pd;

    while (*pd!='\0' || *ps!='\0')  //of course len(pd)>len(ps)...
        *pd++ = *ps++;
    *pd = '\0';
    
    return po;
}

char *my_strncpy(char *pd, char *ps, int cut)
{
    //reminder: this is cpy but actually makes new string (po)
    char *po = pd;

    //그냥 [cut]에 \0 바꿔치기 이런거로 될 듯?
    int i=0;
    while (*pd!='\0' || *ps!='\0') 
    {
        if (i==cut) break;
        *pd++ = *ps++;
        i++;
    }

    return po;
}
#endif

/***********************************************************/
// [12-10] strcat()
/***********************************************************/

#if 0
#include <stdio.h>
#include <string.h> //strcat(), con-cate-nate

int main(void)
{
    char str[80] = "straw";

    strcat(str, "berry");
    printf("%s\n", str);

    char *pi = " ice cream";
    strcat(str, pi);
    printf("%s\n", str);

    char str2[80] = "cake dessert yogurt";
    strncat(str, str2, 4);
    printf("%s\n", str);

	return 0;
}
#endif

/***********************************************************/
// [12-10-DIY] strcat();
/***********************************************************/

#if 0
#include <stdio.h>

char *my_strcat(char *target, char *str);

int main(void)
{
    char str[80] = "straw";

    my_strcat(str, "berry");

    printf("%s\n", str);

	return 0;
}

char *my_strcat(char *pd, char *ps)
{
    char *po = pd, *pr = po;

    while (*po) po++;
    while (*ps) *po++ = *ps++; *po = '\0';
    // 흠 뭔가 찜찜하네 뒤에 더 있는듯.
    // 조건에 *pd는 필요한가?
    // 뒤에 \0을 쓰느냐마느냐? -> printf에서 처리하나?
    // str[80]초기화 시 전부 \0으로 차게 됨 -> 안넣어도 동작은 함.
    // 근데 넣어라.
    
    return pr;
}

#endif

/***********************************************************/
// [12-11] strlen()
/***********************************************************/

#if 0
#include <stdio.h>
#include <string.h> //strlen()

int main(void)
{
    char str1[80];
    char str2[80];

    printf("두 과일 입력: ");
    scanf("%s %s", str1, str2);

    printf("first:\t%s\n", str1);
    printf("second:\t%s\n", str2);

    if (strlen(str1) > strlen(str2))
        printf("first one is longer\n");
    else
        printf("second one is longer\n");

	return 0;
}
#endif

/***********************************************************/
// [12-11-DIY] strlen()
/***********************************************************/

#if 0
#include <stdio.h>

int my_strlen(char *str);

int main(void)
{
    char str1[80] = "pineapple";
    printf("%d\n", my_strlen(str1));

	return 0;
}

int my_strlen(char *str)
{
    int count=0;
    while (*str++) count++;

    return count;
}

#endif

/***********************************************************/
// [12-12] strcmp()
/***********************************************************/

#if 0
#include <stdio.h>
#include <string.h>

int main(void)
{
    char str1[80] = "apple";
    char str2[80] = "Apple";
    char str3[80] = "zanananana";

    //check if every symbols have same ascii code
    printf("%d\n", strcmp(str1, str2));
    printf("%d\n", strcmp(str1, str3));

    /*
        0: true
        positive: 1's ascii is larger   
        negative: 2's ascii is larger  
        does it calcs ascii-meters?
    */

    char s1[80] = "pear";
    char s2[80] = "peach";
    int result = strncmp(s1, s2, 2);
    switch (result)
    {
        case 1: printf("%s is late in dict.\n", s1); break;
        case -1: printf("%s is late in dict.\n", s2); break;
        case 0: printf("They're the same.\n"); break;
        default: printf("wrong input.\n");

    }

	return 0;
}
#endif

/***********************************************************/
// [12-12-DIY] strcmp()
/***********************************************************/

#if 0
#include <stdio.h>

int my_strcmp(char *s1, char *s2);

int main(void)
{
    char s1[80] = "asdf";
    char s2[80] = "asdf";
    char s3[80] = "asdq";
    char s4[80] = "bqwer";
    char s5[80] = "Zasdf2";
    char s6[80] = "asdqqqq";
    char s7[80] = "as";

    printf("%d %d %d %d %d %d\n", 
    my_strcmp(s1, s2), my_strcmp(s1, s3),
    my_strcmp(s1, s4), my_strcmp(s1, s5),
    my_strcmp(s1, s6), my_strcmp(s1, s7)
    );

	return 0;
}

int my_strcmp(char *s1, char *s2)
{
    if (*s1 > *s2) return 1;
    else if (*s1 < *s2) return -1;

    while (*s1 == *s2) {
        if (*s1++ == '\0' || *s2++ == '\0') return 0;
        // no s2 rule check: s1==s2==null이 성립함.
        // 고로 senseiversion이 더 좋음.
    }
    return 666;

}

#endif

/***********************************************************/
// [12-append] how many digits?
/***********************************************************/

#if 0
#include <stdio.h>

int find_char(char *str, char target);

int main(void)
{
    printf("%d\n", find_char("Hehhhhllo", 'H'));
    printf("%d\n", find_char("HelLLLLlo", 'l'));

	return 0;
}

int find_char(char *str, char target)
{
    int count = 0;
    char *p = str;
    while (*str)
    {
        if (*str++==target) count++;
    }
    return count;
}

#endif

/***********************************************************/
// [12-challenge] dict search
/***********************************************************/

#if 1
#include <stdio.h>
#include <string.h>

int main(void)
{
    /*
        All intracerebral data regarding double pointers
        has been conclusively expunged from memory.
    */

    char AA[3][11];
    char temp[11];

    for (int i=0; i<3; i++) 
        scanf("%10s", AA[i]);

    for (int i=0; i<3-1; i++)
    {
        for (int j=0; j<3-1-i; j++)
        {
            if (strcmp(AA[j], AA[j+1]) > 0)
            {
                strcpy(temp, AA[j]);
                strcpy(AA[j],AA[j+1]);
                strcpy(AA[j+1],temp);
            }
        }
    }

    for (int i=0; i<3; i++) 
        printf("%s", AA[i]);
    printf("\n");

	return 0;
}
#endif
