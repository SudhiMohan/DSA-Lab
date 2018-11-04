#include<stdio.h>
#include<stdlib.h>
int borrow=0, flag=0;
struct Node
{
	int data;
	struct Node *next;
};

struct Node *templ;

void push(struct Node** headref, int new_data)
{
	struct Node *new_node = malloc(sizeof(struct Node));
	new_node->data = new_data;
	new_node->next = *headref;
	*headref = new_node;
	return;
}
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
		if(head->data==0 && flag==0)
		{
			head = head->next;
		}
		else
		{
			printf("%d", head->data);
			head = head->next;
			flag=1;
		}	
	}
	if(flag==0)
		printf("0");
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
void difference_of_digits(struct Node* max, struct Node* min)
{	
	int num1, num2;
	if(max!=NULL)
	{
		num1 = max->data;
		num2 = min->data;
		if(borrow==1)
		{
			num1--;
			borrow=0;
		}
		num1 = num1-num2;
		if(num1<0)
		{		
			num1 = num1+10;
			borrow=1;
		}
		max->data = num1;
		min->data = num2;
		difference_of_digits(max->next, min->next);
	}
	else
	{
		return;
	}	
}
int main()
{
	struct Node *head1 = NULL;
	struct Node *head2 = NULL;
	struct Node *max, *min;
	int num1, num2;
	char c;
	c = getchar();
	while(c!=' ' && c!='\n')
	{
		append(&head1, (int)c-48);
		c = getchar();
	}
	c = getchar();
	while(c!=' ' && c!='\n')
	{
		append(&head2, (int)c-48);
		c = getchar();
	}
	struct Node *temp1 = head1;
	struct Node *temp2 = head2;
	max = head1;
	min = head2;
	while(head1!=NULL)
	{
		num1 = head1->data;
		num2 = head2->data;
		if(num1>num2)
		{
			max = temp1;
			min = temp2;
			break;
		}
		else if(num2>num1)
		{
			max = temp2;
			min = temp1;
			break;
		}
		head1 = head1->next;
		head2 = head2->next;
	}
	head1 = max;
	head2 = min;
	reverse(&head1);
	reverse(&head2);
	difference_of_digits(head1, head2);
	reverse(&head1);		
	print(head1);
	return 0;
}
