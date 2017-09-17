#include "stdlib.h"
#include "string.h"
#include "stdio.h"
#include "socketclientdll.h"

void main()
{
	int ret = 0;

	void *handle = NULL;

	unsigned char buf[1024]; /*in*/  
	int buflen = 10;

	unsigned char out[1024] = {0}; /*in*/
	int outlen = 0;

	strcpy(buf, "aadd3456789012233ddddddddddddddaaaaaaaaaaa");
	//�ͻ��˳�ʼ�� ��ȡhandle����
	//���е������Ļ��� 
	ret = cltSocketInit(&handle/*out*/);
	if (ret !=0)
	{
		printf("func cltSocketInit() err :%d \n", ret);
		return ;
	}

// 	//�ͻ��˷�����
	ret = cltSocketSend(handle /*in*/, buf /*in*/,buflen /*in*/);
	if (ret !=0)
	{
		printf("func cltSocketSend() err :%d \n", ret);
		return ;
	}
// 
// 	//�ͻ����ձ���
	ret = cltSocketRev(handle /*in*/, out /*in*/, &outlen /*in out*/);
	if (ret != 0)
	{
		printf("func cltSocketRev() err :%d \n", ret);
		return ;
	}
	printf("out: %s \n", out);
// 
// 	//�ͻ����ͷ���Դ
	ret = cltSocketDestory(handle/*in*/);
	if (ret != 0)
	{
		printf("func cltSocketDestory() err :%d \n", ret);
		return ;
	}

	system("pause");
}