#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

struct List
{
	int key;
	struct List *next;	
};

struct Node
{
	int rank;
	int key;
	struct Node *parent;
}*temp=NULL;

struct Node *arr1[1000];

int x, y;
long long int minwt=0;

void makeset(int x)
{
	if(arr1[x]==NULL)
	{
		arr1[x] = (struct Node *)malloc(sizeof(struct Node));
		arr1[x]->key = x;
		arr1[x]->parent = arr1[x];
		arr1[x]->rank = 0;
	}	
	else
	{	
		printf("PRESENT\n");
	}
	return;	 
}
struct Node *find(int x)
{	
	int h = x;
	if(arr1[h] == NULL)
	{
		return NULL;
	}
	if(arr1[h] == arr1[h]->parent)
	{
		return arr1[h];
	}
	else
		find((arr1[h]->parent)->key);	
}
struct Node *link(struct Node *x, struct Node *y)
{
	if(y->rank > x->rank)
	{
		x->parent = y;
		return y;
	}
	else
	{
		y->parent = x;
		if(x->rank == y->rank)
			x->rank = x->rank + 1;
		return x;	
	}
}

struct Node *unite(int x, int y)
{
	struct Node *m = find(x);
	struct Node *n = find(y);
	if(m == NULL || n == NULL)
	{
		return NULL;
	}
	else
	{
		temp = NULL;
		temp = link(m, n);
		return temp;
	}
}

struct Weight
{
	int u;
	int v;
	int w;
};

struct List *head = NULL;

int i, j, n, k, u, v, count, val, p, temp1, temp2, temp3;

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
	struct List *adj[n];
	struct Node1 *arr1[n];
	struct Weight wt[1000];
	for(i=0; i<n; i++)
	{
		adj[i] = (struct List *)malloc(sizeof(struct List));
		adj[i]->key = i;
		adj[i]->next = NULL; 	
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
	k=0;
	j=0;
	while(k<n)
	{
		head = adj[k];
		u = head->key;
		count = 0;
		head = head->next;
		while(head)
		{
			count++;
			head = head->next;
		}
		head = adj[k]->next;
		for(i=0; i<count; i++)
		{
			scanf("%d", &val);
			v = head->key;
			wt[j].u = u;
			wt[j].v = v;
			wt[j].w = val;
			j++;
			head = head->next;
		}
		k++;
	}
	count = j;
	for(i=0; i<j; i++)
	{
		for(p=i+1;p<j;p++)
		{
			if(wt[i].w > wt[p].w)
			{
				temp1 = wt[i].u;
				temp2 = wt[i].v;
				temp3 = wt[i].w;
				wt[i].u = wt[p].u;
				wt[i].v = wt[p].v;
				wt[i].w = wt[p].w;
				wt[p].u = temp1;
				wt[p].v = temp2;
				wt[p].w = temp3;
			}
		}
	}
	for(x=0; x<n; x++)
	{
		makeset(x);
	}
	for(i=0; i<count; i++)
	{
		u = wt[i].u;
		v = wt[i].v;
		val = wt[i].w;
		if(find(u) != find(v))
		{
			minwt = minwt + val;
			unite(u,v);
		}
	}
	printf("%lld\n", minwt);
	return 0;
}
