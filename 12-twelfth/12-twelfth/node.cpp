#include<stdio.h>
#include"node.h"
#include<stdlib.h>
/*typedef struct _node
{
	int value;
	struct _node *next;
} Node;*/
/*
//第一版
int main()
{
	Node *head=NULL;
	int x;
	do
	{
		scanf("%d",&x);
		if(x!=-1)
		{
			//add to linked-list
			Node *p=(Node*)malloc(sizeof(Node));
			p->value=x;
			p->next=NULL;
			//find the last
			Node *last=head;
			if(last)
			{
				while(last->next)
				{
					last=last->next;
				}
				//attach
				last->next=p;//p放在最后连接起来
			}
			else
			{
				head=p;//此时head为NULL，如果last指向head，last的next无效，所以head=p
			}
		}
	}while(x!=-1);
	return 0;
}*/
//第二版
typedef struct _list
{
	Node *head;
} List;

void add(List *pList, int x);

void print(List *pList);

int main()
{
	List list;
	list.head=NULL;
	int x;
	do
	{
		scanf("%d",&x);
		if(x!=-1)
		{
			add(&list,x);
		}
	}while(x!=-1);

	print(&list);
	return 0;
}

void add(List *pList, int x)
{
	//add to linked-list
	Node *p=(Node*)malloc(sizeof(Node));
	p->value=x;
	p->next=NULL;
	//find the last
	Node *last=pList->head;
	if(last)
	{
		while(last->next)
		{
			last=last->next;
		}
		//attach
		last->next=p;//p放在最后连接起来
	}
	else
	{
		pList->head=p;//此时head为NULL，如果last指向head，last的next无效，所以head=p
	}
}

void print(List *pList)
{
	Node *p;
	for(p=pList->head; p; p= p->next)//循环
	{
		printf("%d\t",p->value);
	}
}