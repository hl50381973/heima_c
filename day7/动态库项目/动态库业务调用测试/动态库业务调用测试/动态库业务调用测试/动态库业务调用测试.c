#include "stdlib.h"
#include "string.h"
#include "stdio.h"

void main()
{
	int ret = 0;

	void *handle = NULL;
	//客户端初始化 获取handle上下
	ret = cltSocketInit(&handle/*out*/);
	if (ret !=0)
	{
		printf("func cltSocketInit() err :%d \n", ret);
		return ;
	}

// 	//客户端发报文
// 	int cltSocketSend(void *handle /*in*/, unsigned char *buf /*in*/,  int buflen /*in*/);
// 
// 	//客户端收报文
// 	int cltSocketRev(void *handle /*in*/, unsigned char *buf /*in*/, int *buflen /*in out*/);
// 
// 	//客户端释放资源
// 	int cltSocketDestory(void *handle/*in*/);

	system("pause");
}