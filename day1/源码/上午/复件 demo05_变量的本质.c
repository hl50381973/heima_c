#include "stdlib.h"
#include "string.h"
#include "stdio.h"


//数据类型分为两种，一个是简单的数据类型，一个是复杂的数据类型。
//碰见复杂的数据类型不能用简单的数据类型的思维去思考它。抛砖

void main(void)
{
	int a; //告诉c编译器给我分配4个字节的内存

	a = 10; //直接修改

	printf("&a:%d \n", &a);

	printf("a:%d \n", a);

	*((int *)1245024) = 20;  //间接修改

	printf("&a:%d \n", &a);
	printf("通过标号a:%d \n", a);


	system("pause");
}