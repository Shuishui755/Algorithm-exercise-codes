//为了确保所有人出列，本题设定为循环链表，尾节点指针指向第一个节点，每当计数到m时清零并删除该节点，循环直至链表为空
#include <bits/stdc++.h>
using namespace std;

//定义链表节点
typedef struct linkNode
{
	int data;
	struct linkNode *next;
}linkNode, *linkList; 

//定义指定头节点和链表长度的链表创建函数
void createList(linkList &L, int n)
{
	//创建首节点
	linkList current, p;
	current = new linkNode;
	current->data = 1;
	current->next = NULL;
	L->next = current;
	
	//循环创建链表
	for(int i = 2; i <= n; i++) 
	{
		p = new linkNode;
		p->data = i;
		p->next = NULL;
		current->next = p;
		current = p;
	}
	//尾节点指向首节点构成循环
	current->next = L->next;
}

//main函数
int main()
{
	int n, m;
	scanf("%d %d", &n, &m);

	//创建链表
	linkList L = new linkNode;
	L->data = 0;
	L->next = NULL;
	createList(L, n);

	//循环并计数
	linkList getNode = L->next;
	int count = 1;
	while(true)
	{
		if(count == (m - 1))
		{
			printf("%d ", getNode->next->data);

			linkList temp = getNode->next;
			getNode->next = getNode->next->next;

			if(L->next == temp) L->next = getNode->next;

			delete temp;

			//清零重新计数
			getNode = getNode->next;
			count = 1;

			//链表为空时输出最后一个节点并删除
			if(getNode->next == getNode)
			{
				printf("%d", getNode->data);
				delete getNode;
				break;
			}
		}
		
		else
		{
			getNode = getNode->next;
			count++;
		}
	}

	return 0;
} 
