#include "stdlib.h"
#include "string.h"
#include "stdio.h"

void main62()
{
	int a = 10; 
	int *  p = NULL;//指针是一个变量
	int c = 0;


	a = 11; //直接修改

	p = &a;

	p = &a +1;
	p = &a +2;
	*p = 20; //*p操作
	//*p放在=的左边，写内存
	//*（谁的地址）就是去间接的修改谁。
	//*（&a）就是去间接的修改啊。
	//*p放在等号的右边，从p所指内存空间读数据。
	c = *p;

	//*p  *就像一把钥匙，通过p这扇门打开一个内存块，去操作内存空间。，



	
	system("pause");
}

//1站在c++编译器的角度 指针就是一个变量，除此之外啥也不是！
//不管是1个* 还是8个*对c++编译器来讲，只会分配4个字节内存
//2
/*
int getbuf01(char   *p); int getbuf01(char*     p);
int getbuf02(char **p); int getbuf02(char *   *p); getbuf02(char **        p);
int getbuf03(char (*p)[]); int getbuf03(char (*p)      []);  int getbuf03(char (     *p)[     ]);
int getbuf03(char p[10][30]);
int getbuf04(char *****p);

*/

//铁律一：指针也是数据类型，它的数据类型，是指它指向的内存空间的数据类型
void main()
{
	char buf1[100] = {0};
	char buf2[100] = {0};
	char *p1 = buf1;
	char *p2 = buf2;

	strcpy(buf1, "abcdefg");

	while(*p1 != '\0')
	{
		*p2 = *p1;
		p1++;
		p2 ++;
	}

	printf("buf2:%s", buf2);

	system("pause");

}