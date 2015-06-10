#include<stdio.h>
#include<string.h>

/*
* @Author: dwyaneini
* @Time: 2015-06-10
* @Language: C 
* Description: 将仅由数字组成的字符串，转换成整数并输出 
* (规定: 不使用库函数atoi())
* Example: input: "123456789", output: 123456789
*  
* Sol:
* 从左至右扫描字符串，将之前得到额数字乘以10，再加上当前字符表示的数字 
* 
* Tips:
* 1. 空指针输入, 在使用指针前需要先判断指针是否为空 
* 2. 正负符号, 若第一个字符为'+' or '-', 需要将得到的整数转换成正/负整数 
* 3. 非法字符, 若字符串中含有非数字的字符，忽略它们，只转换数字部分 
* 4. 整型溢出, 若输入的字符串超过了INT的最大范围导致溢出，则输出最大正整数/最小负整数 
*/

static const int MAX_INT = (int)((unsigned)~0 >> 1);
static const int MIN_INT = -(int)((unsigned)~0 >> 1) - 1;

int StrToInt(const char* str);

int main()
{
	char str[100];
	int number;     
	char* str1 = str;
	printf("请输入需要转成整数的字符串: \n");
	scanf("%s", str);
	
	number = StrToInt(str1);
	printf("\n经转换后的整数为: %d\n", number);
	return 0;
}

int StrToInt(const char* str)
{
	unsigned int n = 0;         //存放转换的结果 
	
	//判断输入的字符串是否为空
	if (str == 0)
	{
		return 0;
	} 
	
	//处理空格
	while( isspace(*str))
		++str;
	
	//处理正负
	int sign = 1;                //用来处理数字的正负，当为正时sign>0, 当为负时sign<0 
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		++str;
	} 
	
	//确定是数字后才执行循环
	while (*str)
	{
		if (isdigit(*str))
		{
		    //处理溢出
			int c = *str - '0';       //当前数字 
			if (sign > 0 && (n > MAX_INT / 10 || (n == MAX_INT / 10 && c > MAX_INT % 10) )) 
			{
				n = MAX_INT;
				break;
			}
			else if (sign < 0 && (n > (unsigned)MIN_INT / 10 || (n == (unsigned)MIN_INT / 10 && c > (unsigned)MIN_INT % 10)))
			{
				n = MIN_INT;
				break;
			}
			
			//把之前得到的数字乘以10, 再加上当前字符表示的数字
			n = n * 10 + c;
		}
		++str;		
	} 
	return (sign > 0) ? n : (-n);
}