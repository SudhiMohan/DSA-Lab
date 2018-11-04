#include<stdio.h>
#include<stdlib.h>
struct Node
{
	int rank;
	int key;
	struct Node *parent;
}*temp=NULL, *temp1=NULL, *temp2=NULL, *temp3=NULL, *temp4=NULL;

struct Node *arr1[100], *arr2[100], *arr3[100], *arr4[100];
int x, y, i, k;
int c1 = 0, c2 = 0, c3 = 0, c4 = 0;

void makeset(int x)
{
	if(arr1[x]==NULL)
	{
		arr1[x] = (struct Node *)malloc(sizeof(struct Node));
		arr1[x]->key = x;
		arr1[x]->parent = arr1[x];
		arr1[x]->rank = 0;
		
		arr2[x] = (struct Node *)malloc(sizeof(struct Node));
		arr2[x]->key = x;
		arr2[x]->parent = arr2[x];
		arr2[x]->rank = 0;
		
		arr3[x] = (struct Node *)malloc(sizeof(struct Node));
		arr3[x]->key = x;
		arr3[x]->parent = arr3[x];
		arr3[x]->rank = 0;

		arr4[x] = (struct Node *)malloc(sizeof(struct Node));
		arr4[x]->key = x;
		arr4[x]->parent = arr4[x];
		arr4[x]->rank = 0;
		printf("%d\n", x);
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
struct Node *find1(int x)
{	
	int h = x;
	if(arr1[h] == NULL)
	{
		return NULL;
	}
	c1++;
	if(arr1[h] == arr1[h]->parent)
	{
		return arr1[h];
	}
	else
		find1((arr1[h]->parent)->key);	
}
struct Node *find2(int x)
{
	
	int h = x;
	if(arr2[h] == NULL)
	{
		return NULL;
	}
	c2++;
	if(arr2[h] == arr2[h]->parent)
	{
		return arr2[h];
	}
	else
		find2((arr2[h]->parent)->key);
}
struct Node *find3(int x)
{
	if(arr3[x] == NULL)
	{
		return NULL;
	}
	c3++;
	if(arr3[x] != arr3[x]->parent)
		arr3[x]->parent = find3((arr3[x]->parent)->key);
	return arr3[x]->parent;		
}
struct Node *find4(int x)
{
	if(arr4[x] == NULL)
	{
		return NULL;
	}
	c4++;
	if(arr4[x] != arr4[x]->parent)
	{
		arr4[x]->parent = find4((arr4[x]->parent)->key);
	}	
	return arr4[x]->parent;
}
struct Node *link1(struct Node *x, struct Node *y)
{
	y->parent = x;
	return x;
}
struct Node *link2(struct Node *x, struct Node *y)
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
struct Node *link3(struct Node *x, struct Node *y)
{
	y->parent = x;
	return x;
}
struct Node *link4(struct Node *x, struct Node *y)
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
struct Node *unite1(int x, int y)
{
	struct Node *m = find1(x);
	struct Node *n = find1(y);
	if(m == NULL || n == NULL)
	{
		return NULL;
	}
	else
	{
		temp1 = NULL;
		temp1 = link1(m, n);
		return temp1;
	}
}
struct Node *unite2(int x, int y)
{
	struct Node *m = find2(x);
	struct Node *n = find2(y);
	if(m == NULL || n == NULL)
	{
		return NULL;
	}
	else
	{temp2 = NULL;
	temp2 = link2(m, n);
	return temp2;
	}
}
struct Node *unite3(int x, int y)
{
	struct Node *m = find3(x);
	struct Node *n = find3(y);
	if(m == NULL || n == NULL)
	{
		return NULL;
	}
	else
	{
	temp3 = NULL;
	temp3 = link3(m, n);
	return temp3;
	}
}
struct Node *unite4(int x, int y)
{
	struct Node *m = find4(x);
	struct Node *n = find4(y);
	if(m == NULL || n == NULL)
	{
		return NULL;
	}
	else
	{
	temp4 = NULL;
	temp4 = link4(m, n);
	return temp4;
	}
}	
int main()
{
	k=0;
	while(k<100)
	{
		arr1[k] = NULL;
		arr2[k] = NULL;
		arr3[k] = NULL;
		arr4[k] = NULL;
		k++;
	}
	char ch;
	ch = getchar();
	while(ch!= 's')
	{
	switch(ch)
	{
		case 'm': scanf("%d", &x);
			makeset(x);
			break;
		case 'f': scanf("%d", &x);
			if(find(x) == NULL)
			{
				printf("NOT FOUND\n");
			}
			else
			{
				printf("%d %d %d %d\n", find1(x)->key, find2(x)->key, find3(x)->key, find4(x)->key);
			}
			break;
		case 'u': scanf("%d %d", &x, &y);
			if(find(x) == NULL || find(y) == NULL)
				printf("ERROR\n");
			else
			{
				printf("%d %d %d %d\n", unite1(x,y)->key, unite2(x,y)->key, unite3(x,y)->key, unite4(x,y)->key);
			}
			break;		
	}
		ch = getchar();
	}
	printf("%d %d %d %d\n", c1, c2, c3, c4);
	return 0;
}		
