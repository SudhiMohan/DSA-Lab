#include<stdio.h>
#include<stdlib.h>

char type, ch;
int m, x, r, h1, h2, h, i, j, count, ele, *table1;
struct Node
{
	int key;
	struct Node* next;
}*head, *table;

void hashTable(int m)
{
	if(type == 'd')
	{
		table = malloc(m*sizeof(struct Node));
		for(i=0; i<m; i++)
		{
			table[i].key = -1;
			table[i].next = NULL;
		}
	}
	else
	{
		table1 = malloc(m*sizeof(int));
		for(i=0; i<m; i++)
		{
			table1[i] = -1;
		}
	}	
}
int hash1(int k)
{
	return k%m;
}
int calcR(int m)
{
	for(i = m-1; i>=1; i--)
	{
		count = 0;
		for(j = 2; j<i; j++)
		{
			if(i%j == 0)
				count++;
		}
		if(count==0)
			return i;
	}
}
int hash2(int k)
{
	r = calcR(m);
	return (r - (k%r));
}
void insert(int k)
{
	if(type != 'd')
	{
		if(type == 'a')
		{	
			i=0;
			h1 = hash1(k);
			h = (h1 + i)%m;
			ele = table1[h];
			while(ele!=-1 && ele!=-2 && i<m)
			{
				i++;
				h = (h1 + i)%m;
				ele = table1[h];	
			}
			table1[h] = k;
			return;
		}
		else if(type == 'b')
		{	
			i=0;
			h1 = hash1(k);
			h = (h1 + (i*i))%m;
			ele = table1[h];
			while(ele!=-1 && ele!=-2 && i<m)
			{
				i++;
				h = (h1 + (i*i))%m;
				ele = table1[h];
					
			}
			table1[h] = k;
			return;
		}
		else if(type == 'c')
		{	
			h1 = hash1(k);
			h2 = hash2(k);
			i=0;
			h = (h1 + (i*h2))%m;
			ele = table1[h];
			while(ele!=-1 && ele!=-2 && i<m)
			{
				i++;
				h = (h1 + (i*h2))%m;
				ele = table1[h];	
			}
			table1[h] = k;
			return;
		}
		
	}
	else
	{
		h = hash1(k);
		head = &table[h];
		if(head->key==-1)
		{
			head->key = k;
			return;
		}
		else
		{
			while(head->next!=NULL)
			{
				head = head->next;
			}
			struct Node *new_node = malloc(sizeof(struct Node));
			new_node->key = k;
			new_node->next = NULL;
			head->next = new_node;
		}
	}	
	return;
}
void search(int k)
{
	if(type != 'd')
	{
		if(type == 'a')
		{
			i=0;
			h1 = hash1(k);
			h = (h1 + i)%m;
			while(table1[h]!=k && i<m)
			{
				if(table1[h]==-1)
				{
					printf("-1\n");
					return;
				}	
				else
				{
					i++;
					h = (h1 + i)%m;
				}		
			}
			if(i<m)
				printf("1\n");
			else
			{
				printf("-1\n");
			}	
		}
		else if(type == 'b')
		{
			i=0;
			h1 = hash1(k);
			h = (h1 + (i*i))%m;
			while(table1[h]!=k && i<m)
			{
				if(table1[h]==-1)
				{
					printf("-1\n");
					return;
				}	
				else
				{
					i++;
					h = (h1 + (i*i))%m;
				}		
			}
			if(i<m)
				printf("1\n");
			else
			{
				printf("-1\n");
			}	
		}
		else if(type == 'c')
		{
			h1 = hash1(k);
			h2 = hash2(k);
			i=0;
			h = (h1 + (i*h2))%m;
			while(table1[h]!=k && i<m)
			{
				if(table1[h]==-1)
				{
					printf("-1\n");
					return;
				}	
				else
				{
					i++;
					h = (h1 + (i*h2))%m;
				}		
			}
			if(i<m)
				printf("1\n");
			else
			{
				printf("-1\n");
			}	
		} 
	}
	else
	{
		h = hash1(k);
		head = &table[h];
		if(head->key==-1)
		{
			printf("-1\n");
			return;
		}
		else
		{
			while(head!=NULL)
			{
				if(head->key!=k)
				{
					head = head->next;
				}
				else
					break;
			}
			if(head!=NULL)
				printf("1\n");
			else
				printf("-1\n");	
		}
	}
	return;
	
}
void delete(int k)
{
	if(type != 'd')
	{
		if(type == 'a')
		{
			i=0;
			h1 = hash1(k);
			h = (h1 + i)%m;
			while(table1[h]!=k)
			{
				i++;
				h = (h1 + i)%m;
			}
			table1[h] = -2;
			return;
		}
		else if(type == 'b')
		{
			i=0;
			h1 = hash1(k);
			h = (h1 + (i*i))%m;
			while(table1[h]!=k)
			{
				i++;
				h = (h1 + (i*i))%m;
			}
			table1[h] = -2;
			return;
		}
		else if(type == 'c')
		{
			h1 = hash1(k);
			h2 = hash2(k);
			i=0;
			h = (h1 + (i*h2))%m;
			while(table1[h]!=k)
			{
				i++;
				h = (h1 + (i*h2))%m;
			}
			table1[h] = -2;
			return;
		}
	}
	else
	{
		h = hash1(k);
		head = &table[h];
		struct Node *prev = NULL;
		while(head!= NULL && head->key!=k)
		{
			prev = head;
			head = head->next;
		}
		if(prev == NULL)
		{
			if(head->next==NULL)
			{
				table[h].key = -1;
			}
			else
			{
				struct Node *temp = head->next;
				head = head->next;
				table[h].key = head->key;
				table[h].next = head->next;
				free(temp);
			}	
		}
		else
		{
			struct Node *temp = head;
			prev->next = head->next;
			free(temp);
		}	
	}
	return;			
}
void print()
{
	if(type !='d')
	{
		for(i=0;i<m;i++)
		{
			if(table1[i]==-1 || table1[i]==-2)
			{
				printf("%d ()\n", i);
			}
			else
			{
				printf("%d (%d)\n", i, table1[i]);
			}
		}
	}
	else
	{
		for(i=0;i<m;i++)
		{
			head = &table[i];
			if(head->key == -1)
			{
				printf("%d ()\n", i);
			}
			else
			{
				printf("%d (", i);
				while(head!=NULL)
				{
					printf("%d", head->key);
					if(head->next!=NULL)
					{
						printf(" ");
					}
					else
						break;
					head = head->next;		
				}
				printf(")\n");
			}	
		}
	}	
}
int main()
{
	type = getchar();
	scanf("%d", &m);
	hashTable(m);
	r = calcR(m);
	label: ch = getchar();
	switch(ch)
	{
		case 'i': scanf("%d", &x);
			insert(x);
			break;
		case 's': scanf("%d", &x);
			search(x);
			break;
		case 'd': scanf("%d", &x);
			delete(x);
			break;
		case 'p':
			print();
			break;			
	}
	if(ch != 't')
		goto label;
	else	
	{	
		free(table1);
		free(table);
		return 0;
	}	
}
