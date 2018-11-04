#include<stdio.h>
#include<stdlib.h>
int main()
{
	int m, n, i, j, val, count;
	int **arr;
	scanf("%d %d", &m, &n);
	arr = (int **)malloc(m*sizeof(int *));
	for(i=0;i<m;i++)
		arr[i] = (int *)malloc(n*sizeof(int));
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d", &arr[i][j]);
		}
	}
	scanf("%d", &val);
	i=0;
	j=n-1;
	count=0;
	while(i<m && j>=0)
	{
		if(val==arr[i][j])
		{
			count++;
			break;
		}
		else if(val>arr[i][j])
		{
			i++;
		}
		else
			j--;
	}
	if(count==0)
		printf("-1\n");
	else
		printf("1\n");		
	return 0;
}

