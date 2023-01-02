#include<iostream>
using namespace std;
struct Node
{
	int data;
	struct Node* next;
};
void create_list(Node* pHead);//创建单链表
void travel_list(Node* pHead);//遍历单链表
Node* add_list(Node* pHead1, Node* pHead2);//合并两个单链表
int main()
{
	Node* pHead1 = new Node;
	Node* pHead2 = new Node;
	pHead1->next = NULL;
	pHead2->next = NULL;
	create_list(pHead1);
	cout << "第一个链表的元素有：" << endl;
	travel_list(pHead1);
	create_list(pHead2);
	cout << "第二个链表的元素有：" << endl;
	travel_list(pHead2);
	Node* all_list = new Node;
	all_list=add_list(pHead1, pHead2);
	cout << "合并后的链表值为：" << endl;
	travel_list(all_list);
	return 0;
}
void create_list(Node* pHead)//尾插法创建单链表
{
	int n, val;
	Node* p = pHead;
	cout << "请输入要生成节点的个数：";
	cin >> n;
	for (int i = 0;i < n;i++)
	{
		Node* pNew = new Node;
		cout << "输入第 " << i + 1 << " 个节点的值：";
		cin >> val;
		pNew->data = val;
		p->next = pNew;
		pNew->next = NULL;
		p = pNew;
	}
	return;
}
void travel_list(Node* pHead)
{
	Node* p = pHead->next;
	while (p != NULL)
	{
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
	return;
}
Node* add_list(Node* pHead1, Node* pHead2)
{
	//具体操作：让链表pHead1的尾结点指向pHead2的头结点，并释放pHead2。
	Node* p1 = pHead1->next;
	Node* p2 = pHead2->next;
	while (p1 ->next!= NULL)//让p1指向链表pHead1的尾结点
	{
		p1 = p1->next;
	}
	p1->next = pHead2->next;
	delete pHead2;
	return pHead1;
}