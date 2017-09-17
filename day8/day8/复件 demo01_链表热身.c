#include "stdio.h"
#include "string.h"
#include "stdlib.h"


typedef struct _Student
{
	char name[64];
	int age;
}Student;

//自定义数据结构定义 本质 固定大小内存块的别名
typedef struct _Teacher
{
	char name[64];
	int age;
	char *p1 ;
	char **p2;
	Student s1;
	Student *ps1; //
}Teacher;



void main01()
{
	Student s1;
	Teacher t1; //告诉编译器要分配内存
	t1.age = 30;
	t1.s1.age = 20;

	//结构体中套一个元素 和 跳一个指针区别。。。
	t1.ps1 = &s1; //没有内存块，哪里的指针

	t1.ps1->age = 100;

	system("pause");
}

//我要自定义数据类型，本质 固定大小内存块的别名。。是一个模子。。。。
typedef struct _AdvTeacher
{
	char name[64]; 
	int age;
	struct _AdvTeacher *pAdvTeacher; 
	//struct _AdvTeacher myAdvTeacher;
}AdvTeacher;

void main()
{

	//AdvTeacher adv; //栈溢出
	system("pause");
}

