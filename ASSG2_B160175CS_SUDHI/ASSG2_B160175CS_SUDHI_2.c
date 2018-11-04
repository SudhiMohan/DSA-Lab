#include<stdio.h>
#include<stdlib.h>
void quicksort(long int *a,long int low,long int high,long int ctr);
long int partition(long int *a,long int low,long int high);
long int median(long int *a,long int low,long int high,long int m);

int main()
{
	long int n,i,ctr=0;
	scanf("%ld",&n);
	long int a[n];

	for(i=0;i<n;i++)
        	scanf("%ld",&a[i]);

       
        quicksort(a,0,n-1,0);
        for(i=0;i<n;i++)
            printf("%ld ",a[i]);
        }

void quicksort(long int *a,long int low,long int high,long int ctr)
{
	long int q,m,n;
        n=high-low+1;
   	if(n%2==0)
             m=low+(n/2)-1;
        else 
           m=low+(n/2);

	if(low<high)
	{
		q=median(a,low,high,m);
                if(ctr<2)
                {
                	printf("%ld\n",a[q]);
                }
                quicksort(a,low,q-1,ctr+1);
               	quicksort(a,q+1,high,ctr+1);
                
	}
}

long int partition(long int *a,long int low,long int high)
{
	long int x=a[high];
        long int i=low-1,j,temp;
	
	for(j=low;j<=high-1;j++)
	{	if(a[j]<=x)
			{i++;
 			        temp=a[i];
				a[i]=a[j];
				a[j]=temp;
			}
         
         }
	temp=a[i+1];
	a[i+1]=a[j];
	a[j]=temp;

	return i+1;
}


long int median(long int *a,long int low,long int high,long int m)
{        long int pivot=partition(a,low,high);
	if(pivot==m)
            return m;
        if(pivot>m)
             median(a,low,pivot-1,m);
         else 
             median(a,pivot+1,high,m);

}
