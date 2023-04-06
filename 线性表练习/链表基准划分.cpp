#include<iostream>
/*
以点链表首节点值x为基准将该单链表分割为两部分，使所有小于x的节点排在
大于或等于x的节点之前 
*/ 
using namespace std;
struct List
{
	int data;
	struct List *pNext;
};
void init_list(List *&L);//初始化单链表
void create_list(List *&L);//创建单链表,使用尾插法创建 
void travel_list(List *L);//遍历单链表 
bool if_empty(List *L);//判断链表是否为空 
void destory_list(List *&L);//销毁单链表 
void operation(List *&L,List *&A);
int main()
{
	List *L=NULL;
	init_list(L);
	create_list(L);
	 cout<<"遍历链表为："<<endl;
	 travel_list(L);
	 List *A=NULL;
	 operation(L,A);
	 cout<<"操作后遍历链表为："<<endl;
	 travel_list(A);
	 destory_list(L);
	 destory_list(A);
	return 0;
}
void init_list(List *&L)
{
	L=new List;
	L->pNext=NULL;
	return;
}
void create_list(List *&L)
{
	int n;
	cout<<"请输入生成节点的个数：";
	cin>>n;
	List *val=L;
	int data;
	for(int i=0;i<n;i++)
	{
		cout<<"请输入第"<<i+1<<"个节点的值:";
		cin>>data;
		List *pNew=new List;
		pNew->data=data;
		pNew->pNext=NULL;
		val->pNext=pNew;
		val=pNew; 
	}
	return;
}
bool if_empty(List *L)
{
	if(L->pNext==NULL)
	{
		return true;
	}
	return false;
}
void travel_list(List *L)
{
	if(if_empty(L))
	{
		cout<<"链表为空！"<<endl;
		return;
	}
	List *p=L->pNext;
	while(p!=NULL)
	{
		cout<<p->data<<" ";
		p=p->pNext;
	}
	cout<<endl;
	return;
}
void destory_list(List *&L)
{
	List *p=L->pNext;
	List *val;
	while(p!=NULL)
	{
		val=p;
		p=p->pNext;
		delete val;
	}
	delete L;
	return;
}
void operation(List *&L,List *&A)
{
	init_list(A);//初始化新节点A 
	List *pNew=new List;
	pNew->data=L->pNext->data;
	int x=pNew->data;//记录链表L的首节点的值 
	A->pNext=pNew;//新节点A的首节点为节点L的首节点 
	pNew->pNext=NULL;
	List *p=L->pNext->pNext;//p指向L链表的第二个节点 
	List *val=A;List *val2=A->pNext;List *val3=A->pNext;
	while(p!=NULL)
	{
		if(p->data<x)//如果节点元素的值小于链表L首节点的值，则往前移动 
		{
			//创建链表A的新节点
			List *pNew=new List; 
			pNew->data=p->data;
			//将新节点插在链表B原始首节点的前面 ，即在原始首节点之前使用尾插法 
			val->pNext=pNew;
			pNew->pNext=val2;
			val=pNew;
		}else
		{
			 //创建链表A的新节点
			List *pNew=new List;
			pNew->data=p->data;
			pNew->pNext=NULL;
			//将新节用尾插法放在链表A后面 
			val3->pNext=pNew;
			val3=pNew;
		}
		p=p->pNext;
	}
	return;
}
