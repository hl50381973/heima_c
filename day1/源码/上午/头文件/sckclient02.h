
//�������� ����ͷ�ļ���ΰ���

#ifndef _SCK_CLINT02_H_
#define _SCK_CLINT02_H_

#ifdef  __cplusplus
extern "C" {
#endif

//��������
// 1���ͻ��˻�����ʼ��
int sckClient_init2(void **handle); //5 day
// 
// 2���ͻ��˷��ͱ���
int sckClient_send2(void *handle, unsigned char *data, int datalen);
// 3���ͻ��˶˽��ܱ���
int sckClient_rev2(void *handle, unsigned char **out, int *outlen); //1
int sckClient_rev2_Free(void **p); //1
// 4���ͻ��˻����ͷ� 
int sckClient_destroy2(void **handle);

#ifdef  __cplusplus
}
#endif


#endif