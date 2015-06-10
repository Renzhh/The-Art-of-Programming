#include<stdio.h>
#include<string.h>

/*
* @Author: dwyaneini
* @Time: 2015-06-09
* @Language: C 
* Description: 快速判断字符串b中所有字母是否都在字符串a中, 且a的长度比b的长 
* (规定: 字符串中只包含大写英文字母)
* Example: input: a: "ABCDEF", b: "BEBE", output: True
*          input: a: "ABCDEF", b: "BFH", output: False, "H" not included in string b 
*
* Sol1(常规思路) :
* 针对字符串b中每一个字符，逐个与a中每个字符比较，看是否存在于a中。时间复杂度为O(m*n) 
*
* Sol2(先排序后轮询):
* 先对两字符串的字母进行排序，然后在同时对两个字串依次轮询
* 排序常规情况需O(mlogm)+O(nlogn)次操作, 线性扫描需要O(m+n)次操作 
*
* Sol:
* 将长字符串a中的所有字符都放入一个Hashtable里, 然后轮询短字符串b, 查看b的每个字符是否都在Hashtable里 
* 本段代码对字符串a，用位运算(26bit整数表示)计算出一个"Signature", 再用b中的字符到a里进行查找 
*/

int StringContain(char* a, char* b);

int main()
{
	char s1[100], s2[99];
	int isContain;        //获取函数StringContain的返回值，1表示字符串a包含b，其他值均表示不包含 
	char notExistChar;    //当isContain不为1时，获取字符串b中包含而a中不包含的字符 
	char* a = s1;
	char* b = s2;
	printf("请输入字符串a: (长度不超过100的大写英文字母)\n");
	scanf("%s", a);
	printf("输入字符串b: (长度不超过99的大写英文字母)\n");
	scanf("%s", b);
	
	isContain = StringContain(a, b);
	if (isContain == 1)
		printf("\nTrue, 字符串\"%s\"包含在\"%s\"中.\n", b, a);
	else
	{
		notExistChar = (char)('A' + isContain); 
		printf("\nFalse, 字符串\"%s\"中存在\"%s\"没有的字符 (%c)!\n", b, a, notExistChar);	
	}
	return 0;
}

int StringContain(char* a, char* b)
{
	int flag = 1;  //默认1，表示a包含b 
	int hash = 0;
	int i;
	for (i = 0; i < strlen(a); i++)
	{
		//hash = hash 按位或 ( 1左移 (a[i]-'A')位) 
		hash |= (1 << (a[i] - 'A'));
	}
	for (i = 0; i < strlen(b); i++)
	{
		if ((hash & (1 << (b[i] - 'A'))) == 0) 
		{ 
//			flag = 0;
			flag = (b[i] - 'A');
			return flag;
		} 
	}
	return flag;
	
}