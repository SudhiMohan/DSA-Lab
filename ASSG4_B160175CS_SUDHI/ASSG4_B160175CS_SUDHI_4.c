#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int key;
	struct Node *left;
	struct Node *right;
};
int i, j, k=0;
struct Node *createNode(int key)
{
	struct Node *temp1 = malloc(sizeof(struct Node));
	temp1->key = key;
	temp1->left = NULL;
	temp1->right = NULL;
	return temp1;
}
int findIn(int inor[], int st, int end, int key)
{
	int t;
	for(t=st; t<=end; t++)
	{
		if(inor[t] == key)
			return t;
	}
}
struct Node *createTree(int prer[], int inor[], int st, int end)
{
	if(st > end)
		return NULL;
	struct Node *tNode = createNode(prer[k]);
	k++;
	if(st == end)
	{
		return tNode;
	}
	else
	{
		tNode->left = createTree(prer, inor, st, findIn(inor, st, end, tNode->key)-1);
		tNode->right = createTree(prer, inor, findIn(inor, st, end, tNode->key)+1, end);
		return tNode;
	}		
}
void printTree(struct Node *root)
{
	printf("( ");
	if(root!=NULL)
	{
		printf("%d ", root->key);
		printTree(root->left);
		printTree(root->right);
	}
	printf(") ");
}
int main()
{
	struct Node *root = NULL;
	int m;
	scanf("%d", &m);
	int prer[m], inor[m];
	for(i=0; i<m; i++)
	{
		scanf("%d", &prer[i]);
	}
	for(i=0; i<m; i++)
	{
		scanf("%d", &inor[i]);
	}
	root = createTree(prer, inor, 0, m-1);	
	printTree(root);
	return 0;
}
