#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<ctype.h>
#include<string.h>

struct Node
{
	int color;
	int dist;
	struct Node *parent;
}*arr[1000];

struct Node1
{
	int color1;
	struct Node1 *parent1;
}*arr1[1000];

struct List
{
	int key;
	struct List *next;	
}*adj[1000];

struct List *head = NULL;
int i, n, k, j=0, r, q[1000], q1[1000], p, front=-1, rear=-1, time = 0, flag1 = 0;
int z=-1;

void enqueue(int q[], int val)
{
	rear++;
	q[rear] = val;
	return;
}
int dequeue(int q[])
{
	if(front==rear)
	{
		rear=-1;
		front=-1;
		printf("ERROR\n");
		return 0;
	}	
	else
	{	
		front++;
		return q[front];
	}	
}
void push(int q1[], int ele)
{
	z++;
	q[z] = ele;
	return;
}
int pop(int q1[])
{
	if(z==-1)
	{
		printf("ERROR\n");
		return 0;
	}
	else
	{	
		z--;
		return q[z+1];
	}		
}
void bfs(struct List *adj[], int st, int end)
{
	for(i=0; i<n; i++)
	{
		if(i == st)
			continue;
		arr[i]->color = 0;
		arr[i]->dist = INT_MAX;
		arr[i]->parent = NULL;	
	}
	arr[st]->color = 1;
	arr[st]->dist = 0;
	arr[st]->parent = NULL;
	rear=-1;
	front=-1;
	enqueue(q, st);
	while(front != rear)
	{
		r = dequeue(q);
		head = adj[r]->next;
		while(head)
		{
			p = head->key;
			if(arr[p]->color == 0)
			{
				arr[p]->color = 1;
				arr[p]->dist = arr[r]->dist + 1;
				arr[p]->parent = arr[r];
				enqueue(q, p);
			}
			head = head->next;
		}
		arr[r]->color = 2;
		printf("%d ", r);
		if(r == end)
			break;
	}
	return;
}

void dfs(struct List *adj[], int st, int end)
{
	for(i=0; i<n; i++)
	{
		if(i == st)
			continue;
		arr1[i]->color1 = 0;
		arr1[i]->parent1 = NULL;	
	}
	arr1[st]->color1 = 1;
	arr1[st]->parent1 = NULL;
	z=-1;
	push(q, st);
	while(z!=-1)
	{
		r = pop(q);
		head = adj[r]->next;
		while(head)
		{
			p = head->key;
			if(arr1[p]->color1 == 0)
			{
				arr1[p]->color1 = 1;
				arr1[p]->parent1 = arr1[r];
				push(q, p);
			}
			head = head->next;
		}
		arr1[r]->color1 = 2;
		printf("%d ", r);
		if(r == end)
			break;
	}
	return;
}
int main()
{
	char ch;
	char str[10];
	int total=0, flag=0, st, end;
	ch = getchar();
	while(ch !='\n')
	{
		total = total*10 + (int)ch - 48;
		ch = getchar();
	}
	n = total;
	for(i=0; i<n; i++)
	{
		adj[i] = (struct List *)malloc(sizeof(struct List));
		adj[i]->key = i;
		adj[i]->next = NULL;	
	}
	for(i=0; i<n; i++)
	{
		arr[i] = (struct Node *)malloc(sizeof(struct Node));
		arr[i]->parent = NULL;
		arr1[i] = (struct Node1 *)malloc(sizeof(struct Node1));
		arr1[i]->parent1 = NULL;	
	}
	j=0;
	ch = getchar();
	while(j<n)
	{	
		if(j!=0)
			ch = getchar();
		while(ch!='\n')
		{
			while(isdigit(ch))
			{
				total = 0;
				while(ch != ' ' && ch !='\n')
				{
					total = total*10 + (int)ch - 48;
					ch = getchar();
				}
				if(ch == '\n')
				{
					head = adj[j];
					while(head->next != NULL)
						head = head->next;
					struct List *temp = (struct List *)malloc(sizeof(struct List));
					temp->key = total;
					temp->next = NULL;
					head->next = temp;
					flag = 1;	
					break;
				}	
				else
				{
					head = adj[j];
					while(head->next != NULL)
						head = head->next;
					struct List *temp = (struct List *)malloc(sizeof(struct List));
					temp->key = total;
					temp->next = NULL;
					head->next = temp;
					ch = getchar();
				}	
			}
		}
		if(flag == 1)
		{
			flag = 0;
		}	
		j++;
	}
	/*for(i=0; i<n; i++)
	{
		head = adj[i]->next;
		while(head)
		{
			printf("%d ", head->key);
			head = head->next;
		}
		printf("\n");
	}*/
	scanf("%s", str);
	while(strcmp(str, "stp") != 0)
	{
		if(strcmp(str, "bfs")==0)
		{
			scanf("%d %d", &st, &end);
			bfs(adj, st, end);
			printf("\n");
		}
		else if(strcmp(str, "dfs")==0)
		{
			scanf("%d %d", &st, &end);
			dfs(adj, st, end);
			printf("\n");
		}
		scanf("%s", str);
	}
	return 0;
}
