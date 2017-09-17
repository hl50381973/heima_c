#include "stdlib.h"
#include "stdio.h"
#include "string.h"

//回忆指针基础

//演示间接赋值
int main51()
{
	int a = 0;
	int *p = NULL; //

	p = &a;
	
	*p = 11; //间接赋值 *p就像一把钥匙，通过指针打开一扇门，去修改门后面的内存空间

	printf("sizeof(int *):%d, sizeof(p):%d\n", sizeof(int *), sizeof(p));
	printf("*p:%d", a);

	getchar();
	return 0;
}

//演示
//*p放在等号的左边
//*p放在等号的右边
int main52()
{
	int a = 0;
	int *p = NULL; //定义一个指针，并初始化后

	p = &a;

	*p = 11; //间接赋值 *p就像一把钥匙，通过指针打开一扇门，去修改门后面的内存空间

	{
		int c = 100;
		c = *p;
		
		printf("c:%d", c);
	}

	{
		char buf1[20];
		char buf2[20];
		
		char *p1 = buf1;
		char *p2 = buf2;
		strcpy(buf1, "abcd");

		while (*p1!='\0')
		{
			*p2++ = *p1++; //增加几那？
		}
		*p2 = '\0';
		printf("\nbuf2:%s", buf2);
		
	}

	getchar();
	return 0;
}


//演示
//p指针也是一种数据类型，指针的数据类型具有依赖特性；
//指针的数据类型，是指它所指向的内存空间的数据类型。
/*
int getData01(char a);
int getData01(char *p, int *len);
int getData02(char **p, int *len);
int getData03(char *p[], int a);
int getData03(char buf[][30], int n);
*/
int main53()
{
	int a[5] = {1, 2, 3, 4, 5};
	int *p = a;

	//导致这个问题的原因是 a是一个指针 &a也是一个指针，但是a &a两个指针的数据类型不一样。
	//指针的步长计算公式为：p+1 ===>(unsigned int)p + sizeof(*p);
	//结论非常简单：指针步长根据 所执行内存空间的数据类型来定。
	printf("p:%d, p+1:%d\n", p, p+1);
	printf("a:%d, a+1:%d\n", a, a+1); //a是数组首元素地址，代表数组首元素，首元素是int型变量，所以p++,步长为4
	printf("&a:%d, &a+1:%d\n", &a, &a+1);//&a是整个数组类型int[5],代表整个数组，&a++步长等于4*5 = 20; 
	
	getchar();
	return 0;
}

//对于基础数据类型，从被调用函数返回值，有两种方法
int Add10(int a)
{
	return a+10;
}

void Add20(int a, int result)
{
	result = a+20;
}

void Add30(int a, int *result)
{
	*result = a+30;
}


int main54()
{
	int a = 10;
	int result = 0;

	Add30(a, &result);
	printf("result:%d \n", result);
	getchar();
	return 0;
}


//函数调用时用1级指针（形参）去改变0级指针的值
void getLen(int *p)
{
	int a = 200;
	*p = a;
}

//0级指针到1级指针的推演
//间接赋值成立的三个条件
int main55()
{
	//01定义两个变量通常实参，一个形参 
	int a = 100;
	int *p = NULL;
	int result;

	//02建立关联 实参取地址赋给形参
	p = &a;

	//03 *p形参间接修改实参的值
	//*p = a;
	getLen(&a);

	printf("间接赋值成立的是三个条件至关重要\n");
	getchar();
}


//典型的错误用法
void getLen2(int *p)
{
	int a = 200;
	*p = a;
}

int main57()
{
	int *a = NULL;
	getLen(a);
	getchar();
}

//指针的特性：输入输出特性
//一级指针做输出




