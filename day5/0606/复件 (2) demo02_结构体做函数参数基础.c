
#include "stdlib.h"
#include "stdio.h"
#include "string.h"

//结构体的定义
typedef struct _Teacher
{
	char name[62];
	char c;
	int age;
}Teacher ;


int printTArray(Teacher *tArray, int num)
{
	int i = 0;
	for (i=0; i<num; i++)
	{
		printf("%d \n", tArray[i].age);
	}
	return 0;
}
//
int sortTArray(Teacher *tArray, int num)
{
	int i , j = 0; 
	Teacher tmp;
	for (i=0; i<num; i++)
	{
		for (j=i+1; j<num; j++)
		{
			if (tArray[i].age > tArray[j].age)
			{
				tmp = tArray[i]; //编译器给我们提供的行为
				tArray[i] = tArray[j];
				tArray[j] = tmp;
			}
		}
	}
	return 0;
}

int getLen(int *num)
{
	*num = 10;
}

//分配结构体数组内存块
//在被调用函数里面分配的内存块 传送不出来
int creatTArray(Teacher *tArray, int num)
{
	tArray = (Teacher *)malloc(num * sizeof(Teacher));
	if (tArray == NULL)
	{
		return -1;
	}
	return 0;
}

Teacher *creatTArray2(int num)
{
	Teacher *tArray = NULL;
	tArray = (Teacher *)malloc(num * sizeof(Teacher));
	if (tArray == NULL)
	{
		return NULL;
	}
	return tArray;
}

//
void main01()
{
	//定义一个结构体数组，给结构体数组元素赋值，给结构题排序。。。。打印
	int i = 0;
	int ret = 0;

	Teacher tArray[3];
	
	Teacher *pArray = NULL;
	
	ret = creatTArray(pArray, 3);
	if (ret != 0)
	{
		return ;
	}

	pArray = creatTArray2(3);
	if (pArray == NULL)
	{
		return ;
	}
	
	for (i=0; i<3; i++)
	{
		printf("请键入第%d个老师的年龄：", i+1);
		scanf("%d", &tArray[i].age);
	}

	printf("排序之前。。。。\n");
	printTArray(tArray, 3);
	sortTArray(tArray, 3);
	printf("排序之后。。。。\n");
	printTArray(tArray, 3);



	system("pause");
}



void main()
{
	//定义一个结构体数组，给结构体数组元素赋值，给结构题排序。。。。打印
	int i = 0;
	int ret = 0;
	Teacher *pArray = NULL;

	pArray = creatTArray2(3);
	if (pArray == NULL)
	{
		return ;
	}

	for (i=0; i<3; i++)
	{
		printf("请键入第%d个老师的年龄：", i+1);
		scanf("%d", & (pArray[i].age));
	}

	printf("排序之前。。。。\n");
	printTArray(pArray, 3);
	sortTArray(pArray, 3);
	printf("排序之后。。。。\n");
	printTArray(pArray, 3);

	system("pause");
}
