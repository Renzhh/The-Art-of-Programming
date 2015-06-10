#include<stdio.h>
#include<string.h>

/*
* @Author: dwyaneini
* @Time: 2015-06-10
* @Language: C
* Description: �ж��ַ����Ƿ����(palindrome)
* Example: input: madam, output: YES;
*          input: teacher, output: No.
*
* Sol: ͬʱ���ַ���ͷβ��ʼ���м�ɨ���ַ������������ַ���һ������Ϊ���ģ����򣬲��ǡ�
* ʱ�临�Ӷ�: O(n), �ռ临�Ӷ�: O(1), nΪ�ַ������� 
*/

int IsPalindrome(const char* str, int n);

int main()
{
	char s[1000];
	char* str = s;
	int is;            //����IsPalindrome()�ķ���ֵ��1�ǻ��ģ�0���ǻ��� 
	printf("�������������ĵ��ַ���: \n");
	scanf("%s", str);
	
	is = IsPalindrome(str, strlen(str));
	if (is == 1)
		printf("\n�ǻ����ַ�����");
	else
		printf("\n���ǻ����ַ���.");
	return 0;
}

int IsPalindrome(const char* str, int n)
{
	//����Ƿ�����
	if (str == NULL || n < 1)
		return 0;
	char* front;
	char* back;
	
	front = str;
	back = str + n - 1;
	
	while (front < back)
	{
		if (*front != *back)
			return 0;             //һ��ĳ��λ�ò���ȣ����������ز��ǻ��� 
		++front;
		--back;
	} 
	return 1;
}