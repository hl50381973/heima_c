#include "stdlib.h"
#include "string.h"
#include "stdio.h"

//�����鵱�����������Ļ���ʱ����˻�Ϊָ�� 
int printfArray(int a[])
{
	int i = 0;
	printf("����֮ǰ\n ");
	for (i=0; i<10; i++)
	{
		printf("%d ", a[i]);
	}
	return 0;
}

int printfArray03(int a[], int num)
{
	
	int i = 0;
	printf("����֮ǰ\n ");
	for (i=0; i<num; i++)
	{
		printf("%d ", a[i]);
	}
	return 0;
	
}

int printfArray04(int *a, int num)
{

	int i = 0;
	printf("����֮ǰ\n ");
	for (i=0; i<num; i++)
	{
		printf("%d ", a[i]);
	}
	return 0;

}


//int a[10]  -=-->int a[] ---->int *a
//�����������βε�ʱ��������β��ж���int a[10]��䣬
//c/c++������ �����Ż���������������
//int a[10]  -=-->int a[] ---->int *a
//�ܽ᣺�������õ�ʱ�򣬰������׵�ַ����Ч���ݳ��ȴ��������ú�����������ȷ������

int printfArray02(int a[10])
{
	int i = 0;
	int num = 0;
	printf("����֮ǰ\n ");
	num = sizeof(a)/sizeof(*a);
	printf("num:%d \n", num);
	
	for (i=0; i<10; i++)
	{
		printf("%d ", a[i]);
	}
	return 0;
}

int sortArray(int a[])
{
	int i = 0, j = 0;
	int tmp;
	for (i=0; i<10; i++) //���ѭ��
	{
		for (j=i+1; j<10; j++) //�ڲ�ѭ��
		{
			if (a[i] > a[j])
			{
				tmp = a[i];
				a[i] = a[j];
				a[j] = tmp;
			}
		}
	}
	return 0;
}
void main()
{
	//�������� ��ӡ���� ��������
	int i = 0, j = 0;
	int num2;
	int a[10] = {1,3,4,5,65,76,7,34,4,32};
	int tmp;

	num2 = sizeof(a)/sizeof(*a);
	printf("num2:%d \n", num2);
	printf("����֮ǰ\n ");
// 	for (i=0; i<10; i++)
// 	{
// 		printf("%d ", a[i]);
// 	}

	printfArray02(a);
	sortArray(a);
// 	for (i=0; i<10; i++) //���ѭ��
// 	{
// 		for (j=i+1; j<10; j++) //�ڲ�ѭ��
// 		{
// 			if (a[i] > a[j])
// 			{
// 				tmp = a[i];
// 				a[i] = a[j];
// 				a[j] = tmp;
// 			}
// 		}
// 	}

	printf("����֮��\n ");
// 	for (i=0; i<10; i++)
// 	{
// 		printf("%d ", a[i]);
// 	}

	printfArray(a);


	printf("hello.....\n");
	system("pause");
}