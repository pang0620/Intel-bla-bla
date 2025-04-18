/***********************************************************/
// [17-9] self-referencing structure
/***********************************************************/

#if 0
#include <stdio.h>

struct list
{
    int num;
    struct list *next;
};

int main(void)
{
    // list: linked list
    struct list a = {10, }, b = {20, }, c = {30, };
    // addr for first value "a"
    // never change head: const
    const struct list *head = &a;

    a.next = &b;
    b.next = &c;

    printf("a, %d , a-> %d\n", a.num, a.next);
    printf("b, %d , b-> %d\n", a.next->num, a.next->next);
    printf("c, %d , c-> %d\n", a.next->next->num, a.next->next->next);

    printf("list all : ");
    struct list *current = head;

    while (current != NULL)
    {
        printf("%d ", current->num);
        current = current->next;
    }
    printf("\n");

    return 0;
}
#endif

/***********************************************************/
// [17-10] union
/***********************************************************/

#if 0
#include <stdio.h>

union data
{
    int i;
    double d;
} weather_data;

int main(void)
{
    // receive data from another device via packet
    // int humidity / double temperature

    char *str = "84,17.1,85,17.2,86,17.3";

    int count=1;
    if (count%2==1)
    {
        weather_data.i = 84;
        count++;
    }
    else
    {
        weather_data.d = 17.1;
        count++;
    }

    weather_data.i;
    weather_data.d;

    return 0;
}
#endif

/***********************************************************/
// [17-11] enumeration *열거
/***********************************************************/

#if 0
#include <stdio.h>
enum discount
{
    NORMAL,
    EARLY = 4000,
    TELECOM = 2000
};

int main(void)
{
    int menu;
    int ticket_price = 14000;

    printf("[1]할인없음 [2]조조 [3]통신사할인\n");
    printf("할인 권종 선택: ");
    scanf("%d", &menu);

    switch (menu)
    {
        case 1: ticket_price -= NORMAL; break;
        case 2: ticket_price -= EARLY; break;
        case 3: ticket_price -= TELECOM; break;
        default: break;
    }

    printf("결제 금액: %d원\n", ticket_price);

    return 0;
}
#endif

/***********************************************************/
// [17-12] data-type redefine by typedef
/***********************************************************/

#if 0
#include <stdio.h>
#include <time.h>

typedef signed int 정수;    //  shortening / alias

struct student
{
    int num;
    double grade;
};
typedef struct student Student;

typedef struct
{
    char name[20];
    int age;
} Profile;

int main(void)
{
    //<time.h>
    clock_t t = clock();

    //구조체 재정의 대문자 국룰
    Student s1 = { 315, 3.7 };
    Profile p1 = {"pang", 27};

    int a = 10;
    정수 b = 20;
    printf("%d %d\n", a, b);

    return 0;
}
#endif

/***********************************************************/
// [18-1] fopen fclose - ERROR
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{
    FILE *fp;
    const char* path = "./a.txt";
    //const char* path = "/Users/pang/Documents/Intel/a.txt";
    printf("opening file... ");

    fp = fopen(path, "w");
    if (fp == NULL)
    {
        printf("NULL\n");
        return -1;
    }
    else printf("done!\n");

    char *words = "C CLEAR!!";
    while (*words) fputc(*words++, fp); fputc('\n', fp);
    
    fclose(fp);
    return 0;
}
#endif

/***********************************************************/
// [18-3-practice] doesn't work
/***********************************************************/

#if 0
#include <stdio.h>
#include <string.h>

int main(void)
{
    FILE *fpa, *fpb, *fpc;
    const char* origin_path = "/Users/pang/Documents/Intel/";

    char path_a[256] = {0, };
    char path_b[256] = {0, };
    char path_c[256] = {0, };
    strcpy(path_a, origin_path);
    strcpy(path_b, origin_path);
    strcpy(path_c, origin_path);
    strcat(path_a, "a.txt");
    strcat(path_b, "b.txt");
    strcat(path_c, "c.txt");

    fpa = fopen(path_a, "r");
    if (fpa == NULL) return 1;

    fpb = fopen(path_b, "r");
    if (fpa == NULL) return 2;

    fpc = fopen(path_c, "w");
    if (fpa == NULL) return 3;

    char temp[256] = {0,};

    char *pt = temp;
    int ch;
    while (1)
    {
        ch = fgetc(fpa);
        *pt++ = ch;
        if (ch==EOF) break;
    }
    pt--;

    while (1)
    {
        ch = fgetc(fpb);
        *pt++ = ch;
        if (ch==EOF) break;
    }
    pt--;
    *pt = '\0';

    pt = temp;
    while(1)
    {
        fputc(*pt, fpc);
        pt++;
        if (*pt == NULL) break;
    }
    fputc('\n', fpc);

    printf("%s\n", temp);

    fclose(fpa);
    fclose(fpb);
    fclose(fpc);
    return 0;
}
#endif

