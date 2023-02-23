#include<iostream>
using namespace std;
#define Maxsize 100
struct Num
{
	int *data;
	int length;
};
void init_list(Num *number);
void push_list(Num *number,int n,int m);
void delete_list(Num *number,int n,int &m);
void show_list(Num *number);
void delete_numb(Num* number,int n);//删除顺序表中所有的特定元素 
int main()
{
	int m;
	Num *number=new Num;
	init_list(number);
	push_list(number,1,1);
	push_list(number,1,6);
	push_list(number,1,3);
	push_list(number,1,4);
	push_list(number,1,5);
	push_list(number,1,6);
	push_list(number,1,7);
	push_list(number,1,6);
	show_list(number);
	delete_list(number,2,m);
	cout<<"删除后的线性表为："<<endl;
	show_list(number);
	cout<<"删除的数据为："<<m<<endl;
	delete_numb(number,6);
	cout<<"删除元素6后的顺序表为："<<endl;
	show_list(number);
	return 0;
}
void init_list(Num *number)
{
	number->data=new int[Maxsize];
	number->length=0;
	return;
}
void push_list(Num *number,int n,int m)
{
	if(n<1||n>number->length+1)
	{
		cout<<"插入位置有误！"<<endl;
		return;
	}
	if(number->length==Maxsize)
	{
		cout<<"线性表已满！"<<endl;
		return;
	}
	if(number->length==0)
	{
		number->data[0]=m;
		number->length++;
		return;
	}
	for(int i=number->length;i>=n;i--)
	{
		number->data[i]=number->data[i-1];
	}
	number->data[n-1]=m;
	number->length++;
	return;
}
void delete_list(Num *number,int n,int &m)
{
	if(n<1||n>number->length)
	{
		cout<<"删除位置有误！"<<endl;
	}
	if(number->length==0)
	{
		cout<<"线性表为空！"<<endl;
		return;
	}
	m=number->data[n-1];
	for(int i=n-1;i<number->length-1;i++)
	{
		number->data[i]=number->data[i+1];
	}
	number->length--;
	return;
}
void show_list(Num *number)
{
	if(number->length==0)
	{
		cout<<"线性表为空！"<<endl;
		return;
	}
	for(int i=0;i<number->length;i++)
	{
		cout<<number->data[i]<<" ";
	}
	cout<<endl;
	return;
}
void delete_numb(Num *number,int n)//该算法的时间复杂度为o(n)空间复杂度为o(1) 
{
	int count=0;
	for(int j=0;j<number->length-1;j++)
	{
		if(number->data[j]==n)
		{
			count++;
		}
	}
	if(count==0)
	{
		cout<<"顺序表中没有该元素！"<<endl;
		return;
	}
	int k=0;
	for(int i=0;i<number->length-1;i++)
	{
		if(number->data[i]!=n)
		{
			number->data[k]=number->data[i];
			k++;
		}else
		{
			number->length--;
		}
	}
	return;
}
