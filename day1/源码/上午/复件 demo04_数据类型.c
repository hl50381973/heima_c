#include "stdlib.h"
#include "string.h"
#include "stdio.h"


//�������ͷ�Ϊ���֣�һ���Ǽ򵥵��������ͣ�һ���Ǹ��ӵ��������͡�
//�������ӵ��������Ͳ����ü򵥵��������͵�˼άȥ˼��������ש

typedef int u32 ;

struct Teacer
{
	char name[100];
	int age ;
};

typedef struct Teacer Teacer;

typedef struct _Teacer2
{
	char name[100];
	int age ;
}Teacer2;


void main(void)
{
	int b ; //����c���������ҷ���4���ֽڵ��ڴ�

	int a[10];  //����c���������ҷ���40���ֽڵ��ڴ�
	//printf("&a:%d, a:%d \n" , &a, a);

	//ͬ�������� +1 ��һ�� 
	//�������Ͳ�һ�� 
	printf("&a+1:%d, a+1:%d \n", &a +1 , a +1);

	printf("sizeof(int):%d\n", sizeof(int));

	printf("sizeof(int *):%d\n", sizeof(int *));

	printf("sizeof(u32):%d\n", sizeof(u32));

	/*
	�������ͣ�ѹ����ѧ�ߵ�������ɽ
		1����������
		2������ָ��
		3���������ͺ�����ָ��Ĺ�ϵ
	*/


	system("pause");
}