/***********************************************************/
// [18-4,5] stdin, stdout
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{
    int ch;

    /*
    while (1)
    {
        ch = getchar();
        if (ch == EOF) break;
        putchar(ch);
    }
    */

    while(out)
    {
        ch = fgetc(stdin);
        if (ch == EOF) break;
        fputc(ch, stdout);
    }

    return 0;
}
#endif
/***********************************************************/
// [18-6] text / binary
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{
    FILE *fp;
    const char *path = "./d.txt";

    fp = fopen(path, "wb");
    if (fp==NULL) return 1;

    int arr[10] = {13, 10, 13, 13, 10, 26, 13, 10, 13, 10};

    for (int i=0; i<10; i++)
    {
        fputc(arr[i], fp);
    }

    fclose(fp);

    fp = fopen(path, "rt");
    int ch;
    while (1)
    {
        ch = fgetc(fp);
        if (ch==EOF) break;
        printf("%3d", ch);
        //putc(ch, stdout);
    }
    printf("\n");

    fclose(fp);
    return 0;
}
#endif

/***********************************************************/
// [18-7] a+ mod
/***********************************************************/

#if 0
#include <stdio.h>
#include <string.h>

int main(void)
{
    FILE *fp;
    const char* path = "./music.txt";

    fp = fopen(path, "a+");
    if (fp==NULL) return -1;

    char str[20];
    while (1)
    {
        printf("song title: ");
        scanf("%s", str);

        if (strcmp(str, "end") == 0) break;
        else if (strcmp(str, "list") == 0)
        {
            fseek(fp, 0, SEEK_SET);
            while (1)
            {
                //strlen()+1 for getting \n
                fgets(str, strlen(str)+1, fp);
                if (feof(fp)!=0) break;
                printf("%s", str);
            }
        }
        else fprintf(fp, "%s\n", str);
    }

    fclose(fp);
    return 0;
}
#endif

/***********************************************************/
// [18-8] multiple line in, one line out
/***********************************************************/

#if 0
#include <stdio.h>
#include <string.h>

int main(void)
{
    //a: hello world
    //b: c clear
    const char* path_a = "./a.txt";
    const char* path_b = "./b.txt";
    const char* path_e = "./e.txt";

    FILE *fpa, *fpb, *fpe;
    fpa = fopen(path_a, "r");
    if (fpa == NULL) return 1;
    fpb = fopen(path_b, "r");
    if (fpb == NULL) return 2;
    fpe = fopen(path_e, "w");
    if (fpe == NULL) return 3;

    char str[80];
    char *result = str;

    printf("reading a.txt...");
    while (1)
    {
        result = fgets(str, strlen(str)+1, fpa);
        if (result==NULL) 
        {
            printf("done!\n");
            printf("reading b.txt...");
            while (1)
            {
                result = fgets(str, strlen(str)+1, fpb);
                if (result==NULL) break;
            }
        }
    }

    while (1)
    {
        fputs(result, fpe);
        if (fpe==NULL) break;
    }

    fclose(fpa);
    fclose(fpb);
    fclose(fpe);
    return 0;
}
#endif

/***********************************************************/
// [18-9] fprintf() variant shape
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{
    FILE *fp, *fs;
    const char *path = "./gf.txt";
    const char *path_score = "./score.txt";

    printf("opening gf.txt...");
    fp = fopen(path, "r");
    if (fp==NULL)
    {
        printf("fail\n");
        return 1;
    }
    else printf("done\n");

    printf("opening score.txt...");
    fs = fopen(path_score, "w");
    if (fs==NULL)
    {
        printf("fail\n");
        return 2;
    }
    else printf("done\n");

    char name[20];
    int kor, eng, math;
    int total;
    double avg;

    int result;
    while(1)
    {
        result = fscanf(fp, "%s %d %d %d", name, &kor, &eng, &math);
        if (result == EOF) break;
        total = kor + eng + math;
        avg = total/3.0;
        fprintf(fs, "name: %3s, total: %4d, avg: %.1lf\n", name, total, avg);
    }

    fclose(fp);
    fclose(fs);
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