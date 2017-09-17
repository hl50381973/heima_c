
#include "stdlib.h"
#include "stdio.h"
#include "string.h"

//�ṹ��Ķ���
typedef struct _Teacher
{
	char name[62];
	char c;
	int age;
}Teacher ;


int printTArray(Teacher *tArray, int num)
{
	int i = 0;
	for (i=0; i<num; i++)
	{
		printf("%d \n", tArray[i].age);
	}
	return 0;
}
//
int sortTArray(Teacher *tArray, int num)
{
	int i , j = 0; 
	Teacher tmp;
	for (i=0; i<num; i++)
	{
		for (j=i+1; j<num; j++)
		{
			if (tArray[i].age > tArray[j].age)
			{
				tmp = tArray[i]; //�������������ṩ����Ϊ
				tArray[i] = tArray[j];
				tArray[j] = tmp;
			}
		}
	}
	return 0;
}

int getLen(int *num)
{
	*num = 10;
}

//����ṹ�������ڴ��
//�ڱ����ú������������ڴ�� ���Ͳ�����
int creatTArray(Teacher *tArray, int num)
{
	tArray = (Teacher *)malloc(num * sizeof(Teacher));
	if (tArray == NULL)
	{
		return -1;
	}
	return 0;
}

Teacher *creatTArray2(int num)
{
	Teacher *tArray = NULL;
	tArray = (Teacher *)malloc(num * sizeof(Teacher));
	if (tArray == NULL)
	{
		return NULL;
	}
	return tArray;
}

//
void main01()
{
	//����һ���ṹ�����飬���ṹ������Ԫ�ظ�ֵ�����ṹ�����򡣡�������ӡ
	int i = 0;
	int ret = 0;

	Teacher tArray[3];
	
	Teacher *pArray = NULL;
	
	ret = creatTArray(pArray, 3);
	if (ret != 0)
	{
		return ;
	}

	pArray = creatTArray2(3);
	if (pArray == NULL)
	{
		return ;
	}
	
	for (i=0; i<3; i++)
	{
		printf("������%d����ʦ�����䣺", i+1);
		scanf("%d", &tArray[i].age);
	}

	printf("����֮ǰ��������\n");
	printTArray(tArray, 3);
	sortTArray(tArray, 3);
	printf("����֮�󡣡�����\n");
	printTArray(tArray, 3);



	system("pause");
}



void main()
{
	//����һ���ṹ�����飬���ṹ������Ԫ�ظ�ֵ�����ṹ�����򡣡�������ӡ
	int i = 0;
	int ret = 0;
	Teacher *pArray = NULL;

	pArray = creatTArray2(3);
	if (pArray == NULL)
	{
		return ;
	}

	for (i=0; i<3; i++)
	{
		printf("������%d����ʦ�����䣺", i+1);
		scanf("%d", & (pArray[i].age));
	}

	printf("����֮ǰ��������\n");
	printTArray(pArray, 3);
	sortTArray(pArray, 3);
	printf("����֮�󡣡�����\n");
	printTArray(pArray, 3);

	system("pause");
}
