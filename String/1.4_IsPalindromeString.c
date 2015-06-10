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
* Sol1: 同时从字符串头尾开始向中间扫描字符串，若所有字符都一样，则为回文；否则，不是。
* 时间复杂度: O(n), 空间复杂度: O(1), n为字符串长度 
*
* Sol2: 从字符串中间向两端扫描。
* !当应用于判断单链表结构是否为"回文"时， 可采用经典的快慢指针方法，即先定位到链表的中间位，
* 再将链表的后半逆置，最后用两个指针同时从链表头部和中间开始同时遍历并比较即可。 
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

/*
*
* 从字符串两端向中间扫描 
*
*/
 
/* 
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
*/

/*
*
* 从字符串中间向两端扫描 
*
*/

int IsPalindrome(const char* str, int n)
{
	//处理非法输入
	if (str == NULL || n < 1)
		return 0;
	char* first;
	char* second;
	
	int m = ((n >> 1) - 1) >= 0 ? (n >> 1) - 1 : 0;      //m是str的中间点 
	first = str + m;
	second = str+ n - 1 - m;
	
	while (first >= str)
	{
		if(*first != *second)
			return 0;
		first--;
		second++;
	}
	return 1;	
} 