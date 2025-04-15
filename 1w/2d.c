#define _CRT_SECURE_NO_WARNINGS

/***********************************************************/
// [0-0] print Hello World
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{
	printf("Hello World!\n");

	return 0;
}
#endif


/***********************************************************/
// [2-3] ���� ���ڸ� ����� ���
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{
	printf("GooT\bd\tchance\n");
	printf("Cow\rW\a\n");

	return 0;
}
#endif


/***********************************************************/
// [3-1] ���� ����� ���
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{
	int a;
	a = 10;

	int b, c;
	double da;
	char ch;
	
	b = a;
	c = a + 20;
	da = 3.5;
	ch = 'A';

	printf("���� a�� ��: %d\n", a);
	printf("���� b�� ��: %d\n", b);
	printf("���� c�� ��: %d\n", c);
	printf("���� da�� ��: %.1lf\n", da);
	printf("���� ch�� ��: %c\n", ch);

	return 0;
}
#endif


/***********************************************************/
// [3-2] char�� ������ ���
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{
	char ch1 = 'A';
	int ch2 = 65;

	printf("%c %d\n", ch1, ch1);
	printf("%c %d\n", ch2, ch2);

	return 0;
}
#endif


/***********************************************************/
// [3-3] �������� ������ ����
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{
	short menu = 10000;
	int lotto = 4000000000;
	long people = 50000000;
	long long world = 7000000000;

	short sh = 32768;

	printf("%d\n", sh);
	
	printf("%d\n", menu);
	printf("%d\n", lotto);
	printf("%ld\n", people);
	printf("%lld\n", world);

	return 0;
}
#endif


/***********************************************************/
// [3-4] unsigned�� �߸� ����� ���
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{
	unsigned int a;

	a = 4294967295;
	printf("%u\n", a);

	a = -1;
	printf("%u\n", a);

	return 0;
}
#endif


/***********************************************************/
// [3-5] ��ȿ ���� Ȯ��
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{
	float ft = 1.212341234123412341234;
	double db= 1.212341234123412341234;
	long double ldb = 1.212341234123412341234;

	printf("%.100f\n", ft);
	printf("%.100lf\n", db);
	printf("%.100llf\n", ldb);

	return 0;
}
#endif


/***********************************************************/
// [3-6] char �迭�� ���ڿ� ����
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{
	char fruit[7] = "orange";
	// ���� null���ڰ� ���� �ϴ� ���ڿ� ����+1 �̻����� ũ�⸦ ����

	printf("%s\n", fruit);

	return 0;
}
#endif


/***********************************************************/
// [3-7] char �迭�� ���ڿ� ����
/***********************************************************/

#if 0
#include <stdio.h>
#include <string.h>

int main(void)
{
	char fruit[20] = "banana";

	strcpy(fruit, "choco");	// -> "fruitchoco"
	printf("%s\n", fruit);

	return 0;
}
#endif


/***********************************************************/
// [3-8] const�� ����� ����
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{
	int income = 0;
	double tax;

	income = 400;
	const double tax_rate = 0.065;
	tax = income * tax_rate;

	printf("%.0lf����\n", tax);

	return 0;
}
#endif


/***********************************************************/
// [3-Ȯ�ι���] 2  
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{
	int a = 0;	//0

	a = a + 1;	//1
	a = a + 2;	//3
	a = a + 3;	//6
	printf("a : %d", a);

	return 0;
}
#endif


/***********************************************************/
// [3-Ȯ�ι���] 3
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{
	int kor = 70;
	int eng = 80;
	int mat = 90;

	int tot = kor + eng + mat;

	printf("kor: %d, eng: %d, mat: %d\n", kor, eng, mat);
	printf("total: %d", tot);

	return 0;
}
#endif


/***********************************************************/
// [3-9] scanf �Լ��� ����� Ű���� �Է�
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{
	int age;
	printf("enter age: ");
	scanf("%d", &age);

	printf("age: %d\n", age-1);

	return 0;
}
#endif


/***********************************************************/
// [3-10] scanf �Լ��� ����� ���� �Է�
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{
	int age;
	double height;
	printf("enter age, height: ");
	scanf("%d %lf", &age, &height);

	printf("age: %d, height: %.1lf\n", age, height);

	return 0;
}
#endif


/***********************************************************/
// [3-11] ���ڿ� ���ڿ� �Է�
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{
	char grade;
	char fruit[20];

//	printf("Enter grade: ");
	scanf("%c", &grade);
//	printf("Enter fruit: ");
	scanf("%s", fruit);

	printf("Grade: %c\n\n", grade);
	printf("Fruit: %s\n\n", fruit);

	return 0;
}
#endif


/***********************************************************/
// [3-Ȯ�ι���] 2
/***********************************************************/

// 1: fruit
// 2. &cnt

/***********************************************************/
// [3-Ȯ�ι���] 3
/***********************************************************/

// scanf("%c", &ch);
// printf("%d", ch);

/***********************************************************/
// [4-1] Ÿ��Ʋ
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{
	int a, b;
	a = 10; b = 20;
	
	printf("%d + %d = %d\n", a, b, a + b);
	printf("%d - %d = %d\n", a, b, a - b);
	printf("%d * %d = %d\n", a, b, a * b);
	printf("%d\n", -a);

	return 0;
}
#endif


/***********************************************************/
// ���� 10172
/***********************************************************/

