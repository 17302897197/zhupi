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
	rewind(fl);//�ļ�����Ƶ���ͷ
	return ch;
}

int  readOfWord(FILE*fl)
{
	//�����ʣ��ƶ�ָ���ҵ� ���ո� ���ߡ����š�	
	//��һ�οռ䣬�����ڴ���п��ƣ����Ч��
	char buffer[1024];
	int start = 0;
	char ch;
	while ((ch = fgetc(fl)) != EOF)
	{
		buffer[start] = ch;
		start++;
	}
	buffer[start] = '\0';
	//�Ѿ�����buffer����

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

	
	if (strcmp(argv[1], "-c") == 0)//�ַ���
	{
		printf("�ļ�%s  �ַ�����: %d",ppath, readOfChar(fl));//�Ѿ��򿪣�ֱ�Ӷ�
	}
	else if (strcmp(argv[1], "-w") == 0)//������
	{
		printf("�ļ�%s  ���ʸ���: %d", ppath, readOfWord(fl));
	}
	else
	{
		printf("��������");
	}

		
	fclose(fl);
	fl = NULL;
	return 0;
}