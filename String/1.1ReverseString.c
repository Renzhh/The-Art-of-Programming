#include<stdio.h>
#include<string.h>

/*
* @Author: dwyaneini
* @Time: 2015-06-04
* Description: 实现字符串的旋转，要求时间复杂度为O(n)，空间复杂度O(1)，n为字符串的长度
* Example: input: abcdef (将前2个字符移动到字符串尾部), output: cdefab
*/
void ReverseString(char* s, int from, int to);
void LeftRotateString(char* s, int n, int m);

int main()
{
	char s[50];
	char* input=s;
	int m;
	int n;
	printf("请输入欲旋转的字符串：\n");
	scanf("%s", input); 
	n = strlen(input);
	printf("欲旋转的字符个数：\n");
	scanf("%d", &m);
	LeftRotateString(input, n, m);
	printf("旋转后的字符串：");
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
	//m为移动的最前面字符个数 
	m %= n;
	ReverseString(s, 0, m-1);
	ReverseString(s, m, n-1);
	ReverseString(s, 0, n-1); 
	
}