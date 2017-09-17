
//条件编译 避免头文件多次包含

#ifndef _SCK_CLINT02_H_
#define _SCK_CLINT02_H_

#ifdef  __cplusplus
extern "C" {
#endif

//函数声明
// 1、客户端环境初始化
int sckClient_init2(void **handle); //5 day
// 
// 2、客户端发送报文
int sckClient_send2(void *handle, unsigned char *data, int datalen);
// 3、客户端端接受报文
int sckClient_rev2(void *handle, unsigned char **out, int *outlen); //1
int sckClient_rev2_Free(void **p); //1
// 4、客户端环境释放 
int sckClient_destroy2(void **handle);

#ifdef  __cplusplus
}
#endif


#endif