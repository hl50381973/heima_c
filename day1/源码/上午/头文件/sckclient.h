#ifndef _SCK_CLINT_H_
#define _SCK_CLINT_H_

//函数声明
// 1、客户端环境初始化
int sckClient_init(void **handle); //5 day
// 
// 2、客户端发送报文
int sckClient_send(void *handle, unsigned char *data, int datalen);
// 3、客户端端接受报文
int sckClient_rev(void *handle, unsigned char *out, int *outlen); //1
// 4、客户端环境释放 
int sckClient_destroy(void *handle);


#endif