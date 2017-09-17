#include "stdlib.h"
#include "string.h"
#include "stdio.h"

//证明二维数组的存储，是线性的e。。。。。
void printArray(char aa[][5]);
void printArray2(int *p);

void main()
{
	int a[3][5];


	int c[5]; //&c + 1;

	int b[10]; //b代表数组首元素的地址 &b代表这个数组的地址 &b+1相当于 指针后移4*10个单位
	//指针步长===》铁律1
	
	//a代表什么什么那？a是一个数组指针 指向低维数组的指针
	//a +1;
	printf("a:%d, a+1:%d \n", a, a+1); //4*5

	{
		int i=0, j = 0, tmp = 0;
		for (i=0; i<3; i++)
		{
			for (j=0; j<5; j++)
			{
				a[i][j] = ++tmp;
			}
		}

		printf("\n");
		for (i=0; i<3; i++)
		{
			for (j=0; j<5; j++)
			{
				printf("%d \n", a[i][j]);
			}
		}
	}

	//a的本质是一个数组指针。。。。每次往后跳一维的维数。。。。。。
	{
		int i = 0, j = 0;
		//定义了一个数组指针 变量
		int (*myArrayPoint)[5] ; //告诉编译给我开辟四个字节内存
		myArrayPoint  =  a;
		printf("\n");
		for (i=0; i<3; i++)
		{
			for (j=0; j<5; j++)
			{
				//myArrayPoint[i][j] = ++tmp;
				printf("%d \n", myArrayPoint[i][j]);
			}
		}
	}

	/*
	char array[10][30];
	(array+i) //相当于 第i行的首地址 //二级指针

	（*(array+i)）//一维数组的首地址

	（*(array+i)）+j //相当于第i行第j列的地址了把。。。。

	*(（*(array+i)）+j) //相当于第i行第j列的地址了把。。。。<====>array[i][j]
	*/


	
	system("pause");
}