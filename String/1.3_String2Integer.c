#include<stdio.h>
#include<string.h>

/*
* @Author: dwyaneini
* @Time: 2015-06-10
* @Language: C 
* Description: ������������ɵ��ַ�����ת������������� 
* (�涨: ��ʹ�ÿ⺯��atoi())
* Example: input: "123456789", output: 123456789
*  
* Sol:
* ��������ɨ���ַ�������֮ǰ�õ������ֳ���10���ټ��ϵ�ǰ�ַ���ʾ������ 
* 
* Tips:
* 1. ��ָ������, ��ʹ��ָ��ǰ��Ҫ���ж�ָ���Ƿ�Ϊ�� 
* 2. ��������, ����һ���ַ�Ϊ'+' or '-', ��Ҫ���õ�������ת������/������ 
* 3. �Ƿ��ַ�, ���ַ����к��з����ֵ��ַ����������ǣ�ֻת�����ֲ��� 
* 4. �������, ��������ַ���������INT�����Χ�����������������������/��С������ 
*/

static const int MAX_INT = (int)((unsigned)~0 >> 1);
static const int MIN_INT = -(int)((unsigned)~0 >> 1) - 1;

int StrToInt(const char* str);

int main()
{
	char str[100];
	int number;     
	char* str1 = str;
	printf("��������Ҫת���������ַ���: \n");
	scanf("%s", str);
	
	number = StrToInt(str1);
	printf("\n��ת���������Ϊ: %d\n", number);
	return 0;
}

int StrToInt(const char* str)
{
	unsigned int n = 0;         //���ת���Ľ�� 
	
	//�ж�������ַ����Ƿ�Ϊ��
	if (str == 0)
	{
		return 0;
	} 
	
	//����ո�
	while( isspace(*str))
		++str;
	
	//��������
	int sign = 1;                //�����������ֵ���������Ϊ��ʱsign>0, ��Ϊ��ʱsign<0 
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		++str;
	} 
	
	//ȷ�������ֺ��ִ��ѭ��
	while (*str)
	{
		if (isdigit(*str))
		{
		    //�������
			int c = *str - '0';       //��ǰ���� 
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
			
			//��֮ǰ�õ������ֳ���10, �ټ��ϵ�ǰ�ַ���ʾ������
			n = n * 10 + c;
		}
		++str;		
	} 
	return (sign > 0) ? n : (-n);
}