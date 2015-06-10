#include<stdio.h>
#include<string.h>

/*
* @Author: dwyaneini
* @Time: 2015-06-09
* @Language: C 
* Description: �����ж��ַ���b��������ĸ�Ƿ����ַ���a��, ��a�ĳ��ȱ�b�ĳ� 
* (�涨: �ַ�����ֻ������дӢ����ĸ)
* Example: input: a: "ABCDEF", b: "BEBE", output: True
*          input: a: "ABCDEF", b: "BFH", output: False, "H" not included in string b 
*
* Sol1(����˼·) :
* ����ַ���b��ÿһ���ַ��������a��ÿ���ַ��Ƚϣ����Ƿ������a�С�ʱ�临�Ӷ�ΪO(m*n) 
*
* Sol2(���������ѯ):
* �ȶ����ַ�������ĸ��������Ȼ����ͬʱ�������ִ�������ѯ
* ���򳣹������O(mlogm)+O(nlogn)�β���, ����ɨ����ҪO(m+n)�β��� 
*
* Sol:
* �����ַ���a�е������ַ�������һ��Hashtable��, Ȼ����ѯ���ַ���b, �鿴b��ÿ���ַ��Ƿ���Hashtable�� 
* ���δ�����ַ���a����λ����(26bit������ʾ)�����һ��"Signature", ����b�е��ַ���a����в��� 
*/

int StringContain(char* a, char* b);

int main()
{
	char s1[100], s2[99];
	int isContain;        //��ȡ����StringContain�ķ���ֵ��1��ʾ�ַ���a����b������ֵ����ʾ������ 
	char notExistChar;    //��isContain��Ϊ1ʱ����ȡ�ַ���b�а�����a�в��������ַ� 
	char* a = s1;
	char* b = s2;
	printf("�������ַ���a: (���Ȳ�����100�Ĵ�дӢ����ĸ)\n");
	scanf("%s", a);
	printf("�����ַ���b: (���Ȳ�����99�Ĵ�дӢ����ĸ)\n");
	scanf("%s", b);
	
	isContain = StringContain(a, b);
	if (isContain == 1)
		printf("\nTrue, �ַ���\"%s\"������\"%s\"��.\n", b, a);
	else
	{
		notExistChar = (char)('A' + isContain); 
		printf("\nFalse, �ַ���\"%s\"�д���\"%s\"û�е��ַ� (%c)!\n", b, a, notExistChar);	
	}
	return 0;
}

int StringContain(char* a, char* b)
{
	int flag = 1;  //Ĭ��1����ʾa����b 
	int hash = 0;
	int i;
	for (i = 0; i < strlen(a); i++)
	{
		//hash = hash ��λ�� ( 1���� (a[i]-'A')λ) 
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