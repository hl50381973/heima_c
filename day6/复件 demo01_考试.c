#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "string.h"
#include "stdlib.h"

//把第一种内存模型的数据排序,运算结果放到第三种内存模型中
char **SortArrayAndGen3Mem(const char ** const myArray1, int num,  char *str, int *myNum)
{
	
	char **p = NULL;
		p= (char **)malloc(num*sizeof(char *));
	if (myArray1==NULL || str==NULL|| myNum==NULL)
	{
		printf("传入参数错误\n");
		p = NULL;
		goto END;
	}
	*myNum = num;
	for (int i = 0; i < num;i++)
	{
		p[i] = NULL;
		p[i] = (char)malloc(50 * sizeof(char));
		memset(p[i], 0, sizeof(p[i]));
		if (p[i]==NULL)
		{
			printf("内存分配错误！\n");
			goto END;
		}
		strcpy(p[i], myArray1[i]);

	}
	char *tmp;
	for (int i = 0; i < num; i++)
	{
		for (int j = i + 1; j < num; j++)
		{
			if (strcmp(p[i],p[j])>0)
			{
				char *tmp = p[i];
				p[i] = p[j];
				p[j] = tmp;
				
			}
		}

	}
	for (int i = 0; i < num; i++)
	{
		printf("%s \n", myArray1[i]);
	}
	


END:

	return p;
}

//释放内存函数自己写
void main222()
{
	int i = 0;
	char **myArray3 = NULL;
	int num3 = 0;
	//第一种内存模型
	char *myArray[] = {"bbbbb", "aaaaa", "cccccc"};
	char *myp = "111111111111";

	myArray3 = SortArrayAndGen3Mem(myArray, 3,  myp, &num3);

	for (i=0; i<num3; i++)
	{
		printf("%s \n", myArray3[i]);
	}

	system("pause");
}