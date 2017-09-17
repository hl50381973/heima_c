
//程序作用：求类型大小 关键字sizeof用法
//sizeof a ; sizeof int 
#include "stdio.h"
#include "stdlib.h"

int main11()
{
	int a = 10;
	int b[10] ; //
	printf("int a:%d \n", sizeof(a)); //4
	//printf("int a:%d \n", sizeof a );
	printf("int a:%d \n", sizeof(int *));//4
	printf("int b:%d \n", sizeof(b));//40
	printf("int b:%d \n", sizeof(b[0]));//4
	printf("int b:%d \n", sizeof(*b));//4
	printf("hello.....\n");
	getchar();
	return 0;
}