#if 0
#include <stdio.h>

int main() {
	printf("|\\_/|\n");
	printf("|q p|   /\}\n");
	printf("\( 0 \)\"\"\"\\\n");
	printf("|\"\^\"\`    |\n");
	printf("||_/\=\\\\__|\n");

	return 0;
}
#endif


/***********************************************************/
// [4-2] ������, ������ ������
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{
	double apple;
	int banana;
	int orange;
	
	apple = 5.0 / 2.0;
	banana = 5 / 2;
	orange = 5 % 2;

	printf("%lf\n", apple);
	printf("%d\n", banana);
	printf("%d\n", orange);

	return 0;
}
#endif


/***********************************************************/
// [4-2-�ǽ�] �������. ���ǰ���.
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{
	int input = 770;
	int price = 100;
	int change = input - price;

	printf("�ܵ�: %d��\n", change);
	printf("500: %d��\n", change / 500);
	printf("100: %d��\n", (change % 500)/100);
	change = change % 100;
	printf("50: %d��\n", change / 50);
	printf("10: %d��\n", (change % 50)/10);

	return 0;
}
#endif


/***********************************************************/
// [4-2-�ǽ�2] �ð� ��ȯ 
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{
	int time = 7533;
	int h, m, s;

	h = time / 3600;
	m = (time % 3600) / 60;
	s = time % 60;

	printf("%d:%d:%d", h, m, s);

	return 0;
}
#endif


/***********************************************************/
// [4-3] ���� �������� ����
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{
	int a = 10;
	int b = 10;

	printf("%d, %d", ++a, --b);

	return 0;
}
#endif


/***********************************************************/
// [4-4] Ÿ��Ʋ
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{
	int a = 5;
	int b = 5;
	int prefix, postfix;

	prefix = (++a) * 3;
	postfix = (b++) * 3;

	printf("%d, %d\n", prefix, postfix);	//18 15
	printf("%d, %d\n", a, b);

	return 0;
}
#endif


/***********************************************************/
// [4-5] ���� ������
/***********************************************************/

#if 0
#include <stdio.h>
#include <string.h>

int main(void)
{
	int a = 10, b = 20;

	char str[10] = "asdf";

	printf("%d>%d: %d\n", a, b, a > b);	//0: false
	printf("%d<%d: %d\n", a, b, a < b);	//!0: true
	printf("%d>=%d: %d\n", a, b, a >= b);	//0: false
	printf("%d<=%d: %d\n", a, b, a <= b);	//!0: true
	printf("%d==%d: %d\n", a, b, a == b);	//0: false
	printf("%d!=%d: %d\n", a, b, a != b);	//!0: true

	printf("%d\n", strcmp(str, str));	//0: true, false: -1?
	printf("%d\n", strcmp(str, "asdf"));	//0: true, false: -1?
	printf("%d\n", strcmp("asdf", "asdf"));	//0: true, false: -1?

	return 0;
}
#endif


/***********************************************************/
// [4-6] �� ������ ���
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{
	int a = 30;
	printf("(a>30) && (a<20): %d\n", a > 30) && (a < 20);	//0
	printf("(a<10) || (a>20): %d\n", (a < 10) || (a > 20));	//1	
	printf("!(a>=30): %d\n", a >= 30);						//1

	return 0;
}
#endif


/***********************************************************/
// [4-Ȯ��] avg
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{
	int kor, eng, mat;

	scanf("%d %d %d", &kor, &eng, &mat);
	printf("sum: %d��\navg: %d��", kor + eng + mat, (kor + eng + mat) / 3);

	return 0;
}
#endif


/***********************************************************/
// [4-4] ����ȯ������
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{
	int a = 20, b = 3;

	printf("%lf\n", (double)a /b);

	double result = (double)a /b;
	printf("%lf\n", result);

	return 0;
}
#endif


/***********************************************************/
// [4-9] sizeof ������
// 5-8 ���
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{
	int a = 10;
	double b = 3.14;

	printf("int: %d\n", sizeof(a));
	printf("double: %d\n", sizeof(b));
	printf("const int: %d\n", sizeof(100));
	printf("condition result: %d\n", sizeof(1.5+3.4));
	printf("char: %d\n", sizeof(char));		//char:1, "��" / 'a': 4

	return 0;
}
#endif


/***********************************************************/
// [4-10] ���� ���� ������
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{
	int a = 10;

	age += 1;


	return 0;
}
#endif


/***********************************************************/
// [4-11] comma operator
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{
	int a = 10, b = 20;
	int result;

	result = (++a, ++b);

	printf("%d\n", result);

	return 0;
}
#endif


/***********************************************************/
// [4-12] conditino operator
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{
	int menu = 58;
	char lunch_menu[20];
	menu % 2 == 0 ? strcpy(lunch_menu, "¥��") : strcpy(lunch_menu, "«��");	//string.h ��� �ǳ�

	printf("%s", lunch_menu);

	return 0;
}
#endif


/***********************************************************/
// [4-12-ū ��] 
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{
	int A, B;
	scanf("%d", &A);
	scanf("%d", &B);

	printf("ū ��: %d\n", A > B ? A : B);

	return 0;
}
#endif


/***********************************************************/
// [4-12] ����
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{
	int A;
	scanf("%d", &A);

	printf("����: % d\n", A > 0 ? A : -A);

	return 0;
}
#endif