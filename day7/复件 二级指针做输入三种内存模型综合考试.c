#include "stdio.h"
#include "stdlib.h"
#include "string.h"

int getArray3_Free(char **p3, int p3num)
{
	return 0;
}

char **getArray3(char **myp1, int num1, char  (*myp2)[30], int num2, int *num3)
{
	int tmpNum3 = 0;

	char **tmpp3 = NULL;

	if (myp1==NULL || myp2==NULL ||num3==NULL )
	{
		return NULL;
	}
	//׼���ڴ�
	tmpNum3 = num1 + num2;
	//�����һά
	tmpp3 = (char **)malloc(tmpNum3 * sizeof(char *));
	
	//����ڶ�ά

	//�ѵ�һ���ڴ�ģ�����ݺ͵ڶ����ڴ�ģ�����ݣ�copy����3���ڴ�ģ����


	//����

	return tmpp3;
}

void main()
{
	int num3 = 0, i = 0;
	char *p1[] = {"222222", "1111111", "33333333"};
	char p2[4][30] =  {"bbbbb", "aaaaa", "zzzzzz", "ccccccc"};
	char **p3 = NULL;

	p3 = getArray3(p1, 3, p2, 4, &num3);
	if (p3 == NULL)
	{
		return ;
	}
	for (i=0; i<num3; i++)
	{
		printf("%s \n", p3[i]);
	}

	getArray3_Free(p3, num3);
	system("pause");
}