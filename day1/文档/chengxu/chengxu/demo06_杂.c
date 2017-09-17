#include "stdio.h"
#include "stdlib.h"
#include "string.h"

int main61()
{

	int a1 = 1;
	int b1 = 2;
	int *p1 = NULL;
	p1 = &a1;

	//*p1放在等号的左边，取值
	b1 = *p1;

	printf("*p1:%d\n", *p1);

	printf("hello.....\n");
	getchar();
	return 0;
}

void main62()
{
	int a[5] = {1, 3, 4, 5, 6};
	printf("a:%d &a:%d \n", a, &a);
	printf("a+1:%d &a+1:%d \n", a+1, &a+1);
	system("pause");
	
}

void main63()
{
	int a1 = 1;
	int b1 = 2;
	int *p1 = NULL;
	p1 = &a1;

	//*p1放在等号的左边，取值
	b1 = *p1;

	printf("&b1:%d\n", &b1);
	*((int *)(1245012)) = 3;
	printf("%d\n", b1);
	//printf("*p1:%d\n", *p1);

	printf("hello.....\n");
	system("pause");
}

char main64()
{
	return 'a';
}

void main()
{
	printf("%d %d %d", sizeof(main61), sizeof(main62()), main64);
	system("pause");
}