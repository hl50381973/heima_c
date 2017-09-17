
#include "stdlib.h"
#include "stdio.h"
#include "string.h"

typedef struct Te1
{
	char *p1;
	char *p2;

	char *p3;
	char *p13;
	char *p4;
};

//结构体的定义
typedef struct _Teacher
{
	char name[64]; 
	char *tile;
	//char *p1;
	//char **p2;
	int age;
}Teacher ;


int printTArray(Teacher *tArray, int num)
{
	int i = 0;
	for (i=0; i<num; i++)
	{
		printf("%d %s %s \n", tArray[i].age, tArray[i].name, tArray[i].tile);
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

Teacher *creatTArray2(int num)
{
	int i = 0;
	Teacher *tArray = NULL;
	tArray = (Teacher *)malloc(num * sizeof(Teacher));
	if (tArray == NULL)
	{
		return NULL;
	}
	for (i=0; i<num; i++)
	{
		tArray[i].tile = (char *)malloc(100);
	}
	return tArray;
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
		scanf("%d", &pArray[i].age);
		printf("请键入第%d个老师的姓名：", i+1);
		scanf("%s", pArray[i].name);

		printf("请键入第%d个老师的职称：", i+1);
		scanf("%s", pArray[i].tile);
	}

	printf("排序之前。。。。\n");
	printTArray(pArray, 3);
	sortTArray(pArray, 3);
	printf("排序之后。。。。\n");
	printTArray(pArray, 3);

	system("pause");
}
