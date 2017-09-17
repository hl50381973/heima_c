#include "stdlib.h"
#include "stdio.h"
#include "string.h"

#include "des.h"

//完成文件加密的操作
//
int FileSymEnc(char *filename1, char *filename2)
{
	int ret  =0;
	FILE *fp1 = NULL;
	FILE *fp2 = NULL;
	unsigned char plain[4096];
	int plainlen = 0;
	int writtenlen = 0;
	fp1 = fopen(filename1, "rb");
	if (fp1 == NULL)
	{
		ret = -1;
		goto End;	
	}
	fp2 = fopen(filename2, "wb");
	if (fp2 == NULL)
	{
		ret = -2;
		goto End;	
	}

	while (!feof(fp1))
	{
		//处理大于4k的数据
		plainlen = fread(plain, 1, 4096, fp1); //fread函数的返回值是返回的实际长度
		if (feof(fp1))
		{
			break;
		}
	}

	//处理小于4k的数据
	writtenlen = fwrite(plain, 1, plainlen, fp2);
	if (writtenlen != plainlen) //如果长度不相等，说明写文件发生了IO错我
	{
		ret = -3;
		printf("写新文件失败\n");
		goto End;
	}
	
End:
	if (fp1 != NULL) fclose(fp1);
	if (fp2 != NULL) fclose(fp2);

	return 0;
}

void main()
{
	int ret = 0;
	char *file1 = "c:/1.txt";
	char *file2 = "c:/222.txt";

	ret = FileSymEnc(file1, file2);
	if (ret != 0)
	{
		return ;
	}
	system("pause");
}