#include "stdio.h"
#include "stdlib.h"
#include "string.h"

int spitString03(const char *buf1, char c, char **mypp, int *num)
{
	int ret = 0;
	char *p = NULL;
	char *pTmp = NULL;
	int ncount = 0;
	if (buf1==NULL ||  num==NULL)
	{
		return -1;
	}
	//����1 ��ʼ������ pTmp,p��ִ�м����Ŀ�ͷ
	p = buf1;
	pTmp = buf1;
	do 
	{
		//����2 strstr strchr������p���� 	��p��pTmp֮����һ����ֵ
		p = strchr(p, c);
		if (p == NULL) //û���ҵ���������
		{
			break;
		}
		else 
		{

			//���ַ���
			strncpy(mypp[ncount], pTmp, p-pTmp);
			mypp[ncount][p-pTmp] = '\0';
			ncount++;

			//����3 ��p��pTmp���³�ʼ�����ﵽ����������
			pTmp = p  = p + 1;
		}

	} while (*p != '\0');
	//printf("ncout:%d\n", ncount);
	*num = ncount;
	return ret;
}

//�����ڴ溯��
char **getMem(int num)
{
	int i = 0;
	char **pp = (char **)malloc(sizeof(num*sizeof(char *)));
	if (pp == NULL)
	{
		return NULL;
	}
	for (i=0; i<num; i++)
	{
		pp[i] = (char *)malloc(100);
		if (pp[i] == NULL)
		{
			return NULL;
		}
	}
	return pp;
}

int FreeMem(char **pp, int num)
{
	int i = 0;
	if (pp == NULL)
	{
		 return -1;
	}
	for (i=0; i<num; i++)
	{
		free(pp[i]);
	}
	free(pp);
	pp=NULL��
	return 0;
}
void main()
{
	int			ret = 0, i = 0;
	int			num = 0;
	int			numArray = 10;
	const char	*buf1 = "abcdef,acccd,";
	char			c = ',';

	char			**pp =  NULL;

	pp = 	getMem(numArray);
	if (pp == NULL)
	{
		return ;
	}
	ret =  spitString03(buf1, c, pp, &num);
	if (ret != 0)
	{
		printf("func spitString() err:%d\n", ret);
		return ret;
	}

	for (i=0; i<num; i++)
	{
		printf("%s\n", pp[i]);
	}

	FreeMem(pp, numArray);
	system("pause");
}
