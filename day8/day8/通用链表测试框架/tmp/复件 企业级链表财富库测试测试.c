#include "stdlib.h"
#include "stdio.h"
#include "string.h"
#include "Mylinklist.h"

typedef struct _Teacher
{
	LinkListNode node; //必须在业务节点的第一个域包含链表结
	char name[32];
	int age ;
}Teacher;


void main()
{
	//定义一个链表
	int ret = 0, len = 0;
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

	ret = LinkList_Insert(list, (LinkListNode*)&t1, LinkList_Length(list));
	ret = LinkList_Insert(list, (LinkListNode*)&t2, LinkList_Length(list));
	ret = LinkList_Insert(list, (LinkListNode*)&t3, LinkList_Length(list));
	ret = LinkList_Insert(list, (LinkListNode*)&t4, LinkList_Length(list));
	ret = LinkList_Insert(list, (LinkListNode*)&t5, LinkList_Length(list));

	len = LinkList_Length(list);




	LinkList_Destroy(list);

	/*
	LinkList* LinkList_Create();

	void LinkList_Destroy(LinkList* list);

	void LinkList_Clear(LinkList* list);

	int LinkList_Length(LinkList* list);

	

	LinkListNode* LinkList_Get(LinkList* list, int pos);

	LinkListNode* LinkList_Delete(LinkList* list, int pos);
	*/
	system("pause");
}
