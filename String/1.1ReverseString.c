#include<stdio.h>
#include<string.h>

/*
* @Author: dwyaneini
* @Time: 2015-06-04
* Description: ʵ���ַ�������ת��Ҫ��ʱ�临�Ӷ�ΪO(n)���ռ临�Ӷ�O(1)��nΪ�ַ����ĳ���
* Example: input: abcdef (��ǰ2���ַ��ƶ����ַ���β��), output: cdefab
*/
void ReverseString(char* s, int from, int to);
void LeftRotateString(char* s, int n, int m);

int main()
{
	char s[50];
	char* input=s;
	int m;
	int n;
	printf("����������ת���ַ�����\n");
	scanf("%s", input); 
	n = strlen(input);
	printf("����ת���ַ�������\n");
	scanf("%d", &m);
	LeftRotateString(input, n, m);
	printf("��ת����ַ�����");
	printf("%s\n", input);
	return 0;
}

void ReverseString(char* s, int from, int to)
{
	while(from < to)
	{
		char t = s[from];
		s[from++] = s[to];
		s[to--] = t;
	}
}

void LeftRotateString(char* s, int n, int m)
{
	//mΪ�ƶ�����ǰ���ַ����� 
	m %= n;
	ReverseString(s, 0, m-1);
	ReverseString(s, m, n-1);
	ReverseString(s, 0, n-1); 
	
}