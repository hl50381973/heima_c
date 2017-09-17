#include "stdio.h"
#include "stdlib.h"
#include "string.h"

//强化指针数组char* a[30] 和 数组指针char (*a)[30]
//()[]优先级  
char *a() //函数名称
{
	return NULL;
}
char (*a2)(); //是一个指针变量。。。。。。分配四个自己内存


char  **getMem(int count)
{
	int i = 0;
	char **tmp = (char **)malloc(count*sizeof(char *));
	for (i=0; i<count; i++)
	{
		tmp[i]  = (char *)malloc(100);
	}
	return tmp;
}

void sortArray(char **myArray, int count)
{
	int i = 0, j = 0;

	char *tmp;
	for (i=0; i<count; i++)
	{
		for (j=i+1; j<count; j++)
		{
			if (strcmp(myArray[i], myArray[j]))
			{
				tmp = myArray[i]; //这个地方交换的是指针变量
				myArray[i] = myArray[j];
				myArray[j] = tmp;
			}
		}
	}
}

void sortArray02(char **myArray, int count)
{
	int i = 0, j = 0;

	char tmp[200];
	for (i=0; i<count; i++)
	{
		for (j=i+1; j<count; j++)
		{
			if (strcmp(myArray[i], myArray[j]) > 0)
			{
				strcpy(tmp, myArray[i]);
				strcpy(myArray[i], myArray[j]);
				strcpy(myArray[j], tmp); //交换是buf的内容
			}
		}
	}
}

void  printfArray(char **myArray, int count)
{
	int i = 0, j = 0;

	for (i=0; i<count; i++)
	{
		printf("%s \n", myArray[i]);
	}
}

void main()
{
	char **pArray = NULL;
	pArray = getMem(3);

	strcpy(pArray[0], "bbbbb");
	strcpy(pArray[1], "aaaa");
	strcpy(pArray[2], "cccc");

	printf("排序之前\n");
	printfArray(pArray ,3);

	//sortArray(pArray, 3);
	sortArray02(pArray, 3); 

	printf("排序之后\n");
	printfArray(pArray ,3);
	system("pause");


}

void main0011()
{
	//03、数组类型、数组指针类型、数组指针类型变量
	typedef int MyTypeArray[5];
	MyTypeArray a; //int a[5];
	int intArray[3][5];


	{
		typedef int (*MyPTypeArray)[5];
		MyPTypeArray  myArrayPoint ;
		myArrayPoint = &a;
		(*myArrayPoint)[0] = 1; //通过一个数组指针变量去操作数组内存
	}

	{
		int (*myArrayVar)[5]; //告诉编译给我开辟4个字节的内存‘
		myArrayVar = &a;
		(*myArrayVar)[1] = 2;
		
	}

	{
		int (*myArrayVar2)[5]; //告诉编译给我开辟4个字节的内存‘
		myArrayVar2 = intArray; //
	}

}