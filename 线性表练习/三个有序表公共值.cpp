#include<iostream>
using namespace std;
/*三个有序表 LA LB LC 节点均以元素递增值排列，使链表LA中仅留下
三个表中均包含的数据元素的结点，且没有数据值相同的点,并释放LA中其他节点，算法时间复杂度为
O(m+n+p),即每个链表只遍历一遍*/ 
struct List
{
	int data;
	struct List *pNext;
};
void creat_list(List *&L);
void travel_list(List *L);
void operato(List *&LA,List *&LB,List *&LC);
int main()
{
	List *LA,*LB,*LC;
	creat_list(LA);
	creat_list(LB);
	creat_list(LC);
	cout<<"链表LA的值为："<<endl;
	travel_list(LA);
	cout<<"链表LB的值为："<<endl;
	travel_list(LB);
	cout<<"链表LC的值为："<<endl;
	travel_list(LC);
	operato(LA,LB,LC);
	cout<<"操作后LA 链表的值为："<<endl;
	travel_list(LA);
	return 0;
}
void creat_list(List *&L)
{
	L=new List;
	L->pNext=NULL;
	List *val=L;
	int n;
	cout<<"请输链表中元素个数：";
	cin>>n;
	int num;
	for(int i=0;i<n;i++)
	 {
	 	cout<<"请输入第"<<i+1<<"个节点的值(由大到小输入):"; 
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
void operato(List *&LA,List *&LB,List *&LC)
{
	List *La=LA->pNext,*Lb=LB->pNext,*Lc=LC->pNext,*p,*q;
	LA->pNext=NULL;//此时LA为新建单链表的头结点
	p=LA;//p始终指向尾结点
	while(La!=NULL)//查找公共节点并建立新链表LA 
	{
		while(Lb!=NULL&&La->data>Lb->data)
		{
			Lb=Lb->pNext;
		}
		while(Lc!=NULL&&La->data>Lc->data)
		{
			Lc=Lc->pNext;
		}
		if(Lb!=NULL&&Lc!=NULL&&Lb->data==La->data&&Lc->data==La->data)
		{
			//如果La节点是公共节点，将La节点插入到插入单链表LA中
			p->pNext=La;
			p=La;
			La=La->pNext;
			
		}else//否则删除 La节点 
		{
			q=La;//保存当前La节点 
			La=La->pNext;//La移动到下一节点 
			delete q;//释放非公共节点 
		}
	} 
	p->pNext=NULL;//尾结点的pNext域设置为空 
	return;
}
