#include<stdio.h>
#include<string.h>

/*
*
* @Author: dwyaneini
* @Time: 2015-06-11
* @Language: C 
* Description: ������ַ�����������Ӵ��ĳ���, �����������Ӵ� 
* Example: input: asitmadamitis, output: 5, madam 
* 
* Sol1: ö���м�λ�ã�Ȼ���ڸ�λ��������չ������¼�����µõ���Ļ��ĳ��� 
*       ����¼�����Ӵ����м�λ�ã���Ϊ�ṹ���Ա�������أ����¹����Ӵ� 
*
*/

typedef struct {
	int middle;
	int length;
} PalindromeStringTag;

PalindromeStringTag LongestPalindromeString(const char *s, int n);

int main()
{
	char s[100];
	char* str=s;
	int i, n, start;
	PalindromeStringTag pstr;
	printf("������ԭʼ�ַ���:\n");
	scanf("%s", str); 
	n = strlen(str);
	
	pstr = LongestPalindromeString(str, n);
	start = pstr.middle - (pstr.length / 2);
	if (pstr.length % 2 == 0)                   //�������Ӵ�����Ϊż, start����һλ 
		start += 1;
		
	printf("\n������Ӵ�Ϊ:"); 
	for (i = start; i < (start + pstr.length); i++)
		printf("%c", str[i]);
	printf(", �����%d���ַ�", pstr.length);
	
	return 0;
}

PalindromeStringTag LongestPalindromeString(const char *s, int n)
{
	int i, j, max, c, point;
	PalindromeStringTag pst;
	if (s == 0 || n < 1)
	{
		pst.middle = 0;
		pst.length = 0;
		return pst;
	}
	max = 0;
	
	//i�ǻ����ִ����м�� 
	for (i = 0, point = 0; i < n; i++)
	{
		//���Ĵ�����Ϊ���� 
		for (j = 0; (i - j >= 0) && (i + j < n); j++)
		{
			if (s[i - j] != s[i + j])
				break;
			c = 2 * j + 1;
		}
		if (c > max)
		{
			max = c;
			point = i;	
		}	
		//���Ĵ�����Ϊż�� 
		for (j = 0; (i - j >= 0) && (i + j < n); j++)
		{
			if (s[i - j] != s[i + j + 1])
				break;
			c = 2 * j + 2;
		}
		if (c > max)
		{
			max = c;
			point = i;	
		}	
	}
	pst.middle = point;
	pst.length = max;
	return pst;
}