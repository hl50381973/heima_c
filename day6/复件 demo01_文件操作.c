#include "stdio.h"
#include "string.h"
#include "stdlib.h"

void main01()
{
	int i = 0;
	FILE *fp = NULL;
	char a[100] = "abcdefghijkddddsssss";

	char *fname = "c:\\1.txt";
	char *fname2 = "c:/1.txt"; //统一的用45度斜杠
	 
	fp = fopen(fname2, "a+"); //不管文件是否存在，新建文件
	if (NULL == fp)
	{
		printf("func fopen（） err: \n");
	}

	for (i=0; i<strlen(a); i++)
	{
		fputc(a[i], fp);
	}


	if (fp != NULL)
	{
		fclose(fp);
	}
	

	system("pause");
}

void main02()
{
	int i = 0;
	FILE *fp = NULL;

	char *fname = "c:\\1.txt";
	char *fname2 = "c:/1.txt"; //统一的用45度斜杠

	fp = fopen(fname2, "r"); //不管文件是否存在，新建文件
	if (NULL == fp)
	{
		printf("func fopen（） err: \n");
	}

	while( !feof(fp))
	{
		char tmpC = fgetc(fp);
		printf("%c", tmpC);

	}

	if (fp != NULL)
	{
		fclose(fp);
	}


	system("pause");
}

void main()
{
	 //main01();
	main02();
}