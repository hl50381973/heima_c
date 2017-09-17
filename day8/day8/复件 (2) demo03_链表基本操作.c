#include "stdio.h"
#include "string.h"
#include "stdlib.h"

typedef struct Node
{
	int data;
	struct Node *next;
}SLIST;


//��д����SList_Creat����������ͷ���ĵ�������ѭ��������㣬
//����������е���ֵ�Ӽ������룬��-1��Ϊ���������־�������ͷ����ַ�ɺ���ֵ���ء�

SLIST *SList_Creat();
int SList_Print(SLIST *pHead);
int SList_NodeInsert(SLIST *pHead, int x, int y);
int SList_NodeDel(SLIST *pHead, int x);
int SList_Destory(SLIST *pHead);


SLIST *SList_Creat()
{
	SLIST *pHead = NULL, *pM =NULL, *pCur = NULL;
	int data = 0;
	//1 ����ͷ��㲢��ʼ��
	pHead = (SLIST *)malloc(sizeof(SLIST));
	if (pHead == NULL)
	{
		return NULL;
	}
	pHead->data = 0;
	pHead->next = NULL;

	//2 �Ӽ����������ݣ�����ҵ����
	printf("\nplease enter the data of node(-1:quit) ");
	scanf("%d", &data);

	//3 ѭ������
	//��ʼ����ǰ�ڵ㣬ָ��ͷ���
	pCur = pHead;
	while(data != -1)
	{
		//�½�ҵ���� ����ʼ��
		//1 ���ϵ�malloc �µ�ҵ��ڵ� ===PM
		pM = (SLIST *)malloc(sizeof(SLIST));
		if (pM == NULL)
		{
			return NULL;
		}
		pM->data = data;
		pM->next = NULL;

		//2����pM�ڵ�������
		pCur->next = pM;

		//3 pM�ڵ��ɵ�ǰ�ڵ�
		pCur = pM; //pCur = pCur->next;


		//2 �Ӽ����������ݣ�����ҵ����
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
		//������һ�����λ��
		tmp = p->next;
		free(p);//ɾ����ǰ�ڵ�
		p = tmp; //�ڵ�ָ�����
	}
	return 0;
}

void main()
{
	SLIST *pHead = NULL;
	pHead = 	SList_Creat();
	SList_Print(pHead);

	SList_Destory(pHead);



	system("pause");
}