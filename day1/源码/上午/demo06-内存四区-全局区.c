#include "stdlib.h"
#include "string.h"
#include "stdio.h"


//c++±‡“Î∆˜”≈ªØ
char *getStr1()
{
	char *p = "abcd1";
	return p;
}

char *getStr2()
{
	char *p = "abcd1";
	return p;
}



void main61(void)
{
	int a = 0;
	char *p1 = NULL;
	char *p2 = NULL;
	char *p3 = NULL;
	p3 = (char *)malloc(100);
	p1 = getStr1();
	p2 = getStr2();

	printf("getStr2():%s....\n", getStr2());
	printf("p1:%d....\n", p1);
	printf("p2:%d....\n", p2);
	system("pause");
}


char *getStr3()
{
	char buf[100];
	memset(buf, 0, sizeof(buf));
	strcpy(buf, "abcd1");
	return buf;
}

void main(void)
{

	printf("getStr3():%s\n", getStr3());
	
	system("pause");
}