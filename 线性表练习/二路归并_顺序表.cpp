#include<iostream>
/*有序表的二路归并算法 ，采用顺序表的方法实现 
其过程是分别扫描LA和LB两个有序表，当两个有序表都没有遍历完时循环：
比较LA、LB的当前元素，将其中较小的元素放入LC中，再从较小元素所
在的有序表中取下一个元素。重复这一过程，直到LA或LB遍历完毕，
最后将未遍历完的有序表中余下的元素放入LC中。*/
using namespace std;
#define Maxsize 20
struct Num
{
	int length;
	int *numb;
};
void show(Num *num);
void init_Num(Num *num);//初始化
void gui_bing(Num *num1,Num *num2,Num *num3);
int main()
{
	Num num1,num2,num3;
	init_Num(&num1);
	init_Num(&num2);
	num3.length=num1.length+num2.length;
	num3.numb=new int[num3.length];
	gui_bing(&num1,&num2,&num3);
	cout<<"归并完后结果为："<<endl;
	show(&num3);
	return 0;
} 
void init_Num(Num *num)
{
	cout<<"请输入数组长度：";
	cin>>num->length;
	num->numb=new int[num->length];
	cout<<"请输入数组元素(由小到大)：";
	for(int i=0;i<num->length;i++)
	{
		cin>>num->numb[i];
	}
	return;
}
void show(Num *num)
{
	for(int i=0;i<num->length;i++)
	{
		cout<<num->numb[i]<<" ";
	}
	cout<<endl;
	return;
}
void gui_bing(Num *num1,Num *num2,Num *num3)
{
	 int i=0,j=0,k=0;
	 while(i<num1->length&&j<num2->length)
	 {
	 	if(num1->numb[i]>num2->numb[j])
	 	{
	 	    num3->numb[k]=num2->numb[j];
			 k++;
			 j++; 
		}else
		{
			num3->numb[k]=num1->numb[i];
			k++;
			i++;
		}
	 }
	 while(i<num1->length)//若num1未遍历完 
	 {
	    num3->numb[k]=num1->numb[i];
	 	k++;
	 	i++;
	 }
	 while(j<num2->length)//若num2未遍历完 
	 {
	    num3->numb[k]=num2->numb[j];
	 	k++;
	 	j++;
	 }
	return;
}
