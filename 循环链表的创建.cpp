#include<iostream>
using namespace std;
struct Node
{
	int data;
	struct Node* next;
};
void create_list(Node *pHead);//创建循环链表 
void travel_list(Node* pHead);//遍历循环链表 
int main()
{
	Node* pHead=new Node;
	pHead->next=pHead;//头结点指向自己 
	create_list(pHead); 
	cout<<"该链表的元素有："<<endl;
	travel_list(pHead);
	return 0;
}
void create_list(Node *pHead)//尾插法创建一个循环链表 
{
	int n,val;
	Node* p=pHead;
	cout<<"请输入要生成节点的个数："; 
	cin>>n;
	for(int i=0;i<n;i++)
	{
		Node* pNew=new Node;
		cout<<"请输入第 "<<i+1<<" 个节点的值：";
		cin>>val;
		pNew->data=val;
		pNew->next=pHead;
		p->next=pNew;
		p=pNew;
	}
	return;
}
void travel_list(Node* pHead)
{
	Node* p=pHead->next;
	while(p!=pHead)//与普通单链表的不同，以头结点为结束条件 
	{
		cout<<p->data<<" ";
		p=p->next;
	}
	return;
}
