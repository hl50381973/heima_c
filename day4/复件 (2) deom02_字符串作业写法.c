#include "stdio.h"
#include "stdlib.h"
#include "string.h"

int spitString03(const char *buf1, char c, char **mypp, int *num)
{
	int ret = 0;
	char *p = NULL;
	char *pTmp = NULL;
	int ncount = 0;
	if (buf1==NULL ||  num==NULL)
	{
		return -1;
	}
	//步骤1 初始化条件 pTmp,p都执行检索的开头
	p = buf1;
	pTmp = buf1;
	do 
	{
		//步骤2 strstr strchr，会让p后移 	在p和pTmp之间有一个差值
		p = strchr(p, c);
		if (p == NULL) //没有找到则跳出来
		{
			break;
		}
		else 
		{

			//挖字符串
			strncpy(mypp[ncount], pTmp, p-pTmp);
			mypp[ncount][p-pTmp] = '\0';
			ncount++;

			//步骤3 让p和pTmp重新初始化，达到检索的条件
			pTmp = p  = p + 1;
		}

	} while (*p != '\0');
	//printf("ncout:%d\n", ncount);
	*num = ncount;
	return ret;
}

//分配内存函数
char **getMem(int num)
{
	int i = 0;
	//char **pp = (char **)malloc(sizeof(num*sizeof(char *)));
	char **pp = (char **)malloc(num* sizeof(char *) );
	if (pp == NULL)
	{
		return NULL;
	}
	for (i=0; i<num; i++)
	{
		pp[i] = (char *)malloc(100);
		if (pp[i] == NULL)
		{
			return NULL;
		}
	}
	return pp;
}

int FreeMem(char **pp, int num)
{
	int i = 0;
	if (pp == NULL)
	{
		 return -1;
	}
	for (i=0; i<num; i++)
	{
		free(pp[i]);
	}
	free(pp);
	return 0;
}

//对付1个入口多个出口的问题。。。有方法
void main()
{
	int			ret = 0, i = 0;
	int			num = 0;
	int			numArray = 10;
	const char	*buf1 = "abcdef,acccd,";
	char			c = ',';

	char			**pp =  NULL;
	char			**pp2 =  NULL;

	//"ab"
	//char *buf = (char *)malloc(strlen("ab") + 1);
	//strcpy(buf, "ab");


	pp = getMem(numArray);
	if (pp == NULL)
	{
		ret = -1;
		printf("func getMem() err:%d\n", ret);
		goto End;
	}

	pp2 = getMem(numArray);
	if (pp2 == NULL)
	{
		ret = -2;
		printf("func getMem() err:%d\n", ret);
		goto End;
	}
		
	ret =  spitString03(buf1, c, pp, &num);
	if (ret == 0) //故意写错
	{
		printf("func spitString() err:%d\n", ret);
		goto End;
	}

	for (i=0; i<num; i++)
	{
		printf("%s\n", pp[i]);
	}

End:

	if (pp != NULL)
	{
		FreeMem(pp, numArray);
	}
		
	if (pp2 != NULL)
	{
		FreeMem(pp2, numArray);
	}
	
	system("pause");
}


