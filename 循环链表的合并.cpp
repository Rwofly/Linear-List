#include<iostream>
using namespace std;
struct Node
{
	int data;
	struct Node* next;
};
void create_list(Node* pHead);//创建循环链表 
void travel_list(Node* pHead);//遍历循环链表 
Node *add_list(Node* pHead1, Node* pHead2);//合并两个循环链表 
int main()
{
	Node* pHead1 = new Node;
	Node* pHead2 = new Node;
	pHead1->next = pHead1;
	pHead2->next = pHead2;//头结点指向自己 
	create_list(pHead1);
	cout << "第一个链表的元素有：" << endl;
	travel_list(pHead1);
	create_list(pHead2);
	cout << "第二个链表的元素有：" << endl;
	travel_list(pHead2);
	Node* All_list;
	All_list=add_list(pHead1, pHead2);
	cout << "合并后的链表为：" << endl;
	travel_list(All_list);
	return 0;
}
void create_list(Node* pHead)//尾插法创建一个循环链表 
{
	int n, val;
	Node* p = pHead;
	cout << "请输入要生成节点的个数：";
	cin >> n;
	for (int i = 0;i < n;i++)
	{
		Node* pNew = new Node;
		cout << "请输入第 " << i + 1 << " 个节点的值：";
		cin >> val;
		pNew->data = val;
		pNew->next = pHead;
		p->next = pNew;
		p = pNew;
	}
	return;
}
void travel_list(Node* pHead)
{
	Node* p = pHead->next;
	while (p != pHead)//与普通单链表的不同，以头结点为结束条件 
	{
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
	return;
}
Node *add_list(Node* pHead1, Node* pHead2)
{
	/*具体操为：让第一个表的尾指针指向第二个表的第一个节点
			  再让第二个表的尾指针指向第一个表的头结点，然后释放第二个表的头结点
		*/
	Node* p1 = pHead1->next;
	Node* p2 = pHead2->next;
	while (p1->next != pHead1)//让p1成为第一个链表的尾指针 
	{
		p1 = p1->next;
	}
	while (p2->next != pHead2)//让p2成为第二个链表的尾结点 
	{
		p2 = p2->next;
	}
	p1->next = pHead2->next;//第一个表的尾指针指向第二个表的第一个节点
	p2->next = pHead1;// 让第二个表的尾指针指向第一个表的头结点
	delete pHead2;//然后释放第二个表的头结点
	return pHead1;
}
