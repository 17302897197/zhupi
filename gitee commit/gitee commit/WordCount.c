#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

void Usage()
{
	printf("Usage:/ WordCount -c/-w filepath");
}

int  readOfChar(FILE* fl)
{
	int ch = 0;
	while (fgetc(fl) != EOF)
	{
		ch++;
	}
	rewind(fl);//文件句柄移到开头
	return ch;
}

int  readOfWord(FILE*fl)
{
	//读单词，移动指针找到 “空格” 或者“逗号”	
	//开一段空间，读到内存进行控制，提高效率
	char buffer[1024];
	int start = 0;
	char ch;
	while ((ch = fgetc(fl)) != EOF)
	{
		buffer[start] = ch;
		start++;
	}
	buffer[start] = '\0';
	//已经读到buffer当中

	start = 0;
	int count = 0;
	while (buffer[start] != '\0')
	{
		while (buffer[start] == ' ' || buffer[start] == ',') start++;
		if (buffer[start] == '\0') break;
		count++;

		while (buffer[start] != ' ' && buffer[start] != ',')
		{
			if (buffer[start] == '\0') break;
			start++;
		}
		if (buffer[start] == '\0') break;
	}
	return count;
}

int main(int argc,char* argv[])
{
	if (argc != 3)
	{
		Usage();
		exit(1);
	}
		
	char* ppath = argv[2];
	FILE* fl = fopen(ppath,"r");
	if (fl == NULL)
	{
		assert("fopen");
	}

	
	if (strcmp(argv[1], "-c") == 0)//字符数
	{
		printf("文件%s  字符个数: %d",ppath, readOfChar(fl));//已经打开，直接读
	}
	else if (strcmp(argv[1], "-w") == 0)//单词数
	{
		printf("文件%s  单词个数: %d", ppath, readOfWord(fl));
	}
	else
	{
		printf("参数错误！");
	}

		
	fclose(fl);
	fl = NULL;
	return 0;
}