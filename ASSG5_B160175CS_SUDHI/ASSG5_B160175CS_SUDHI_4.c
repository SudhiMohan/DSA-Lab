#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
//infinity is taken as 10000
struct edge
{
	int u,v,wt;
}edge_array[10000];
int d[10000];
int n,m;
void initialise_single_source();
void relax(int j);
int checknegcycle();

void initialise_single_source()
{
	for(int i=0;i<n;i++)
		d[i]=10000;
	d[0]=0;
}

void relax(int j)
{
	if(d[edge_array[j].v] > d[edge_array[j].u]+edge_array[j].wt)
		d[edge_array[j].v]=d[edge_array[j].u]+edge_array[j].wt;
		
}

int checknegcycle()
{
	initialise_single_source();
	int i,j;
	for(i=0;i<n-1;i++)
		for(j=0;j<m;j++)
			relax(j);
			
	for(j=0;j<m;j++)
		if(d[edge_array[j].v] > d[edge_array[j].u]+edge_array[j].wt)
			return 1;	
	return -1;
}

int main()
{
	scanf("%d",&n);
	scanf("%d",&m);

	int i,x,y,w;
	for(i=0;i<m;i++)
	{	scanf("%d",&x);
		scanf("%d",&y);
		scanf("%d",&w);
		
		edge_array[i].u=x;
		edge_array[i].v=y;
		edge_array[i].wt=w;
	}

	printf("%d\n",checknegcycle());
	return 0;
}
