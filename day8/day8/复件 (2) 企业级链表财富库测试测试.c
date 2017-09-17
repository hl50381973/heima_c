#include "stdlib.h"
#include "stdio.h"
#include "string.h"
#include "Mylinklist.h"

typedef struct _Teacher
{
	LinkListNode node; //必须在业务节点的第一个域包含链表结
	char name[32];
	char name2[32];
	int age ;
}Teacher;

typedef struct _Student
{
	LinkListNode node; //必须在业务节点的第一个域包含链表结
	char name[32];
	char name2[32];
	int age ;
}Student;

void main()
{
	//定义一个链表
	int ret = 0, len = 0, i = 0;
	LinkList *list = NULL;
	Teacher t1,t2, t3,t4,t5;
	memset(&t1, 0, sizeof(Teacher));
	memset(&t2, 0, sizeof(Teacher));
	memset(&t3, 0, sizeof(Teacher));
	memset(&t4, 0, sizeof(Teacher));
	memset(&t5, 0, sizeof(Teacher));

	t1.age = 1;
	t2.age = 2;
	t3.age = 3;
	t4.age = 4;
	t5.age = 5;
	list = LinkList_Create();
	if (list == NULL)
	{
		return ;
	}

	//向链表中添加业务数据
	//业务数据和链表算法的有效分离。。。。。。
	ret = LinkList_Insert(list, (LinkListNode*)&t1, LinkList_Length(list));
	ret = LinkList_Insert(list, (LinkListNode*)&t2, LinkList_Length(list));
	ret = LinkList_Insert(list, (LinkListNode*)&t3, LinkList_Length(list));
	ret = LinkList_Insert(list, (LinkListNode*)&t4, LinkList_Length(list));
	ret = LinkList_Insert(list, (LinkListNode*)&t5, LinkList_Length(list));

	len = LinkList_Length(list);

	//从链表中获取业务节点
	for (i=0; i<LinkList_Length(list); i++)
	{
		struct _Teacher *tmp = (struct _Teacher *)LinkList_Get(list, i);
		if (tmp != NULL)
		{
			printf("age:%d \n", tmp->age);
		}
	}

	//删除链表结点
	while (LinkList_Length(list) > 0)
	{
		//在从链表库中删除业务节点的时候，把业务节点的指针返回给调用者，以便调用者进行额外的逻辑控制。。。。
		struct _Teacher *tmp  =  (struct _Teacher *)LinkList_Delete(list, 0);
		if (tmp != NULL)
		{
			printf("age:%d \n", tmp->age);
		}
	}
	
	//销毁链表
	LinkList_Destroy(list);

	
	system("pause");
}
