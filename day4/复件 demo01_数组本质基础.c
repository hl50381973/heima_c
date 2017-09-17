#include "stdlib.h"
#include "string.h"
#include "stdio.h"

int main11()
{
	int i = 0;
	int a[10] = {1,2}; //其他初始化为0
	int b[] = {1,2};
	int c[20] = {0};
	
	for(i=0; i<10; i++)
	{
		printf("%d", a[i]);
	}
	
	memset(a, 0, sizeof(a));

	printf("得到整个数组的地址a: %d \n", &a);
	printf("数组的首元素的地址a: %d \n", a);
	getchar();
	
	return 0;	
}

typedef struct _Teacher
{
	char name[20];
	int age;
}Teacher;

void main12()
{
	int i = 0;
	//定义一个数组类型
	typedef int MyArrayType[5]; //int 
	MyArrayType myArray; //int myArray[5];

	for (i=0; i<5; i++)
	{
		myArray[i] = i +1;
	}
	for (i=0; i<5; i++)
	{
		printf("%d \n", myArray[i]);
	}
	system("pause");
}

//演示如何通过数组类型 来定义一个指向数组类型的指针变量
void main13()
{
	int i = 0;
	//定义一个数组类型
	typedef int MyArrayType[5]; //int 

	//定义了一个 数组类型的指针
	MyArrayType *pArray = NULL; //59

	int a[5];

	//如何定义一个数组类型指针 
	{
		int a1;
		int *p1 = NULL;

		p1 = &a1; //对变量取地址，赋给指针
	}
	pArray = &a;

	//我通过数组指针的方式来操作a[5]这块内存
	for (i=0; i<5; i++)
	{
		(*pArray)[i] = i+1; //a[i] = i+1;
	}

	for (i=0; i<5; i++)
	{
		printf("%d \n", (*pArray)[i]);
	}
	
	system("pause");
}

//定义数组指针类型
void main14()
{
	int i = 0;
	//这个是定义了一个类型，这个类型是数组类型
	typedef int MyArrayType[5]; //int 

	//这个是定义了一个类型，定义了一个指针类型，定义了一个指向数组的指针类型。。。。//数组指针
	typedef int (*MyPArrType)[5] ;

	MyPArrType myPoint; //int b[5]; //96

	int b[5];
	{
		int b1 = 0;
		int *pb1 = &b1;  //变量取地址给指针赋值
	}
	myPoint = &b; //变量取地址给指针赋值 

	for (i=0; i<5; i++)
	{
		(*myPoint)[i] = i+1;
	}

	for (i=0; i<5; i++)
	{
		printf("%d  ", (*myPoint)[i]);
	}
	
	system("pause");
}

void main16()
{
	int i = 0;
	int c[5];
	int (*myArrayPoint)[5] ; //告诉编译给我开辟四个字节内存
	{

		//定义一个数组类型
		typedef int MyArrayType[5]; //int 
		//定义了一个 数组类型的指针
		MyArrayType *pArray = NULL; //59
	}

	{	
		//这个是定义了一个类型，定义了一个指针类型，定义了一个指向数组的指针类型。。。。//数组指针
		typedef int (*MyPArrType)[5] ;
		MyPArrType myPoint; //int b[5]; //96
	}

	myArrayPoint = &c;
	for (i=0; i<5; i++)
	{
		(*myArrayPoint)[i] = i+1;
	}

	for (i=0; i<5; i++)
	{
		printf("%d  ", (*myArrayPoint)[i]);
	}

	system("pause");
	
}