#include "stdio.h"
#include "string.h"
#include "stdlib.h"

typedef struct Node
{
	int data;
	struct Node *next;
}SLIST;


//编写函数SList_Creat，建立带有头结点的单向链表。循环创建结点，
//结点数据域中的数值从键盘输入，以-1作为输入结束标志。链表的头结点地址由函数值返回。

SLIST *SList_Creat();
int SList_Print(SLIST *pHead);
int SList_NodeInsert(SLIST *pHead, int x, int y);
int SList_NodeDel(SLIST *pHead, int x);


SLIST *SList_Creat()
{
	SLIST *pHead = NULL, *pM =NULL, *pCur = NULL;
	int data = 0;
	//1 创建头结点并初始化
	pHead = (SLIST *)malloc(sizeof(SLIST));
	if (pHead == NULL)
	{
		return NULL;
	}
	pHead->data = 0;
	pHead->next = NULL;

	//2 从键盘输入数据，创建业务结点
	printf("\nplease enter the data of node(-1:quit) ");
	scanf("%d", &data);

	//3 循环创建
	//初始化当前节点，指向头结点
	pCur = pHead;
	while(data != -1)
	{
		//新建业务结点 并初始化
		//1 不断的malloc 新的业务节点 ===PM
		pM = (SLIST *)malloc(sizeof(SLIST));
		if (pM == NULL)
		{
			return NULL;
		}
		pM->data = data;
		pM->next = NULL;

		//2、让pM节点入链表
		pCur->next = pM;

		//3 pM节点变成当前节点
		pCur = pM; //pCur = pCur->next;


		//2 从键盘输入数据，创建业务结点
		printf("\nplease enter the data of node(-1:quit) ");
		scanf("%d", &data);
	}

	return pHead;
}
void main()
{
	SLIST *pHead = NULL;
	pHead = 	SList_Creat();

	system("pause");
}