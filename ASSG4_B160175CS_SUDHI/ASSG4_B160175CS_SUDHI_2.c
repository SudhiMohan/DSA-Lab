#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Node
{
	int key;
	struct Node *parent;
	struct Node *left;
	struct Node *right;
}*min, *max, *pred, *succ, *res, *temp1, *y, *a;
struct Node *troot = NULL;
struct Node *createNode(int x)
{
	struct Node *temp = malloc(sizeof(struct Node));
	temp->key = x;
	temp->left = NULL;
	temp->right = NULL;
	temp->parent = NULL;
	return temp;
}
void insert(int x)
{
	if(troot == NULL)
	{
		troot = createNode(x);
		return;
	}
	struct Node *root = troot;
	struct Node *prev = NULL;
	while(root!=NULL)
	{
		prev = root;
		if(root->key > x)
			root = root->left;
		else
			root = root->right;
	}
	root = createNode(x);
	root->parent = prev;
	if(prev->key > x)
		prev->left = root;
	else
		prev->right = root;
}
struct Node *search(struct Node *root, int x)
{
	if(root == NULL || root->key == x)
	{
		return root;
	}
	else if(root->key > x)
	{
		return search(root->left, x);
	}	
	else
	{
		return search(root->right, x);
	}
}
struct Node *findMin(struct Node *root)
{
	if(root == NULL)
	{
		return root;
	}
	else if(root->left == NULL)
	{
		return root;
	}
	else
	{
		findMin(root->left);
	}
}
struct Node *findMax(struct Node *root)
{
	if(root == NULL)
	{
		return root;
	}
	else if(root->right == NULL)
	{
		return root;
	}
	else
	{
		findMax(root->right);
	}
}
struct Node *predecessor(struct Node *root, int x)
{
	if(root == NULL)
	{
		return root;
	}
	min = findMin(root);
	a = NULL;
	a = search(root, x);
	if(a!=NULL)
	{
		if(min->key == x)
		{
			return root;
		}
		else
		{
			if(a->left)
			{
				return findMax(a->left);
			}
			else
			{
				y = NULL;
				y = a->parent;
				while(y!= NULL && a == y->left)
				{
					a = y;
					y = y->parent;
				}
				return y;
			}
		}
	}
	else
	{
		return a;
	}
}
struct Node *successor(struct Node *root, int x)
{
	if(root == NULL)
	{
		return root;
	}
		max = findMax(root);
		a = NULL;
		a = search(root, x);
		if(a!=NULL)
		{
			if(max->key == x)
			{
				return root;
			}
			else
			{
				if(a->right)
				{
					return findMin(a->right);
				}
				else
				{
					y = NULL;
					y = a->parent;
					while(y!=NULL && a == y->right)
					{
						a = y;
						y = y->parent;
					}
					return y;
				}
			}
		}
		else
		{
			return a;
		}	
}
void transplant(struct Node *u, struct Node *v)
{
	if(u->parent == NULL)
		troot = v;
	else if(u->parent->left == u)
		u->parent->left = v;
	else
		u->parent->right = v;
	if(v!=NULL)
		v->parent = u->parent;
}

void delete(struct Node *root)
{
	struct Node *y;
	if(root->left == NULL)
		transplant(root, root->right);
	else if(root->right == NULL)
		transplant(root, root->left);
	else
	{
		y = findMin(root->right);
		if(y->parent != root)
		{
			transplant(y,y->right);
			y->right = root->right;
			y->right->parent = y;
		}
		transplant(root, y);
		y->left = root->left;
		y->left->parent = y;
	}
}
void inorder(struct Node *root)
{
	if(root)
	{
		inorder(root->left);
		printf("%d ", root->key);
		inorder(root->right);
	}
}
void preorder(struct Node *root)
{
	if(root)
	{
		printf("%d ", root->key);
		preorder(root->left);
		preorder(root->right);
	}
}
void postorder(struct Node *root)
{
	if(root)
	{
		postorder(root->left);
		postorder(root->right);
		printf("%d ", root->key);
	}
}
char str[10];
int x;
int main()
{
	label: scanf("%s", str);
	if(strcmp(str, "stop") == 0)
		return 0;
	else if(strcmp(str, "insr") == 0)
	{
		scanf("%d", &x);
		insert(x);
	}
	else if(strcmp(str, "srch") == 0)
	{
		scanf("%d", &x);
		temp1 = search(troot, x);
		if(temp1)
		{
			printf("FOUND\n");
		}
		else
		{
			printf("NOT FOUND\n");
		}
	}
	else if(strcmp(str, "minm") == 0)
	{
		min = findMin(troot);
		if(min == NULL)
		{
			printf("NIL\n");
		}
		else
		{
			printf("%d\n", min->key);
		}
	}
	else if(strcmp(str, "maxm") == 0)
	{
		max = findMax(troot);
		if(max == NULL)
		{
			printf("NIL\n");
		}
		else
		{
			printf("%d\n", max->key);
		}
	}
	else if(strcmp(str, "pred") == 0)
	{
		scanf("%d", &x);
		pred = predecessor(troot, x);
		min = findMin(troot);
		if(pred == NULL)
		{
			printf("NOT FOUND\n");
		}
		else if(min->key == x)
		{
			printf("NIL\n");
		}
		else
		{
			printf("%d\n", pred->key);
		}
	}
	else if(strcmp(str, "succ") == 0)
	{
		scanf("%d", &x);
		succ = successor(troot, x);
		max = findMax(troot);
		if(succ == NULL)
		{
			printf("NOT FOUND\n");
		}
		else if(max->key == x)
		{
			printf("NIL\n");
		}
		else
		{
			printf("%d\n", succ->key);
		}
	}
	else if(strcmp(str, "delt") == 0)
	{
		scanf("%d", &x);
		struct Node *temp = search(troot, x);
		delete(temp);
	}
	else if(strcmp(str, "inor") == 0)
	{
		inorder(troot);
		printf("\n");
	}
	else if(strcmp(str, "prer") == 0)
	{
		preorder(troot);
		printf("\n");
	}
	else if(strcmp(str, "post") == 0)
	{
		postorder(troot);
		printf("\n");
	}
		goto label;
}
