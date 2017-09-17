#include "stdio.h"
#include "stdlib.h"
#include "string.h"

//野指针产生问题分析
//指针变量和它所指内存空间变量是两个不同的概念


//解决野指针的方案
//1定义指针时 把指针变量赋值成null
//2 释放内存时，先判断指针变量是否为null 
//3 释放内存完毕后，把指针变量重新赋值成null

//
void main22()
{
	char *p = NULL;
	p = (char *)malloc(100); //char p[100];
	strcpy(p, "abcdefg");

	//做业务
	//此处省略5000字。。。。。
	if (p != NULL)
	{
		free(p);
		p = NULL;
	}

	//做业务
	//此处省略5000字。。。。。
	if (p != NULL)
	{
		free(p);
	}
	system("pause");
}

char *getMem2(int count)
{
	char *tmp = NULL;
	tmp = (char *)malloc(100*sizeof(char)); //char tmp[100];
	return tmp;
}

//实参和形参是两个不同的概念
void getMem3(int count, char *p)
{
	char *tmp = NULL;
	tmp = (char *)malloc(100*sizeof(char)); //char tmp[100];
	p = tmp; //在这个场景下，你给形参赋值了，没有给实参赋值 
	//直接修改实参没戏。。。。。。。 实参和形参是两个不同的概念
	//return tmp;
}

void getMem4(int count, char **p /*out*/)
{
	char *tmp = NULL;
	tmp = (char *)malloc(100*sizeof(char)); //char tmp[100];
	//p = tmp; //在这个场景下，你给形参赋值了，没有给实参赋值 
	//直接修改实参没戏。。。。。。。 实参和形参是两个不同的概念
	//间接的修改实参
	*p = tmp;
	//return tmp;
}

//函数调用的时候，这个场景修改不实参
int FreeMem2(char *p)
{
	if (p ==NULL)
	{
		return -1;
	}
	if (p != NULL)
	{
		free(p);
		p = NULL; //想把实参给改掉，你能修改吗？ 修改不了实参。。。。。
	}
	return 0;
}

void main()
{
	char *myp = NULL;
	myp = getMem2(100);
	getMem3(100, myp);

	getMem4(100, &myp);

	//做业务操作
	//此 50000
	FreeMem2(myp);

	FreeMem2(myp);
}



