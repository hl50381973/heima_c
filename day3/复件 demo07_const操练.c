#include "stdlib.h"
#include "stdio.h"
#include "string.h"

//指针变量和它所指向的内存空间变量，是两个不同的概念。。。。。。
//看const 是放在*的左边还是右边 看const是修饰指针变量，还是修饰所指向的内存空变量

int getStr(const char *p1)
{
	//p1[0] = 'a';
	p1 = 0x1;
	p1 = 0x2;
	
	return 0;
}

int getStr2( char * const p1)
{
	
	//p1 = 0x1;
	//p1 = 0x2;

	p1[0] = 'a';

	return 0;
}

int getStr3(const char * const p1)
{

	//p1 = 0x1;
	//p1 = 0x2;

	//p1[0] = 'a';

	return 0;
}
int main()
{
	const int a;  //const修饰 a b意义相同
	int const b; 

	const char *c; //const修饰c所执行的内存空间，c所值得内存空间不能被修改
	char * const d; //d是一个常量指针；
	const char  * const e ;

	{
		char *p1 = "abcde";
		getStr(p1);
	}

	{
		int a[10]; //a是一个指针===》a常量指针===》为什么c++
		int *p = a;
		p ++;

		a ++;
	}
	

	return 0;
}


