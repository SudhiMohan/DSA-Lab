#include<stdio.h>
#include<stdlib.h>
int circularsortedsearch(int *arr, int low, int high, int x)
{
	int mid;
	if(low<=high)
	{
		mid = (low+high)/2;
		if(x==arr[mid])
			return mid;
		else if(arr[mid]<=arr[high])
		{
			if(x>arr[mid] && x<=arr[high])
				return circularsortedsearch(arr, mid+1, high, x);
			else
				return circularsortedsearch(arr, low, mid-1, x);	
		}	
		else if(arr[low]<=arr[mid])
		{
			if(x<arr[mid] && x>=arr[low])
				return circularsortedsearch(arr, low, mid-1, x);
			else
				return circularsortedsearch(arr, mid+1, high, x);
		}		
	}
	else
		return -1;
}
int main()
{
	int n, i, val, found, *arr;
	scanf("%d", &n);
	arr = (int *)malloc(n*sizeof(int));
	for(i=0;i<n;i++)
	{
		scanf("%d",(arr+i)); 
	}
	scanf("%d", &val);
	found = circularsortedsearch(arr, 0, n-1, val);
	printf("%d\n", found);			
	return 0;
}

