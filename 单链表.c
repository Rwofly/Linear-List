#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct Node
{
	int data;//数据域
	struct Node* pNext;//指针域
}NODE,*PNODE;
PNODE create_list();
void travel_list(PNODE pHead);
bool is_empty(PNODE pHead);//是否为空
int length_list(PNODE);//节点长度
bool insert_list(PNODE,int,int);//插入节点
bool delete_list(PNODE,int);//删除节点
void soert_list(PNODE, int);//排序

int main(void)
{
	PNODE pHead = NULL;
	pHead = create_list();
	travel_list(pHead);
	if (is_empty(pHead))
	{
		printf("链表为空\n");
	}
	else
	{
		printf("链表为不空\n");
	}
	int len = length_list(pHead);
	printf("链表长度是%d\n", len);
	soert_list(pHead, len);
	printf("排序后节点是：\n");
	travel_list(pHead);
	insert_list(pHead, 4, 33);
	printf("插入一个链表后为：\n");
	travel_list(pHead, len);
	delete_list(pHead,4);
	printf("删除一个链表后为：\n");
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
		printf("分配失败，程序终止！");
		exit(-1);
	}
	PNODE pTail = pHead;
	pTail->pNext = NULL;
	printf("请输入你需要生成链表的个数：");
	scanf_s("%d", &len);
	for (i = 0;i < len;i++)
	{
		printf("请输入第%d个节点的值：", i + 1);
		scanf_s("%d", &val);
		PNODE pNew = (PNODE)malloc(sizeof(NODE));
		if (NULL == pNew)
		{
			printf("分配失败，程序终止！");
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
		printf("%d ", p->data);
		p = p->pNext;
	}
	printf("\n");
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
bool insert_list(PNODE pHead, int pos, int val)//插入一个元素
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
		printf("动态内存分配失败！");
		exit(-1);
	}
	pNew->data = val;
	pNew->pNext = p->pNext;
	p->pNext = pNew;
	return true;
}
bool delete_list(PNODE pHead, int pos)//删除一个元素
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
	free(q);
	return true;
}
	