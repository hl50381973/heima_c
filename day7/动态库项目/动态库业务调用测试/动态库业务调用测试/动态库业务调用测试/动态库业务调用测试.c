#include "stdlib.h"
#include "string.h"
#include "stdio.h"

void main()
{
	int ret = 0;

	void *handle = NULL;
	//�ͻ��˳�ʼ�� ��ȡhandle����
	ret = cltSocketInit(&handle/*out*/);
	if (ret !=0)
	{
		printf("func cltSocketInit() err :%d \n", ret);
		return ;
	}

// 	//�ͻ��˷�����
// 	int cltSocketSend(void *handle /*in*/, unsigned char *buf /*in*/,  int buflen /*in*/);
// 
// 	//�ͻ����ձ���
// 	int cltSocketRev(void *handle /*in*/, unsigned char *buf /*in*/, int *buflen /*in out*/);
// 
// 	//�ͻ����ͷ���Դ
// 	int cltSocketDestory(void *handle/*in*/);

	system("pause");
}