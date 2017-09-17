#include "stdlib.h"
#include "string.h"
#include "stdio.h"


int getMem(char ***myp3 /*out*/)
{
	int i = 0;

	char **tmp = (char **)malloc(10*sizeof(char *));
	if (tmp == NULL)
	{
		return -1;
	}
	memset(tmp, 0, 10*sizeof(char *));//给tmp指针指向的内存块赋值成0
	for (i=0; i<3; i++)
	{
		tmp[i] = (char *)malloc(100);
	}
	//*myp3 = 100; //p2取地址传给p3 通过*p3（p2的地址）去间接的修改了p2的值。。
	*myp3 = tmp;
	return;
}


void main03233()
{
	char **p2 = NULL;
	char ***p3 = NULL;
	
	//直接修改p2 的值
	p2 = 1;
	p2 = 3;

	printf("p2:%d \n", p2);
	p3 = &p2;
	*p3 = 100; //p2取地址传给p3 通过*p3（p2的地址）去间接的修改了p2的值。。

	//p3 = &p2;
	getMem(&p2);

	printf("p2:%d \n", p2);
	system("pause");
}

void getp7(char ********  myp8)
{
	*myp8 = 200; //p7取地址，传给p8；*p8去间接的修改p7的值。
}
void main()
{
	char *******  p7 = NULL; //p7就是4个字节
	p7 = 1;
	p7 = 2;
	
	{
		char ********p8 = NULL;
		p8 = &p7;
		*p8 = 100; //p7取地址，传给p8；*p8去间接的修改p7的值。
	}
	printf("p7:%d", p7);

	getp7(&p7);

	printf("通过多级指针，去间接修改p7的值p7:%d", p7);


	system("pause");
}