#include "stdio.h"
#include "stdlib.h"

//typdef���� ����������
typedef int u32;
typedef char u8;

//�ṹ��ͱ���
struct _Teacher
{
	char	name[64];
	int		age;
};
typedef struct _Teacher Teacher;

int main21()
{
	//Teacher t1;
	printf("Teacher:%d \n", sizeof(Teacher));
	printf("u32:%d \n", sizeof(u32));
	printf("u8:%d \n", sizeof(u8));
	printf("hello.....\n");
	getchar();
	return 0;
}


//typedef char(*p)[5];

int mainxxx()
{
	char a[5];
	//�������ͱ����ǹ̶���С�ĵ��ڴ�飻
	//ָ��Ҳ��һ���������ͣ�ָ�����������ָ���ǣ������ڴ�ռ���������͡�
	//��ָ�ڴ�ռ���������ͣ�������ָ��Ĳ��������������͵ı������ڴ��Ĵ�С��
	//��p++�����������
	//p++�Ĳ���������������������

	char(*p2)[5];
	char(*p)[5] = &a;
	printf("sizeof(*p):%d \n", sizeof(*p));
	//p+1; p + sizeof(*p);

	printf("hello.....\n");
	getchar();
	return 0;
}

