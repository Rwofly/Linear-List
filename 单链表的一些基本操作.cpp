#include<iostream> 
#include<stdlib.h>
using namespace std;
typedef struct Node
{
	int data;//数据域 
	struct Node* pNext;//指针域 
}NODE,*PNODE;
PNODE create_list();//创建链表 ，本例使用尾插法 
void travel_list(PNODE pHead);//遍历并输出链表 
bool is_empty(PNODE pHead);//判断链表是否为空 
int length_list(PNODE);//求链表的长度 
bool insert_list(PNODE,int,int);//在链表中插入一个元素 
bool delete_list(PNODE,int);//在链表中删除一个元素 
void soert_list(PNODE, int);//链表中元素的排序 

int main(void)
{
	PNODE pHead = NULL;
	pHead = create_list();
	travel_list(pHead);
	if (is_empty(pHead))
	{
		cout<<"链表为空。"<<endl; 
	}
	else
	{
		cout<<"链表为非空。"<<endl;
	}
	int len = length_list(pHead);
	cout<<"链表长度是："<<len;
	soert_list(pHead, len);
    cout<<"排序后的链表为："<<endl;
	travel_list(pHead);
	int pos,val;
	cout<<"请输入插入节点的位置：";
	cin>>pos;
	cout<<"请输入要插入的值：";
	cin>>val; 
	insert_list(pHead, pos, val);
	cout<<"插入一个元素后链表为："<<endl; 
	travel_list(pHead);
	cout<<"请输入要删除节点的位置：";
	cin>>pos;
	delete_list(pHead,pos);
	cout<<"删除节点后的链表为："<<endl; 
	travel_list(pHead);
	return 0;
}
PNODE create_list()
{
	int len, i;
	int val;
	PNODE pHead=(PNODE)malloc(sizeof(NODE));
	if (NULL == pHead)
	{
		cout<<"内存分配失败！退出程序！";
		exit(-1);
	}
	PNODE pTail = pHead;
	pTail->pNext = NULL;
	cout<<"请输入要生成节点的长度：";
	cin>>len;
	for (i = 0;i < len;i++)
	{
		cout<<"请输入第 "<<i+1<<" 个节点的值：";
		cin>>val; 
		PNODE pNew = (PNODE)malloc(sizeof(NODE));
		if (NULL == pNew)
		{
			cout<<"内存分配失败！退出程序！";
			exit(-1);
		}
		pNew->data = val;
		pTail->pNext = pNew;
		pNew->pNext = NULL;
		pTail = pNew;
	}
	return pHead;
}
void travel_list(PNODE pHead)
{
	PNODE p = pHead->pNext;
	while (p!= NULL)
	{
		cout<<p->data<<" ";
		p = p->pNext;
	}
	cout<<endl;
	return;
}
bool is_empty(PNODE pHead)
{
	if (NULL == pHead->pNext)
	{
		return true;
	}
	else
	{
		return false;
	}
}
int length_list(PNODE pHead)
{
	int count = 0;
	PNODE p = pHead->pNext;
	while (p != NULL)
	{
		count++;
		p = p->pNext;
	}
	return count;
}
void soert_list(PNODE pHead,int len)
{
	int i, j, t;
	PNODE p, q;
	for (i = 0, p = pHead->pNext;i < len - 1;i++, p = p->pNext)
	{
		for (j = i + 1, q = p->pNext;j < len;j++, q = q->pNext)
		{
			if (p->data > q->data)
			{
				t = p->data;
				p->data = q->data;
				q->data = t;
			}
		}
	}
	return;
}
bool insert_list(PNODE pHead, int pos, int val)
{
	int i = 0;
	PNODE p = pHead;
	while (NULL != p && i < pos - 1)
	{
		p = p->pNext;
		i++;
	}
	if (i > pos - 1 || NULL == p)
	{
		return false;
	}
	PNODE pNew = (PNODE)malloc(sizeof(NODE));
	if (NULL == pNew)
	{
		cout<<"内存分配失败！退出程序！";
		exit(-1);
	}
	pNew->data = val;
	pNew->pNext = p->pNext;
	p->pNext = pNew;
	return true;
}
bool delete_list(PNODE pHead, int pos)
{
	int i = 0;
	PNODE p = pHead;
	while (NULL != p->pNext && i < pos - 1)
	{
		p = p->pNext;
		i++;
	}
	if (i > pos - 1 || NULL == p->pNext)
	{
		return false;
	}
	PNODE q = p->pNext;
	p->pNext = q->pNext;
	delete q;//释放被删除节点的内存 
	return true;
}
	
