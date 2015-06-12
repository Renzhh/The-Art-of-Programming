#include<stdio.h>
#include<string.h>

/*
*
* @Author: dwyaneini
* @Time: 2015-06-11
* @Language: C
* Description: 求给定字符串的最长回文子串的长度
* Example: input: asitmadamitis, output: 5
*
* Sol1: 枚举中间位置，然后在该位置上用扩展发，记录并更新得到最长的回文长度
*
* Sol2: 采用Manacher算法，该算法时间复杂度为O(n)
* 基本思路：在每个字符的两边都插入一个特殊的符号#，将所有可能的奇数或偶数长度的回文子串都转换成了奇数长度；
* 为了进一步减少编码的复杂度，可以在字符串的开始加入另一个特殊字符，这样就不用特殊处理越界问题。
*/

int LongestPalindrome(const char *s, int n);

int main()
{
	char s[50];
	char* str=s;
	int n;
	printf("请输入的字符串:\n");
	scanf("%s", str);
	n = strlen(str);

	printf("\n最长回文子串的长度为:%d", LongestPalindrome(str, n));
	return 0;
}

int LongestPalindrome(const char *s, int n)
{
	int i, j, max, c;
	if (s == 0 || n < 1)
		return 0;
	max = 0;

	//i是回文字串的中间点
	for (i = 0; i < n; i++)
	{
		//回文串长度为奇数
		for (j = 0; (i - j >= 0) && (i + j < n); j++)
		{
			if (s[i - j] != s[i + j])
				break;
			c = 2 * j + 1;
		}
		if (c > max)
			max = c;
		//回文串长度为偶数
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
