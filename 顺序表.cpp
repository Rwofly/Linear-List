#include<iostream>
using namespace std;
int Maxsize=100;
int *create_list(int n);
int menu();
void insert_list(int &n,int *p);
void delete_list(int &n,int *p);
int main()
{
	int n,*p;
	cout<<"你想要输入多少个数字:"<<endl;
	cin>>n;
	while(n>Maxsize)
	{
		cout<<"错误！请重新输入！"<<endl;
		cout<<"你想要输入多少个数字:"<<endl;
	    cin>>n;
	}
	p=create_list(n);
	int numb=menu(); 
    while(numb)
    {
    	switch(numb)
    	{
    		case 1:insert_list(n,p);break;
    		case 2:delete_list(n,p);break;
    		case 3:delete [] p;return 0;
		}
		cout<<endl;
		numb=menu();
	}
	return 0;
}
int *create_list(int n)
{
	int *p;
	p=new int [Maxsize];
	if(!p)
	{
		cout<<"内存分配失败！";
	}
	cout<<"请输入你想输入的数字："<<endl;
	for(int i=0;i<n;i++)
	{
		cin>>p[i];
	}
	return p;
}
int menu()
{
	int k;
	cout<<"--------------------------"<<endl;
	cout<<"1.插入一个数字。"<<endl;
	cout<<"2.删除一个数字。"<<endl;
	cout<<"3.退出。"<<endl;
	cout<<"--------------------------"<<endl;
	cout<<"请输入选项："<<endl;
	cin>>k;
	return k;
}
void insert_list(int &n,int *p)
{
	int k,d;
	cout<<"你想在什么位置插入一个数字："<<endl;
	cin>>k;
	while(k>n||k<1)
	{
		cout<<"错误！请重新输入！"<<endl;
		cout<<"你想在什么位置插入一个数字："<<endl;
	    cin>>k;
	}
	cout<<"请输入你想插入的数字："<<endl;
	cin>>d;
	for(int i=n-1;i>=k-1;i--)
	{
		p[i+1]=p[i];
	}
	n=n+1;//表长加一 
	p[k-1]=d;
	cout<<"插入后数组为："<<endl;
	for(int i=0;i<n;i++)
	{
		cout<<p[i]<<" ";
	}
	return;
}
void delete_list(int &n,int *p)
{
	int k;
	cout<<"你想在什么位置删除一个数字："<<endl;
	cin>>k;
	while(k>n||k<1)
	{
		cout<<"错误！重新输入！"<<endl;
		cout<<"你想在什么位置删除一个数字："<<endl;
	    cin>>k;
	}
	for(int i=k;i<n;i++)
	{
	  p[i-1]=p[i]; 
	}
	n=n-1;//表长减一 
	cout<<"删除后的数组为："<<endl;
	for(int i=0;i<n;i++)
	{
		cout<<p[i]<<" ";
	}
	return;
}

