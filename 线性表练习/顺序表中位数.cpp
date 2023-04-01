/*找出两等长升序列的中位数s1,s2，升序列用顺序表存储
思路：
当升序序列采用顺序表存储时，一个升序序列S的中位数就是S->data[S->length/2]
只需要将两个序列二路归并成一个新序列S，其实不需要求出S的全部元素，用k记录当归并的元素的个数
当k=s1->length时进行归并的那个元素就是中位数 
*/
#include<iostream>
using namespace std;
#define Maxsize 5 
struct Num
{
	int *data;
	int length;
};
void init(Num *&num);
void show(Num *num);
int operation(Num *&num1,Num *&num2);
int main()
{
	Num *num1,*num2;
	init(num1);
	init(num2);
	cout<<"num1的元素为："<<endl;
	show(num1);
	cout<<"num2的元素为："<<endl;
	show(num2);
	int n=operation(num1,num2);
	cout<<"两顺序表的中位数为："<<n<<endl; 
	return 0;
} 
void init(Num *&num)
{
	num=new Num;
	num->data=new int[Maxsize];
	num->length=0;
	cout<<"请输入"<<Maxsize<<"个顺序表元素(由小到大输入)：";
	while(num->length<Maxsize)
	{
		cin>>num->data[num->length];
		num->length++;
	}
	return;
}
void show(Num *num)
{
	for(int i=0;i<num->length;i++)
	{
		cout<<num->data[i]<<" ";
	}
	cout<<endl;
	return;
}
int operation(Num *&num1,Num *&num2)
{
	int i=0,j=0,k=0;
	while(i<num1->length&&j<num2->length)//两个序列均没有扫描完 
	{
		k++;//归并数加一
		if(num1->data[i]<num2->data[j])//归并较小的元素 
		{
			if(k==num1->length)//若当前归并的元素是所求的元素 
			{
				return num1->data[i];
			}
			i++;
		}else//归并较小的元素num2->[j] 
		{
			if(k==num2->length)
			{
				return num2->data[j];
			}
			j++;
		} 
	}
}
