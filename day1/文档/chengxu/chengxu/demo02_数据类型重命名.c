#include "stdio.h"
#include "stdlib.h"

//typdef作用 类型重命名
typedef int u32;
typedef char u8;

//结构体和变量
struct _Teacher
{
	char	name[64];
	int		age;
};
typedef struct _Teacher Teacher;

int main21()
{
	//Teacher t1;
	printf("Teacher:%d \n", sizeof(Teacher));
	printf("u32:%d \n", sizeof(u32));
	printf("u8:%d \n", sizeof(u8));
	printf("hello.....\n");
	getchar();
	return 0;
}


//typedef char(*p)[5];

int mainxxx()
{
	char a[5];
	//数据类型本质是固定大小的的内存块；
	//指针也是一种数据类型，指针的数据类型指的是，所致内存空间的数据类型。
	//所指内存空间的数据类型，决定了指针的步长，而数据类型的本质是内存块的大小。
	//故p++步长推理过程
	//p++的步长有数据类型来决定。

	char(*p2)[5];
	char(*p)[5] = &a;
	printf("sizeof(*p):%d \n", sizeof(*p));
	//p+1; p + sizeof(*p);

	printf("hello.....\n");
	getchar();
	return 0;
}

