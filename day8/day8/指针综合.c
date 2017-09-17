#include "stdlib.h"
#include "string.h"
#include "stdio.h"

typedef struct _Teacher
{
	char name[64];
	int age;
}Teacher;

int createTe(Teacher  **p)
{
	Teacher *tmp = (Teacher *)malloc(sizeof(Teacher));
	tmp->age = 10;
	*p = tmp;
	return 0;
}
int printTe1(Teacher  *p)
{
	printf("%d \n", p->age);
}
int printTe2(Teacher  **p)
{
	Teacher *tmp = *p;
	printf("%d \n", tmp->age);
}
int FreeTe1(Teacher  *p)
{
	if (p!=NULL)
	{
		free(p);
		p = NULL;
	}
}

//p��һ����������ʵ�εĵ�ַ
int FreeTe2(Teacher  **p)
{
	Teacher *tmp = NULL;
	if (p == NULL)
	{
		return 0;
	}
	
	tmp = *p;
	if (tmp != NULL)
	{
		free(tmp);
	}
	*p = NULL; //����޸�ʵ�� *pʵ�εĵ�ַ��ȥ��ӵ��޸�ʵ��
}
void main()
{
	Teacher *myp = NULL;
	createTe(&myp);

	printTe1(myp);
	//FreeTe1(myp);
	FreeTe2(&myp);
	system("pause");
}