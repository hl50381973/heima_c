#include "stdio.h"
#include "string.h"
#include "stdlib.h"

//证明一下多维数组的线性存储
//线性打印

//多维数组做函数参数，一般情况下，只能表达到二维，
//如果是三维内存（我们程序员起的名字），已经没有意义。

//一般情况：1级指针代表1维，二级指针代表二维。。。
//如果有超过char ***级及3级以上的指针，则不代表几维的内存。。。

void printfAARRR(char ***ddd);
void printfAARRR(char *********dddd);

void printfArray411(int *array, int num)
{
	int i = 0;
	for (i=0; i<num ; i++)
	{
		printf("%d ", array[i]);
	}
}

void printfArray412(int (*array)[5], int num)
{
	return ;
}

void printfArrr333(int c[3][4][5])
{
	return ;
}
void main()
{
	int a[3][5];
	int c[3][4][5];
	int i , j = 0;
	int tmp = 0;
	for (i=0; i<3; i++)
	{
		for (j=0; j<5; j++)
		{
			a[i][j] = tmp ++;
		}
	}


	printfArray411((int *)a, 15);

	system("pause");
}