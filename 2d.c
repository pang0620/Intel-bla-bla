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
// [2-3] 제어 문자를 사용한 출력
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
// [3-1] 변수 선언과 사용
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

	printf("변수 a의 값: %d\n", a);
	printf("변수 b의 값: %d\n", b);
	printf("변수 c의 값: %d\n", c);
	printf("변수 da의 값: %.1lf\n", da);
	printf("변수 ch의 값: %c\n", ch);

	return 0;
}
#endif


/***********************************************************/
// [3-2] char형 변수의 사용
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
// [3-3] 여러가지 정수형 변수
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
// [3-4] unsigned를 잘못 사용한 경우
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
// [3-5] 유효 숫자 확인
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
// [3-6] char 배열에 문자열 저장
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{
	char fruit[7] = "orange";
	// 끝에 null문자가 들어가야 하니 문자열 길이+1 이상으로 크기를 지정

	printf("%s\n", fruit);

	return 0;
}
#endif


/***********************************************************/
// [3-7] char 배열에 문자열 복사
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
// [3-8] const를 사용한 변수
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

	printf("%.0lf만원\n", tax);

	return 0;
}
#endif


/***********************************************************/
// [3-확인문제] 2  
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
// [3-확인문제] 3
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
// [3-9] scanf 함수를 사용한 키보드 입력
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
// [3-10] scanf 함수를 사용한 연속 입력
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
// [3-11] 문자와 문자열 입력
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
// [3-확인문제] 2
/***********************************************************/

// 1: fruit
// 2. &cnt

/***********************************************************/
// [3-확인문제] 3
/***********************************************************/

// scanf("%c", &ch);
// printf("%d", ch);

/***********************************************************/
// [4-1] 타이틀
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
// 백준 10172
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
// [4-2] 나누기, 나머지 연산자
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
// [4-2-실습] 못들었다. 자판가ㅣ.
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{
	int input = 770;
	int price = 100;
	int change = input - price;

	printf("잔돈: %d원\n", change);
	printf("500: %d개\n", change / 500);
	printf("100: %d개\n", (change % 500)/100);
	change = change % 100;
	printf("50: %d개\n", change / 50);
	printf("10: %d개\n", (change % 50)/10);

	return 0;
}
#endif


/***********************************************************/
// [4-2-실습2] 시간 변환 
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
// [4-3] 증감 연산자의 연산
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
// [4-4] 타이틀
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
// [4-5] 관계 연산자
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
// [4-6] 논리 연산의 결과
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
// [4-확인] avg
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{
	int kor, eng, mat;

	scanf("%d %d %d", &kor, &eng, &mat);
	printf("sum: %d점\navg: %d점", kor + eng + mat, (kor + eng + mat) / 3);

	return 0;
}
#endif


/***********************************************************/
// [4-4] 형변환연산자
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
// [4-9] sizeof 연산자
// 5-8 어디감
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
	printf("char: %d\n", sizeof(char));		//char:1, "뷁" / 'a': 4

	return 0;
}
#endif


/***********************************************************/
// [4-10] 복합 대입 연산자
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
	menu % 2 == 0 ? strcpy(lunch_menu, "짜장") : strcpy(lunch_menu, "짬뽕");	//string.h 없어도 되네

	printf("%s", lunch_menu);

	return 0;
}
#endif


/***********************************************************/
// [4-12-큰 값] 
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{
	int A, B;
	scanf("%d", &A);
	scanf("%d", &B);

	printf("큰 수: %d\n", A > B ? A : B);

	return 0;
}
#endif


/***********************************************************/
// [4-12] 절댓값
/***********************************************************/

#if 0
#include <stdio.h>

int main(void)
{
	int A;
	scanf("%d", &A);

	printf("절댓값: % d\n", A > 0 ? A : -A);

	return 0;
}
#endif