#include<stdio.h>
#include<stdlib.h>
void swap(int *a, int *b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}
void heapify(int* arr, int n, int i)
{
	int largest = i;
	int l = (2*i)+1;
	int r = (2*i)+2;
	if(l<n && (*(arr+l) > *(arr+largest)))
		largest = l;
	if(r<n && (*(arr+r) > *(arr+largest)))
		largest = r;
	if(largest !=i)
	{
		swap((arr+i), (arr+largest));
		heapify(arr, n, largest);
	}
	return;		
}
void kthlargest(int *arr, int n, int k)
{
	int i;
	for(i = (n/2)-1; i>=0; i--)
	{
		heapify(arr, n, i);
	}	
	for(i=n-1;i>=n-k;i--)
	{
		swap(arr, (arr+i));	
		heapify(arr, i, 0);	
	}
}
int main()
{
	int *arr;
	int n, i, k;
	scanf("%d", &n);
	arr = (int *)malloc(n*sizeof(int));
	for(i=0;i<n;i++)
	{
		scanf("%d", (arr+i));
	}
	scanf("%d", &k);
	if(k==0 || k>n)
	{
		printf("Invalid number. Enter a valid number next time.\n");
		return 0;
	}
	kthlargest(arr, n, k);
	printf("%d", *(arr+n-k));	
	return 0;
}
