#ifndef _SCK_CLINT_H_
#define _SCK_CLINT_H_

//��������
// 1���ͻ��˻�����ʼ��
int sckClient_init(void **handle); //5 day
// 
// 2���ͻ��˷��ͱ���
int sckClient_send(void *handle, unsigned char *data, int datalen);
// 3���ͻ��˶˽��ܱ���
int sckClient_rev(void *handle, unsigned char *out, int *outlen); //1
// 4���ͻ��˻����ͷ� 
int sckClient_destroy(void *handle);


#endif