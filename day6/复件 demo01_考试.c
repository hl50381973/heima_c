#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "string.h"
#include "stdlib.h"

//�ѵ�һ���ڴ�ģ�͵���������,�������ŵ��������ڴ�ģ����
char **SortArrayAndGen3Mem(const char ** const myArray1, int num,  char *str, int *myNum)
{
	
	char **p = NULL;
		p= (char **)malloc(num*sizeof(char *));
	if (myArray1==NULL || str==NULL|| myNum==NULL)
	{
		printf("�����������\n");
		p = NULL;
		goto END;
	}
	*myNum = num;
	for (int i = 0; i < num;i++)
	{
		p[i] = NULL;
		p[i] = (char)malloc(50 * sizeof(char));
		memset(p[i], 0, sizeof(p[i]));
		if (p[i]==NULL)
		{
			printf("�ڴ�������\n");
			goto END;
		}
		strcpy(p[i], myArray1[i]);

	}
	char *tmp;
	for (int i = 0; i < num; i++)
	{
		for (int j = i + 1; j < num; j++)
		{
			if (strcmp(p[i],p[j])>0)
			{
				char *tmp = p[i];
				p[i] = p[j];
				p[j] = tmp;
				
			}
		}

	}
	for (int i = 0; i < num; i++)
	{
		printf("%s \n", myArray1[i]);
	}
	


END:

	return p;
}

//�ͷ��ڴ溯���Լ�д
void main222()
{
	int i = 0;
	char **myArray3 = NULL;
	int num3 = 0;
	//��һ���ڴ�ģ��
	char *myArray[] = {"bbbbb", "aaaaa", "cccccc"};
	char *myp = "111111111111";

	myArray3 = SortArrayAndGen3Mem(myArray, 3,  myp, &num3);

	for (i=0; i<num3; i++)
	{
		printf("%s \n", myArray3[i]);
	}

	system("pause");
}