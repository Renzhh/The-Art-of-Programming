#include<stdio.h>
#include<string.h>

/*
*
* @Author: dwyaneini
* @Time: 2015-06-11
* @Language: C 
* Description: ������ַ�����������Ӵ��ĳ��� 
* Example: input: asitmadamitis, output: 5
* 
* Sol1: ö���м�λ�ã�Ȼ���ڸ�λ��������չ������¼�����µõ���Ļ��ĳ��� 
*
*/

int LongestPalindrome(const char *s, int n);

int main()
{
	char s[50];
	char* str=s;
	int n;
	printf("����������ת���ַ���:\n");
	scanf("%s", str); 
	n = strlen(str);
	
	printf("\n������Ӵ��ĳ���Ϊ:%d", LongestPalindrome(str, n)); 
	return 0;
}

int LongestPalindrome(const char *s, int n)
{
	int i, j, max, c;
	if (s == 0 || n < 1)
		return 0;
	max = 0;
	
	//i�ǻ����ִ����м�� 
	for (i = 0; i < n; i++)
	{
		//���Ĵ�����Ϊ���� 
		for (j = 0; (i - j >= 0) && (i + j < n); j++)
		{
			if (s[i - j] != s[i + j])
				break;
			c = 2 * j + 1;
		}
		//���Ĵ�����Ϊż�� 
		for (j = 0; (i - j >= 0) && (i + j < n); j++)
		{
			if (s[i - j] != s[i + j + 1])
				break;
			c = 2 * j + 2;
		}
		if (c > max)
			max = c;	
	}
	return max;
}