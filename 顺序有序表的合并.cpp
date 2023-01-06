#include<iostream>
using namespace std;
#define Max 20
int get_length(int*);//求顺序表长度
void add_list(int*, int*, int*);//合并顺序表
void travel_list(int*);//遍历并输出顺序表
int main()
{
	int num1[Max] = { 3,5,8,11 };
	int num2[Max] = { 2,6,8,9,11,15,20 };
	int num3[Max]={0};
	add_list(num1, num2, num3);
	cout << "表1的元素有：" << endl;
	travel_list(num1);
	cout << "表2的元素有：" << endl;
	travel_list(num2);
	cout << "合并后的结果为：" << endl;
	travel_list(num3);
	return 0;
}
int get_length(int* num)
{
	int len = 0;
	while (*num != 0)
	{
		len++;
		num++;
	}
	return len;
}
void add_list(int* num1, int* num2,int* num3)
{
	int len1, len2;
	len1 = get_length(num1);
	len2 = get_length(num2);
	int i = 0, j = 0,k=0;
	while (i < len1 && j < len2)
	{
		if (num1[i] > num2[j])
		{
			num3[k] = num2[j];
			k++;
			j++;
		}
		else
		{
			num3[k] = num1[i];
			k++;
			i++;
		}
	}
	while (i < len1)
	{
		num3[k] = num1[i];
		k++;
		i++;
	}
	while (j < len2)
	{
		num3[k] = num2[j];
		k++;
		j++;
	}
	return;
}
void travel_list(int* p)
{
	int len = get_length(p);
	for (int i = 0;i < len;i++)
	{
		cout << p[i] << " ";
	}
	cout << endl;
	return;
}