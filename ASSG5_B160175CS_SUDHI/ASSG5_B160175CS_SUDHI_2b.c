#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<string.h>

int n,heapsize=-1,dest,distance[10000],vstd[10000],heap[10000],sum=0;
struct vertex
{
	int data,weight;
	struct vertex *next;
};

struct table{
    struct vertex *list;
}vertex_array[10000];

void min_heapify(int i);
int extract_min();
int parent(int x);
void prim();
void heap_insert(int i);

int parent(int x)
{
	if(x%2==0)
		return (x-2)/2;
	return (x-1)/2;
}

void min_heapify(int i)
{
	int l=2*i+1,r=2*i+2;
	int smallest;

	if(l<=heapsize && distance[heap[l]] < distance[heap[i]])
		smallest=l;
	else smallest=i;

	if(r<=heapsize && distance[heap[r]] < distance[heap[smallest]] )
		smallest=r;

	if(smallest!=i)
	{
		int temp=heap[smallest];
		heap[smallest]=heap[i];
		heap[i]=temp;
		min_heapify(smallest);
	}


}



int extract_min()
{	int temp=heap[0];
	heap[0]=heap[heapsize];
	heapsize--;
	min_heapify(0);
	return temp;
}

void heap_insert(int i)
{
	heapsize++;
	heap[heapsize]=i;
	i=heapsize;
	while(i>0 && distance[heap[parent(i)]]>distance[heap[i]])
	{       int swap=heap[parent(i)];
	        heap[parent(i)]=heap[i];
	        heap[i]=swap;
	        i=parent(i);

	}
}



int main()
{
	int i,j;
	int y,z;
	int t,d;
	char x,c;
  	scanf("%d",&n);
  	scanf("%c",&c);
	for(i=0;i<n;i++)
 	{
     		vstd[i]=0;
 	}
	for(j=0;j<n;j++)
   	{
      		vertex_array[j].list=NULL;
      		while(1)
     		{
			scanf("%c",&c);
			if(c=='\n')break;
			else
			{
				y=c-'0';
			    	while(1)
			    	{
					scanf("%c",&x);
					if(x=='\n' || x==' ' )
						break;
					z=x-'0';
					y=y*10 +z;
			    	}
			}
			struct vertex *newnode=malloc(sizeof(struct vertex));
			newnode->data=y;
			newnode->weight=0;
			newnode->next=NULL;
			if(vertex_array[j].list==NULL)
			{
				vertex_array[j].list=newnode;
			}
			else
			{
				struct vertex *temp=vertex_array[j].list;
				while(temp->next!=NULL)
				temp=temp->next;
				temp->next=newnode;
			}
			if(x=='\n')
				break;
    		}
  	}
  
  for(j=0;j<n;j++)
   {
       struct vertex*temp=vertex_array[j].list;
      while(1)
     {
        scanf("%c",&c);
        if(c=='\n')break;
        else
        {
            y=c-'0';
            while(1)
            {
                scanf("%c",&x);
                if(x=='\n' || x==' ' ) break;
                z=x-'0';
                y=y*10 +z;
                
            }
        }
        temp->weight=y;
        temp=temp->next;
        if(x=='\n') break;
        
    }
  }
	prim();  
	sum=0;
	for(i=0;i<n;i++)
		sum+=distance[i];
	printf("%d\n",sum);
  return 0;
}


void prim()
{
	int i;
	for(i=0;i<n;i++)
	{
		distance[i]=INT_MAX;
		vstd[i]=0;	
	}

	distance[0]=0;

	heap_insert(0);

	while(heapsize!=-1)
	{
		int u=extract_min();

		vstd[u]=1;
		struct vertex *ptr=vertex_array[u].list;
		//relax(ptr,u);
		while(ptr!=NULL)
		{

			if(vstd[ptr->data]==0)
			 {      int t=ptr->weight;
				if(t < distance[ptr->data])
            				{distance[ptr->data]=t;
						//sum+=distance[ptr->data];
					}
             			heap_insert(ptr->data);

         		 }	
		
			ptr=ptr->next;	
		}

	
	}

}
