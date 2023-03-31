#include<iostream>
using namespace std;
/*有序单链表L（从小到大排序），设计一个高效算法，删除值域重复的节点
分析：
由于为顺序表，其排序为从小到大，故只要前一个节点
不与本节点相同就不是重复的节点*/ 
struct List
{
	int data;
	struct List *pNext;
};
void creat_list(List *&L);
void travel_list(List *L);
void operation(List *&L);
int main()
{
	List *L;
	creat_list(L);
	cout<<"操作前链表的值为："<<endl;
	travel_list(L);
	operation(L);
	cout<<"操作后链表的值为："<<endl;
	travel_list(L);
	return 0;
}
void creat_list(List *&L)
{
	L=new List;
	L->pNext=NULL;
	int n;
	cout<<"输入链表结点的个数：";
	cin>>n;
	List *val=L;
	int num;
	for(int i=0;i<n;i++)
	{
		cout<<"请输入第"<<i+1<<"个节点的值：";
		cin>>num;
		List *pNew=new List;
		pNew->data=num;
		pNew->pNext=NULL;
		val->pNext=pNew;
		val=pNew;
	}
	return;
}
void travel_list(List *L)
{
	List *p=L->pNext;
	while(p!=NULL)
	{
	   cout<<p->data<<" ";
	   p=p->pNext; 
	}
	cout<<endl;
	return;
}
void operation(List *&L)
{
	List *p,*q,*t;
	p=L->pNext;
	q=p->pNext;//q指向p的下一个节点 
	while(q!=NULL)
	{
		if(p->data==q->data)
		{
			t=q;//t指向q所指的节点
			q=q->pNext;//q后移一位 
			p->pNext=q; 
			delete t;//释放重复节点 
			 
		}else
		{
			p=q;
			q=q->pNext;//如果不重复，则p与q同时向后移一位 
		}
	}
	return;
}
