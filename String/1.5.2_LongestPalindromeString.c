#include<stdio.h>
#include<string.h>

/*
*
* @Author: dwyaneini
* @Time: 2015-06-11
* @Language: C 
* Description: 求给定字符串的最长回文子串的长度, 并输出最长回文子串 
* Example: input: asitmadamitis, output: 5, madam 
* 
* Sol1: 枚举中间位置，然后在该位置上用扩展发，记录并更新得到最长的回文长度 
*       并记录回文子串的中间位置，作为结构体成员变量返回，重新构造子串 
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
	printf("请输入原始字符串:\n");
	scanf("%s", str); 
	n = strlen(str);
	
	pstr = LongestPalindromeString(str, n);
	start = pstr.middle - (pstr.length / 2);
	if (pstr.length % 2 == 0)                   //若回文子串长度为偶, start后移一位 
		start += 1;
		
	printf("\n最长回文子串为:"); 
	for (i = start; i < (start + pstr.length); i++)
		printf("%c", str[i]);
	printf(", 其包含%d个字符", pstr.length);
	
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
	
	//i是回文字串的中间点 
	for (i = 0, point = 0; i < n; i++)
	{
		//回文串长度为奇数 
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
		//回文串长度为偶数 
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