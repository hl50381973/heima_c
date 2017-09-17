#include "stdlib.h"
#include "stdio.h"
#include "string.h"
typedef struct _A
{
	int a ;
};

//结构体的定义
typedef struct _AdvTeacher
{
	char *name; //4
	int age2 ;
	char buf[32];  //32
	int age; //4
}Teacher ; 


void main2()
{
	int i = 0;
	Teacher * p = NULL;
	p = p - 1;
	p = p - 2;
	p = p +2;
	p = p -p;

	i = (int) (&(p->age)); //1逻辑计算在cpu中，运算
	printf("i:%d \n", i);

		//&属于cpu的计算，没有读写内存，所以说没有coredown


	system("pause");
}

//-> .
void main()
{
	int i = 0;
	i = (int )&(((Teacher *)0)->age );

	
	printf("i:%d \n", i);

	//&属于cpu的计算，没有读写内存，所以说没有coredown -->


	system("pause");
}