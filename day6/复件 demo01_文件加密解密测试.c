#include "stdlib.h"
#include "stdio.h"
#include "string.h"

#include "des.h"
void main()
{
	int ret = 0;
	unsigned char plain[100];
	int plainlen = 0;

	unsigned char plain2[100];
	int plain2len = 0;
	
	unsigned char cryptdata[100];
	int cryptlen = 0;

	strcpy(plain, "abcdefgdafdsafdsafd");


	plainlen = strlen((char *)plain);//我已经知道在 unsigned char  buf中存放的确实是可见字节，所以转没有问题
	//用户使用的函数
	ret =  DesEnc(plain, plainlen, cryptdata, &cryptlen);
	if (ret != 0)
	{
		printf("func DesEnc() err:%d \n", ret);
		return;
	}
	
	//用户使用函数des解密
	ret =   DesDec(cryptdata, cryptlen, plain2, &plain2len);
	if (ret != 0)
	{
		printf("func DesDec() err:%d \n", ret);
		return;
	}

	if (plainlen != plain2len)
	{
		printf("两个明文长度不一致\n");
		return ;
	}

	if (memcmp(plain, plain2, plain2len)==0 )
	{
		printf("两个明文内容一致\n");
	}
	else
	{
		printf("两个明文内容不一致\n");
	}

		
	system("pause");
}