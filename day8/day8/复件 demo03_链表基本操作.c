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
void main()
{
	SLIST *pHead = NULL;
	pHead = 	SList_Creat();

	system("pause");
}