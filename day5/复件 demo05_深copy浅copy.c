#include "stdlib.h"
#include "stdio.h"
#include "string.h"

//结构体的定义
typedef struct _AdvTeacher
{
	char *name;
	char buf[100];
	int age;
}Teacher ;


Teacher * creatT()
{
	Teacher *tmp = NULL;
	tmp = (Teacher *)malloc(sizeof(Teacher));
	tmp->name = (char *)malloc(100);
	return tmp;
}

void FreeT(Teacher *t)
{
	if (t == NULL)
	{
		return ;
	}
	if (t->name != NULL)
	{
		free(t->name);
	}
}

//产生的原因
//编译器给我们提供的copy行为是一个浅copy
//当结构体成员域中含有buf的时候，没有问题
//当结构体成员域中还有指针的函数，编译器只会进行指针变量的copy。指针变量所致的内存空间，编译器不会在多分分配内存
//这就是编译器的浅copy，我们要属顺从。。。。
//

//解决方案
int copyObj(Teacher *to, Teacher *from)
{
	//*to = *from;//copy；
	memcpy(to, from, sizeof(Teacher));
	to->name = (char *)malloc(100);
	strcpy(to->name, from->name);
}
void main()
{
	Teacher t1;
	Teacher t2;
	t1.name = (char *)malloc(100);
	t1.age = 10;

	//t2 = t1;//copy；
	copyObj(&t2, &t1);

	
	if (t1.name != NULL)
	{
		free(t1.name );
	}

	if (t2.name != NULL)
	{
		free(t2.name );
	}

	system("pause");
}
	


