#include<stdio.h>
#include<string.h>

/*
* @Author: dwyaneini
* @Time: 2015-06-10
* @Language: C
* Description: 判断字符串是否回文(palindrome)
* Example: input: madam, output: YES;
*          input: teacher, output: No.
*
* Sol: 同时从字符串头尾开始向中间扫描字符串，若所有字符都一样，则为回文；否则，不是。
* 时间复杂度: O(n), 空间复杂度: O(1), n为字符串长度 
*/

int IsPalindrome(const char* str, int n);

int main()
{
	char s[1000];
	char* str = s;
	int is;            //接受IsPalindrome()的返回值，1是回文，0不是回文 
	printf("请输入待检验回文的字符串: \n");
	scanf("%s", str);
	
	is = IsPalindrome(str, strlen(str));
	if (is == 1)
		printf("\n是回文字符串！");
	else
		printf("\n不是回文字符串.");
	return 0;
}

int IsPalindrome(const char* str, int n)
{
	//处理非法输入
	if (str == NULL || n < 1)
		return 0;
	char* front;
	char* back;
	
	front = str;
	back = str + n - 1;
	
	while (front < back)
	{
		if (*front != *back)
			return 0;             //一旦某个位置不相等，则立即返回不是回文 
		++front;
		--back;
	} 
	return 1;
}