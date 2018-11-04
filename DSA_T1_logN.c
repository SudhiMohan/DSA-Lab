#include<stdio.h>
#include<stdlib.h>
int num=0, a[100][100];
void count(int a[][100], int low1, int high1, int low2, int high2)
{
	if(low1<=high1 && low2<=high2)
	{	
		int mid1 = low1+ (high1-low1)/2;
		int mid2 = low2 + (high2-low2)/2;
		printf("%d %d\n", mid1+1, mid2+1);
		if(a[mid1][mid2]==0)
		{
			count(a, mid1+1, high1, mid2+1, high2);
			count(a, low1, mid1, mid2+1, high2);
			count(a, mid1+1, high1, low2, mid2); 
		}
		else
		{
			num = num + (high1-mid1+1)*(high2-mid2+1);
			count(a, low1, mid1-1, low2, mid2-1);
			count(a, low1, mid1-1, mid2, high2);
			count(a, mid1, high1, low2, mid2-1);
		}	
	}
	return;	
}
int main()
{	
	int p,q,i,j;
	scanf("%d %d", &p, &q);
	for(i=0;i<p;i++)
	{
		for(j=0;j<q;j++)
		{
			scanf("%d", &a[i][j]);
		}
	}
	count(a, 0, p-1, 0, q-1);
	printf("%d\n", num);	
	return 0;
}	
