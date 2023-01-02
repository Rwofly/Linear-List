#include<iostream>//整体思路与单链表相同,有生成、遍历、插入、删除操作 。 
#include<stdlib.h> 
using namespace std;
struct Node
{
	int data;
	struct Node *pre,*next;
};
void creat_list(Node* pHead);//生成双向链表 
void travel_list(Node* pHead);//遍历并输出双向链表 
void insert_list(Node* pHead,int pos,int n);//双向链表的插入 
void delete_list(Node* pHead,int pos);//双向链表的删除 
void test_travel(Node* pHead);//测试双向链表，利用pre节点逆序输出链表 
int main()
{
	Node* pHead=new Node;
	pHead->next=NULL;
	pHead->pre=NULL;
	creat_list(pHead);
	cout<<"双向链表的元素有："<<endl;
	travel_list(pHead);
	int pos,n;
	cout<<"请输入插入元素的位置：";
	cin>>pos;
	cout<<"请输入插入元素的值：";
	cin>>n;
	insert_list(pHead,pos,n);
	cout<<"插入元素后的值链表为："<<endl;
	travel_list(pHead);
	cout<<"请输入删除元素的位置：";
	cin>>pos;
	delete_list(pHead,pos);
	cout<<"删除一个元素后链表为："<<endl;
	travel_list(pHead);
	cout<<"测试输出为："<<endl;
	test_travel(pHead);
	return 0;
}
void creat_list(Node* pHead)
{
	int n,val;
	Node* p=pHead;
	cout<<"请输入生成链表的个数：";
	cin>>n;
	for(int i=0;i<n;i++)
	{
		Node* pNew=new Node;
		cout<<"请输入第 "<<i+1<<" 个链表的值：";
		cin>>val;
		pNew->data=val;
		p->next=pNew;
		pNew->pre=p;
		pNew->next=NULL;
		p=pNew; 
	}
	return;
}
void travel_list(Node* pHead)//遍历方法跟单链表相同 
{
	Node* p=pHead->next;
	while(p!=NULL)
	{
		cout<<p->data<<" ";
		p=p->next;
	}
	cout<<endl;
	return;
}
void insert_list(Node* pHead,int pos,int n)
{
	Node* p=pHead;
	int i=0;
	while(p!=NULL&&i<pos-1)//判断部分跟单链表一样 
	{
		i++;
		p=p->next;
	}
	if(p==NULL||i>pos-1)
	{
		cout<<"不在插入范围之内,退出程序！";
		exit(-1); 
	} 
	Node* pNew=new Node;
	pNew->data=n;
	pNew->next=p->next;//新节点指向下一个节点 
	p->next->pre=pNew; //下一个节点又指向新节点 
	p->next=pNew;//前一个节点指向新节点 
	pNew->pre=p;//新节点指向前一个节点    一共四步 
	return;
}
void delete_list(Node* pHead,int pos)
{
	Node* p=pHead;
	int i=0;
	while(p->next!=NULL&&i<pos-1)//判断跟单链表相同 
	{
		i++;
		p=p->next;
	}
	if(p->next==NULL&&i>pos-1)
	{
		cout<<"超出链表范围，退出程序！";
		exit(-1);
	}
	p=p->next;//必要 ，将p移动到删除位置 
	p->pre->next=p->next;//p的前一个节点指向p的后一个节点 
	p->next->pre=p->pre;//p的后一个节点指向前一个节点 
	delete p;//释放p节点的内存 
	return;
}
void test_travel(Node* pHead)
{
	Node* p=pHead->next;
	while(p->next!=NULL)//将p移动到尾结点 
	{
		p=p->next;
	}
	while(p->pre!=NULL)
	{
		cout<<p->data<<" ";
		p=p->pre;
	}
	cout<<endl;
	return;
} 
/*后面甚至还有双向循环链表。妈了个逼的，
给我敲吐了，反正敲了过几天也会忘，就不敲了。今天代码量算是最多的一天了，
总共得有五六百行，纪念一下
2023 01 02 */ 
