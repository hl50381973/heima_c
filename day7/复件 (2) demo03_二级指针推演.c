#include "stdlib.h"
#include "string.h"
#include "stdio.h"


int getMem(char ***myp3 /*out*/)
{
	int i = 0;

	char **tmp = (char **)malloc(10*sizeof(char *));
	if (tmp == NULL)
	{
		return -1;
	}
	memset(tmp, 0, 10*sizeof(char *));//��tmpָ��ָ����ڴ�鸳ֵ��0
	for (i=0; i<3; i++)
	{
		tmp[i] = (char *)malloc(100);
	}
	//*myp3 = 100; //p2ȡ��ַ����p3 ͨ��*p3��p2�ĵ�ַ��ȥ��ӵ��޸���p2��ֵ����
	*myp3 = tmp;
	return;
}


void main03233()
{
	char **p2 = NULL;
	char ***p3 = NULL;
	
	//ֱ���޸�p2 ��ֵ
	p2 = 1;
	p2 = 3;

	printf("p2:%d \n", p2);
	p3 = &p2;
	*p3 = 100; //p2ȡ��ַ����p3 ͨ��*p3��p2�ĵ�ַ��ȥ��ӵ��޸���p2��ֵ����

	//p3 = &p2;
	getMem(&p2);

	printf("p2:%d \n", p2);
	system("pause");
}

void getp7(char ********  myp8)
{
	*myp8 = 200; //p7ȡ��ַ������p8��*p8ȥ��ӵ��޸�p7��ֵ��
}
void main()
{
	char *******  p7 = NULL; //p7����4���ֽ�
	p7 = 1;
	p7 = 2;
	
	{
		char ********p8 = NULL;
		p8 = &p7;
		*p8 = 100; //p7ȡ��ַ������p8��*p8ȥ��ӵ��޸�p7��ֵ��
	}
	printf("p7:%d", p7);

	getp7(&p7);

	printf("ͨ���༶ָ�룬ȥ����޸�p7��ֵp7:%d", p7);


	system("pause");
}