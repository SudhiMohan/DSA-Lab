#include<stdio.h>
#include<stdlib.h>
struct Node
{
	int data;
	struct Node* next;
};
void append(struct Node** headref, int new_data)
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
void print(struct Node *head)
{
	while(head!=NULL)
	{
		printf("%d ", head->data);
		head = head->next;
	}
	return;
}
void reverse(struct Node** headref)
{
	struct Node* prev = NULL;
	struct Node *current, *next;
	current = *headref;
	while(current!=NULL)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	*headref = prev;
}
int main()
{
	struct Node *head = NULL;
	int num, c;
	scanf("%d", &num);
	while(getchar()!='\n')
	{
		append(&head, num);
		scanf("%d", &num);
	}
	append(&head, num);
	reverse(&head);
	print(head);
	return 0;
}
