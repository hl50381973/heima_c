#include "stdlib.h"
#include "stdio.h"
#include "string.h"


typedef struct _SCK_HANDLE {
	char		version[16];
	char	    serverip[16];
	int		serverport;
	unsigned char *buf ;
	int				buflen;
}SCK_HANDLE;



//客户端初始化 获取handle上下
__declspec(dllexport) 
int cltSocketInit(void **handle /*out*/)
{
	int ret = 0;
	SCK_HANDLE *sh = NULL;
	sh = (SCK_HANDLE *)malloc(sizeof(SCK_HANDLE));
	if (sh == NULL)
	{
		ret = -1;
		printf("func cltSocketInit() err: %d, malloc err....", ret);
		return ret;
	}
	memset(sh, 0, sizeof(SCK_HANDLE));
	strcpy(sh->serverip, "192.168.0.128");
	sh->serverport= 88;

	*handle = sh;
	return ret;
}

//客户端发报文
__declspec(dllexport) 
int cltSocketSend(void *handle /*in*/, unsigned char *buf /*in*/,  int buflen /*in*/)
{
	int		ret = 0;
	SCK_HANDLE *sh = NULL; 
	
	if (handle==NULL || buf==NULL)
	{
		ret = -1;
		printf("func cltSocketSend() err: %d, (handle==NULL || buf==NULL)", ret);
		return ret;
	}
	sh = (SCK_HANDLE *)handle ;
	sh->buf = (char *)malloc(buflen);
	if (sh->buf == NULL)
	{
		ret = -2;
		printf("func cltSocketSend() err: %d, (buflen:%d)", ret, buflen);
		return ret;
	}
	memcpy(sh->buf, buf, buflen);
	sh->buflen = buflen;

	return ret;
}


//客户端收报文
__declspec(dllexport) 
int cltSocketRev(void *handle /*in*/, unsigned char *buf /*in*/, int *buflen /*in out*/)
{
	int  ret = 0;
	SCK_HANDLE *sh = NULL; 

	if (handle==NULL || buf==NULL || buflen==NULL)
	{
		ret = -1;
		printf("func cltSocketSend() err: %d, ((handle==NULL || buf==NULL || buflen==NULL))", ret);
		return ret;
	}

	sh = (SCK_HANDLE *)handle;

	memcpy(buf, sh->buf, sh->buflen);
	*buflen  = sh->buflen;

	if (sh->buf != NULL)
	{
		free(sh->buf);
		sh->buf = NULL; //把状态回到原始
		sh->buflen = 0;
	}
	return ret;
}


//客户端释放资源
__declspec(dllexport) 
int cltSocketDestory(void *handle/*in*/)
{
	int  ret = 0;
	SCK_HANDLE *sh = NULL; 

	if (handle==NULL )
	{
		ret = -1;
		printf("func cltSocketSend() err: %d, ((handle==NULL )", ret);
		return ret;
	}

	sh = (SCK_HANDLE *)handle;
	
	if (sh->buf != NULL)
	{
		free(sh->buf);
		sh->buf = NULL;
		sh->buflen = 0;
	}
	free(sh);

	return ret;
}

//------------------第一套api接口---End-----------------------------------//