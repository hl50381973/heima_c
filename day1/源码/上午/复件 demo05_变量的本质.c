#include "stdlib.h"
#include "string.h"
#include "stdio.h"


//�������ͷ�Ϊ���֣�һ���Ǽ򵥵��������ͣ�һ���Ǹ��ӵ��������͡�
//�������ӵ��������Ͳ����ü򵥵��������͵�˼άȥ˼��������ש

void main(void)
{
	int a; //����c���������ҷ���4���ֽڵ��ڴ�

	a = 10; //ֱ���޸�

	printf("&a:%d \n", &a);

	printf("a:%d \n", a);

	*((int *)1245024) = 20;  //����޸�

	printf("&a:%d \n", &a);
	printf("ͨ�����a:%d \n", a);


	system("pause");
}