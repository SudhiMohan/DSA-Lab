#include<stdio.h>
#include<stdlib.h>
struct Node
{
	int data;
	struct Node *next;
};

void enqueue(struct Node** headref, int new_data)
{
	struct Node* new_node = malloc(sizeof(struct Node));
	new_node->data = new_data;
	new_node->next = NULL;
	struct Node *last = *headref;
	if(last==NULL)
	{
		*headref = new_node;
		return;
	}
	while(last->next!=NULL)
	{
		last = last->next; 
	}
	last->next = new_node;
	return;
}

int dequeue(struct Node** headref)
{
	int res;
	struct Node *temp = *headref;
	if(temp==NULL)
	{	
		res = -1;
		return res;
	}	
	res = temp->data;
	temp = temp->next;
	*headref = temp;
	return res;
}
void print_queue(struct Node** headref)
{
	struct Node *temp = *headref;
	struct Node *temp1 = *headref;
	if(temp==NULL)
	{
		printf("-1");
	}	
	while(temp!=NULL)
	{
		printf("%d ", temp->data);
		temp = temp->next;
	}
	*headref = temp1;
}
int main()
{
	struct Node *head = NULL;
	int num, num2;
	char ch;
	label:ch = getchar();
	switch(ch)
	{
		case 'e' : scanf("%d", &num);
			enqueue(&head, num);			
			break;
			 
		case 'd' : num2 = dequeue(&head);
			printf("%d\n", num2);
			break;		
		case 'p' : print_queue(&head);
			printf("\n");
			break;		 	
	}
	if(ch!='s')
		goto label;
	return 0;
}
