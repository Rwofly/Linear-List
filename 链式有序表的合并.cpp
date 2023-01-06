#include<iostream>
using namespace std;
struct Node
{
	int data;
	Node* next;
};
void creat_list(Node*);//尾插法创建有序链表
void travel_list(Node*);//遍历并输出链表
void add_list(Node*, Node*,Node*);//两个链式有序表的合并
int main()
{
	Node* pHead1 =new Node;
	Node* pHead2 =new Node;
	Node* pHead3 = new Node;
	pHead1->next = NULL;
	pHead2->next = NULL;
	pHead3->next = NULL;
	creat_list(pHead1);
	creat_list(pHead2);
	cout << "第一个链表元素有：" << endl;
	travel_list(pHead1);
	cout << "第二个链表的元素有：" << endl;
	travel_list(pHead2);
	add_list(pHead1, pHead2, pHead3);
	cout << "合并后的链表元素为：" << endl;
	travel_list(pHead3);
	return 0;
}
void creat_list(Node* pHead)
{
	int n, m;
	Node* val;
	val = pHead;
	cout << "请输入生成链表的个数：";
	cin >> n;
	for (int i = 0;i < n;i++)
	{
		cout << "请输入第 " << i + 1 << " 个节点的值(由小到大输入)：";
		cin >> m;
		Node* pNew = new Node;
		if (pNew == NULL)
		{
			cout << "内存分配失败！";
			exit(-1);
		}
		pNew->data = m;
		pNew->next = NULL;
		val->next = pNew;
		val = pNew;
	}
	return;
}
void travel_list(Node* pHead)
{
	Node* p=pHead->next;
	while (p != NULL)
	{
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
	return;
}
void add_list(Node* pHead1, Node* pHead2,Node* pHead3)//将pHead1、pHead2节点放入pHead3节点之后
{
	Node* p1, * p2, * p3;
	p1 = pHead1->next, p2 = pHead2->next, p3 = pHead3;
	while (p1 && p2)//当p1、p2都不指向尾结点时继续循环
	{
		if (p1->data <= p2->data)
		{
			p3->next = p1;//将p1所指节点放在p3所指节点之后
			p3 = p1;//p3指向p1,相当于尾插法创建链表
			p1 = p1->next;//p1指向下一节点
		}
		else
		{
			p3->next = p2;
			p3 = p2;
			p2 = p2->next;
		}
	}
	p3->next = p1 > p2 ? p1 : p2;//将剩余的非空表插入到p3所指的节点后面
	delete pHead1;//释放pHead1,pHead2 的空间
	delete pHead2;
	return;
}