#include<stdlib.h>
#include<ctype.h>
#include<stdio.h>
#include<limits.h>
long int idiv(long int a,long int b);
void merge(long int *a, long int low, long int mid1, long int mid2, long int high);
void mergesort(long int *a,long int low,long int high);

int main()
{
	FILE *fptr1, *fptr2;
	fptr1 = fopen("in","rb");
	fptr2 = fopen("out","wb");
	if(!fptr1)
	{
		 printf("Could not open file.\n");
		 return 0;
	}

	long int i=0,n,k;
        long int *a=malloc(sizeof(long int));
        
	
	while(fscanf(fptr1,"%ld",&k)!=EOF)
   	{        
            a=realloc(a,(i+1)*sizeof(long int));
            a[i]=k;
            i++;
        }

	n=i;
      	mergesort(a,0,n-1);

        for(i=0;i<n;i++)
	fprintf(fptr2,"%ld ",a[i]);
	return 0;
}

void merge(long int *a,long int low,long int mid1,long int mid2,long int high)
{   

   long int j,i,k,L[100]={0},M[100]={0},N[100]={0};

    for(i=0,j=low;j<=mid1;i++,j++)
         L[i]=a[j];          
         L[i]=LONG_MAX;
   
    
    for(j=mid1+1,i=0;j<=mid2;i++,j++)
         M[i]=a[j];
         M[i]=LONG_MAX;
   

    
    for(i=0,j=mid2+1;j<=high;i++,j++)
         N[i]=a[j];
         N[i]=LONG_MAX;

	i=0;j=0,k=0;
	long int x=low;
	while(x<=high)
	{
     		if(M[i]<=N[j ]&& M[i]<=L[k])
             {    
                  a[x]=M[i];
                    i++;
             }
      
     else if(M[i]>=N[j] && N[j]<=L[k])
             {   
                  a[x]=N[j];
                    j++;
             }  

     else if(M[i]>=L[k] && N[j]>=L[k])
             {    
                  a[x]=L[k];
                    k++;
             }     

	x++;
	}
}


void mergesort(long int *a,long int low,long int high)
{
	long int mid1, mid2;  
 	if(low<high)
  	{      
                                   
          mid1=low+idiv(high-low+1,3)-1;
          mid2=high-idiv(high-low+1,3);
          
          
          mergesort(a,low,mid1);
                                                     
          mergesort(a,mid1+1,mid2);
                      
          mergesort(a,mid2+1,high);
                              
	  merge(a,low,mid1,mid2,high);


	  } 
        
}


long int idiv(long int a,long int b)
{

  if(a%b==0)
      return a/b;
 else 
     return (a/b)+1;
}
