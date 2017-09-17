#include "stdio.h"
#include "string.h"
#include "stdlib.h"

//自定义数据结构定义 本质 固定大小内存块的别名
typedef struct _Teacher
{
	char name[64];
	int age;
	struct _Teacher *next;
}Teacher;


/*
1 建立的时，指针指向谁，就把谁的地址赋给指针。。
2、赋值指针变量和业务操作之间的关系。。。。
=======》看图说话
*/
Teacher  *main2()
{
	Teacher t1, t2, t3;
	Teacher *p = NULL;
	memset(&t1, 0, sizeof(Teacher));
	memset(&t2, 0, sizeof(Teacher));
	memset(&t3, 0, sizeof(Teacher));
	t1.age = 11;
	t2.age = 22;
	t3.age = 33;

	t1.next = &t2;
	t2.next = &t3;
	t3.next = NULL; //这一句不要忘记
	return &t1;
}

//静态链表局限性
void main()
{
	Teacher *p = NULL;
	p = main2();
	while(p)
	{
		printf("age:%d \n", p->age);
		p = p->next;
	}

	system("pause");
}