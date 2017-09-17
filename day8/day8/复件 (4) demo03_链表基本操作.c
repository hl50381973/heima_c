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
int SList_Destory(SLIST *pHead);


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

int SList_Print(SLIST *pHead)
{
	SLIST *p = NULL;

	if (pHead == NULL)
	{
		return -1;
	}
	p = pHead->next;
	printf("\nBegin ");
	while(p)
	{
		printf("%d ", p->data);
		p  = p->next;
	}
	printf(" End");
}

int SList_Destory(SLIST *pHead)
{

	SLIST *p = NULL, *tmp = NULL;
	if (pHead == NULL)
	{
		return -1;
	}
	p = pHead;
	while(p)
	{
		//缓存下一个结点位置
		tmp = p->next;
		free(p);//删除当前节点
		p = tmp; //节点指针后移
	}
	return 0;
}

//功能：在值为x的结点前，插入值为y的结点；若值为x的结点不存在，则插在表尾。
int SList_NodeInsert(SLIST *pHead, int x, int y)
{
	SLIST *pCur = NULL, *pPre = NULL, *pM = NULL;

	//根据y的值malloc新结点
	pM = (SLIST *)malloc(sizeof(SLIST));
	if (pM == NULL)
	{
		return -1;
	}
	pM->data = y;
	pM->next = NULL;

	//准备pCur Pre环境
	pPre = pHead;
	pCur = pHead->next;

	while (pCur)
	{
		if (pCur->data == x)
		{
			//插入操作
			break;
		}

		pPre = pCur; //让前驱结点后移
		pCur = pCur->next; //让当前结点后移
	}

	//1 pM结点连接后继链表
	//pM->next = pCur;
	pM->next = pPre->next;
	//2 让前驱结点连接pM 
	pPre->next = pM; 

	return 0;
}

int SList_NodeDel(SLIST *pHead, int x)
{
	SLIST *pCur = NULL, *pPre = NULL;

	//准备pCur Pre环境
	pPre = pHead;
	pCur = pHead->next;

	while (pCur)
	{
		if (pCur->data == x)
		{
			//插入操作
			break;
		}

		pPre = pCur; //让前驱结点后移
		pCur = pCur->next; //让当前结点后移
	}

	if (pCur == NULL)
	{
		printf("没有找到要删除的结点\n");
		return -1;
	}
	//从链表上删除结点
	pPre->next =   pCur->next;
	//释放内存
	free(pCur);
	return 0;
}
void main()
{
	SLIST *pHead = NULL;
	pHead = 	SList_Creat();
	SList_Print(pHead);

	SList_NodeInsert(pHead, 20, 19);
	SList_Print(pHead);

	//SList_NodeInsert(pHead, 100, 99);
	//SList_Print(pHead);

	SList_NodeDel(pHead, 19);
	SList_Print(pHead);


	SList_Destory(pHead);



	system("pause");
}