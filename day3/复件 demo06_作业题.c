//#include "stdlib.h"
//#include "stdio.h"
//#include "string.h"
//
////提取p所指内存空间 数据 前后空格 
//int trimSpaceStr03( char *p, char *buf2)
//{
//	int ret = 0;
//
//	int ncount = 0;
//	int i, j;
//	i = 0;
//	j = strlen(p) -1;
//
//	while (isspace(p[i]) && p[i] != '\0')
//	{
//		i++;
//	}
//
//	while (isspace(p[j]) && j>0 )
//	{
//		j--;
//	}
//
//	ncount = j - i + 1;
//	//
//	strncpy(buf2, p+i, ncount);
//	buf2[ncount] = '\0';
//	return ret;
//}
//
//int getKeybyValue(char *pKeyValude, char *pKey, char *pValude)
//{
//	char rv = 0;
//	char *p = NULL;
//
//	if (pKeyValude==NULL  )
//	{
//		rv = -1;
//		printf("func getKeybyValue() err:%d pKeyValude \n", rv);
//		return rv;
//	}
//	if ( pKey==NULL )
//	{
//		rv = -1;
//		printf("func getKeybyValue() err:%d pKey=NULL \n", rv);
//		return rv;
//	}
//	if ( pValude==NULL )
//	{
//		rv = -1;
//		printf("func getKeybyValue() err:%d pValude \n", rv);
//		return rv;
//	}
//
//	//1 在pKeyValude中查找是否有关键字pKey
//	p = strstr(pKeyValude, pKey);
//	if (p == NULL)
//	{
//		rv = -1;
//		printf("func getKeybyValue() err:%d 查找没有关键字pKey  \n", rv);
//		return rv;
//	}
//	p = p + strlen(pKey); //为下一次检索做准备
//
//	//2 有没有=
//	p = strstr(p, "=");
//	if (p == NULL)
//	{
//		rv = -2;
//		printf("func getKeybyValue() err:%d 查找没有=  \n", rv);
//		return rv;
//	}
//	p = p + 1; //为下一次提取valude做准备
//	
//	//3 提取按照要求的valude
//	rv = trimSpaceStr03(p, pValude);
//	if (rv != 0)
//	{
//		printf("func trimSpaceStr03() err:%d \n", rv);
//		return rv;
//	}
//
//	return rv;
//}
//
//
//int getKeybyValue2_ERR(char *pKeyValude, char *pKey, char *pValude)
//{
//	char rv = 0;
//	char *p = NULL;
//
//	//1 在pKeyValude中查找是否有关键字pKey
//	p = strstr(pKeyValude, pKey);
//	if (p != NULL)
//	{
//		p = p + strlen(pKey); //为下一次检索做准备
//
//		//2 有没有=
//		p = strstr(p, "=");
//		if (p != NULL)
//		{
//			p = p + 1; //为下一次提取valude做准备
//
//			//3 提取按照要求的valude
//			rv = trimSpaceStr03(p, pValude);
//			if (rv == 0)
//			{
//				printf("func trimSpaceStr03() err:%d \n", rv);
//				return rv;
//			}
//			else
//			{
//		
//			}
//		}
//		else
//		{
//
//		}
//		
//	}
//	else
//	{
//
//	}
//
//
//	return rv;
//}
//void main()
//{
//	int ret = 0;
//	char KeyValude[] = "key1  =   valude1";
//	char Key[] = "key1";
//
//	char Valude[1024] =  {0};
//
//	ret = getKeybyValue(KeyValude, Key, Valude);
//	if (ret != 0)
//	{
//		printf("func getKeybyValue() err:%d \n", ret);
//		return;
//	}
//	printf("Valude:%s \n", Valude);
//	system("pause");
//}